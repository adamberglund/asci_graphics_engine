// ohol 
// ohol 2

// check invalid space interactions !!!!!

// Libraries            {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "obj_map.h"
#include "sprites.h"

// }

// Global Definitions {
#define MAPWIDTH     32
#define MAPHEIGHT    32
#define MAPLENGTH    MAPWIDTH * MAPHEIGHT
#define TILEWIDTH    8
#define TILEHEIGHT   4
#define TILELENGTH   TILEWIDTH * TILEHEIGHT
#define SCNTLEWIDTH  6
#define SCNTLEHEIGHT 6
#define SCNTLELENGTH SCNTLEWIDTH * SCNTLEHEIGHT
#define SCREENWIDTH  TILEWIDTH   * SCNTLEWIDTH
#define SCREENHEIGHT TILEHEIGHT  * SCNTLEHEIGHT
#define SCREENLENGTH SCREENWIDTH * SCREENHEIGHT

// Program Structures  {
struct player
{
    int position;
    int hunger;
    int hungertime;
    int age;
    int bdaytime;
    int hand;
    int back;
    int head;
    int body;
    int legs;
    int lfoot;
    int rfoot;
};

struct object
{
    int type;
    int num_sprites;
    int sprite_num;
    int sprite;
    int position;
    int clockid;
    int timeid;
    int timenum;
    int carryid;
    int playersolid;
    int sheepsolid;
    int plrcarry;
    int ret[5];
};

struct objcarry
{
    int carrymun;
    int carry1;
    int carry2;
    int carry3;
    int carry4;
    int carry5;
    int carry6;
};

struct clock
{
    int timeleft;
    int objid;
};

// global vars
int            map[MAPLENGTH];
char           screen[SCREENLENGTH];

char           sprites[NUMSPRITES][SPRITELENGTH];
struct player  players;
int            voidobjs[MAPLENGTH + 1];
struct object  objects[MAPLENGTH];
int            voidclocks[MAPLENGTH + 1];
struct clock   clocks[MAPLENGTH];

// function prototypes
void setvoids();
int  popvid();
void pushvclocks(int id);
int  popvclocks();
void pushvid(int id);
void setplayer();
void setmap();
void printmap();
void printscreen();
void setscreen();
void useraction();
void action(char in);
void objaction(char in, char der);
int  usermove(char in);
int  collisioncheck(int positionToCheck);
void setobj(int id, int type, int position);
void carrydo(int handid, int groundid, int position);
void replacedo(int handid, int groundid, int position);
void recepiedo(int handid, int groundid, int position);

// main
int main(){
    setvoids();
    setsprites(sprites);
    setplayer();
    setmap();

    while(1){
        printscreen();
        useraction();
        // clearscreen();
    }
    return 0;
}

void setvoids()
{
    int x;

    voidobjs[0]   = MAPLENGTH;
    voidclocks[0] = MAPLENGTH;

    for(x = 0; x < MAPLENGTH; x++)
    {
        voidobjs[x + 1]   = x;
        voidclocks[x + 1] = x;
    }
}

int popvid()
{
    voidobjs[0]--;
    return voidobjs[voidobjs[0] + 1];
}

void pushvclocks(int id)
{
    voidclocks[0]++;
    voidclocks[voidclocks[0]] = id;
}

int popvclocks()
{
    voidclocks[0]--;
    return voidclocks[voidclocks[0] + 1];
}

void pushvid(int id)
{
    voidobjs[0]++;
    voidobjs[voidobjs[0]] = id;
}

void setplayer()
{
    players.position = (MAPWIDTH / 2) + ((MAPHEIGHT / 2)
                        * MAPHEIGHT);
    players.hunger     = 10;
    players.age        = 10;
    players.bdaytime   = 60;
    players.hungertime = 10;
    players.hand       = 0;
    players.back       = 0;
    players.head       = 0;
    players.body       = 0;
    players.legs       = 0;
    players.lfoot      = 0;
    players.rfoot      = 0;
}

void setmap()
{
    int x, y;

    for(x = 0; x < MAPLENGTH; x++)
    {
        y = rand() % 40;

        switch(y)
        {
            case 0:
            case 1:
                map[x] = popvid();
                setobj(map[x], STONE, x);
                break;
            case 3:
                map[x] = popvid();
                setobj(map[x], BIG_STONE, x);
                break;
            case 4:
                map[x] = popvid();
                setobj(map[x], MAIPEL, x);
                break;
            case 5:
                map[x] = popvid();
                setobj(map[x], FLINT_ROCK, x);
                break;
            case 6:
                map[x] = popvid();
                setobj(map[x], YEW, x);
                break;
            case 7:
                map[x] = popvid();
                setobj(map[x], JUNIPER, x);
                break;
            case 8:
                map[x] = popvid();
                setobj(map[x], BENT, x);
                break;
            default:
                map[x] = SPACE;
                break;
        }

        // set out of map bounds wall
        // north
        if(x < MAPWIDTH * (SCNTLEWIDTH / 2))
            map[x] = OOBBARRIER;
        // south
        if(x > MAPLENGTH - (MAPWIDTH * (SCNTLEWIDTH / 2)))
            map[x] = OOBBARRIER;
        // west
        for(y = 0; y < (SCNTLEWIDTH / 2); y++)
            if(x % MAPWIDTH == y)
                map[x] = OOBBARRIER;
        // east
        for(y = 1; y <= (SCNTLEHEIGHT / 2); y++)
            if(x % MAPWIDTH == MAPWIDTH - y)
                map[x] = OOBBARRIER;
    }
    setobj(0, SPACE, 0);
    setobj(1, OOBBARRIER, 1);
}

void printmap()
{
    int x;

    for(x = 0; x < MAPLENGTH; x++)
    {
        if(x % MAPWIDTH == 0)
            printf("|\n");
        printf("%d", objects[map[x]].type);
    }
}

void printscreen()
{
    int x;

    setscreen();

    printf("%d", objects[players.hand].type);

    for(x = 0; x < SCREENLENGTH; x++)
    {
        if(x % SCREENWIDTH == 0)
            printf("|\n");
        printf("%c", screen[x]);
    }
}

void setscreen()
{
    int x, y, z, l;
    int start = players.position - (SCNTLEWIDTH / 2) -
                    ((SCNTLEHEIGHT / 2) * MAPWIDTH);

    // fix variable sprite sizes !!!!!!!!!
    for(l = 0; l < SCNTLEHEIGHT; l++) // screen tile height
    {
        for(z = 0; z < TILEHEIGHT; z++) // tile height
        for(y = 0; y < SCNTLEWIDTH; y++) // sreen tile width
        {
        for(x = 0; x < TILEWIDTH; x++)
        {
            // set sprite
            screen[x + (y * TILEWIDTH) + (z * SCREENWIDTH) +
                (l * SCREENWIDTH * TILEHEIGHT)] = 
                    sprites[objects[map[start + y + (l * 
                                MAPWIDTH)]].sprite][x +
                        (z * SPRITEWIDTH) + (SPRITELENGTH / 2)];

            // set player sprite
            if(start + y + (l * MAPWIDTH) == players.position)
                if(sprites[PLAYER_S][x + (z * SPRITEWIDTH) + 
                                    (SPRITELENGTH / 2)] != ' ')
                    screen[x + (y * TILEWIDTH) + (z * SCREENWIDTH) 
                            + (l * SCREENWIDTH * TILEHEIGHT)] = 
                        sprites[PLAYER_S][x + (z * SPRITEWIDTH) + 
                                        (SPRITELENGTH / 2)];

            // set player sprite overlap
            if(start + y + (l * MAPWIDTH) + MAPWIDTH == players.position)
                if(sprites[PLAYER_S][x + (z * SPRITEWIDTH)] != ' ')
                    screen[x + (y * TILEWIDTH) + (z * SCREENWIDTH) 
                            + (l * SCREENWIDTH * TILEHEIGHT)] = 
                        sprites[PLAYER_S][x + (z * SPRITEWIDTH)];

            //printf("c%d ", x + (z * SPRITEWIDTH));
            //printf("p%d ", x + (y * TILEWIDTH) + (z * SCREENWIDTH) 
                            //+ (l * SCREENWIDTH * TILEHEIGHT));
            //printf("\n");

            // set hand sprite !!!!!!

            // set sprite overlap
            if(sprites[objects[map[start + y + (l * MAPWIDTH) + 
                    MAPWIDTH]].sprite][x + (z * SPRITEWIDTH)] != ' ')
                screen[x + (y * TILEWIDTH) + (z * SCREENWIDTH) +
                        (l * SCREENWIDTH * TILEHEIGHT)] = 
                    sprites[objects[map[start + y + (l * 
                            MAPWIDTH) + MAPWIDTH]].sprite][x + 
                                (z * SPRITEWIDTH)];
            }
            //printf("\n");
        }
        //printf("\n");
    }
}

void useraction()
{
    char in, ret;
                    //interact carry replace
    printf("\nMove(km,.) down(l) up(o) press(p):");
    scanf("%c%c", &in, &ret);

    switch(in)
    {
        case 'k':
        case '.':
        case 'm':
        case ',':
            usermove(in);
            break;
        case 'l':
        case 'o':
        case 'p':
            action(in);
            break;
        default:
            printf("?: ");
            break;
    }
}

void action(char in)
{
    char der, ret;

    printf("\ndirection(km,. pi) to ");
    switch(in)
    {
        case 'l':
            printf("down");
            break;
        case 'o':
            printf("up");
            break;
        case 'p':
            printf("press");
            break;
    }
    printf(":");
    scanf("%c%c", &der, &ret);

    switch(der)
    {
        case 'k':
        case '.':
        case 'm':
        case ',':
        case 'p':
        // case 'i':
            objaction(in, der);
            break;
        default:
            printf("?: ");
            break;
    }
}

void objaction(char in, char der)
{
    int position;
    int groundid;

    switch(der)
    {
        case 'k':
            position = players.position - MAPWIDTH;
            break;
        case '.':
            position = players.position + 1;
            break;
        case 'm':
            position = players.position - 1;
            break;
        case ',':
            position = players.position + MAPWIDTH;
            break;
        case 'p':
            position = players.position;
            break;
    }

    groundid = map[position];

    switch(in)
    {
        case 'l':
            recepiedo(players.hand, groundid, position);
            break;
        case 'o':
            carrydo(players.hand, groundid, position);
            break;
        case 'p':
            replacedo(players.hand, groundid, position);
            break;
    }
}

int usermove(char in)
{
    int position = players.position;

    switch(in)
    {
        case 'k':
            if(collisioncheck(position - MAPWIDTH) == 1)
                return position;
            else 
            {
                printf("you head north");
                position = position - MAPWIDTH;
            }
            break;
        case ',':
            if(collisioncheck(position + MAPWIDTH) == 1)
                return position;
            else 
            {
                printf("you head south");
                position = position + MAPWIDTH;
            }
            break;
        case 'm':
            if(collisioncheck(position - 1) == 1)
                return position;
            else 
            {
                printf("you head west");
                position = position - 1;
            }
            break;
        case '.':
            if(collisioncheck(position + 1) == 1)
                return position;
            else 
            {
                printf("you head east");
                position = position + 1;
            }
            break;
    }
    players.position = position;

    return position;
}

int collisioncheck(int positionToCheck)
{
    return objects[map[positionToCheck]].playersolid;
}

void setobj(int id, int type, int position)
{
    switch(type)
    {
        // space
        case SPACE:
            objects[id].type = SPACE;
            objects[id].num_sprites = 1;
            objects[id].sprite = SPACE_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 0;
            break;

        // oob barier
        case OOBBARRIER:
            objects[id].type = OOBBARRIER;
            objects[id].num_sprites = 1;
            objects[id].sprite = OOBBARRIER_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;
        // rock
        case STONE:
            objects[id].type = STONE;
            objects[id].num_sprites = 10;
            objects[id].sprite_num = 1;
            objects[id].sprite = STONE_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // big rock
        case BIG_STONE:
            objects[id].type = BIG_STONE;
            objects[id].num_sprites = 1;
            objects[id].sprite = BIG_STONE_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 0;
            break;

        // sharp rock
        case SHARP_STONE:
            objects[id].type = SHARP_STONE;
            objects[id].num_sprites = 4;
            objects[id].sprite_num = 1;
            objects[id].sprite = SHARP_STONE_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // FLINT_CHIP
        case FLINT_CHIP:
            objects[id].type = FLINT_CHIP;
            objects[id].num_sprites = 4;
            objects[id].sprite_num = 1;
            objects[id].sprite = FLINT_CHIP_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // ARROW_HEAD
        case ARROW_HEAD:
            objects[id].type = ARROW_HEAD;
            objects[id].num_sprites = 1;
            objects[id].sprite = ARROW_HEAD_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // FLINT_ROCK
        case FLINT_ROCK:
            objects[id].type = FLINT_ROCK;
            objects[id].num_sprites = 1;
            objects[id].sprite = FLINT_ROCK_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // yew
        case YEW:
            objects[id].type = YEW;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 2;
            objects[id].sprite = YEW_S + 1;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].timenum = 60 * 60;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;

        // PINE
        case PINE:
            objects[id].type = PINE;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 2;
            objects[id].sprite = PINE_S + 1;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].timenum = 60 * 60;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;

        // MAIPEL
        case MAIPEL:
            objects[id].type = MAIPEL;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 2;
            objects[id].sprite = MAIPEL_S + 1;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].timenum = 60 * 60;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;

        // BENT
        case BENT:
            objects[id].type = BENT;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 2;
            objects[id].sprite = BENT_S + 1;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].timenum = 60 * 60;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;

        // JUNIPER
        case JUNIPER:
            objects[id].type = JUNIPER;
            objects[id].num_sprites = 1;
            objects[id].sprite = JUNIPER_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 1;
            objects[id].sheepsolid  = 1;
            objects[id].plrcarry = 0;
            break;

        // YEW_BRANCH
        case YEW_BRANCH:
            objects[id].type = YEW_BRANCH;
            objects[id].num_sprites = 1;
            objects[id].sprite = YEW_BRANCH_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // BOW_SHAFT
        case BOW_SHAFT:
            objects[id].type = BOW_SHAFT;
            objects[id].num_sprites = 1;
            objects[id].sprite = BOW_SHAFT_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // STRAIT_BRANCH
        case STRAIT_BRANCH:
            objects[id].type = STRAIT_BRANCH;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 1;
            objects[id].sprite = STRAIT_BRANCH_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // STRAIT_SHAFT
        case STRAIT_SHAFT:
            objects[id].type = STRAIT_SHAFT;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 1;
            objects[id].sprite = STRAIT_SHAFT_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // BENT_BRANCH
        case BENT_BRANCH:
            objects[id].type = BENT_BRANCH;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 1;
            objects[id].sprite = BENT_BRANCH_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // BENT_SHAFT
        case BENT_SHAFT:
            objects[id].type = BENT_SHAFT;
            objects[id].num_sprites = 2;
            objects[id].sprite_num = 1;
            objects[id].sprite = BENT_SHAFT_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // PUMP_KIT
        case PUMP_KIT:
            objects[id].type = PUMP_KIT;
            objects[id].num_sprites = 1;
            objects[id].sprite = PUMP_KIT_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // SHORT_SHAFT_S
        case SHORT_SHAFT:
            objects[id].type = SHORT_SHAFT;
            objects[id].num_sprites = 1;
            objects[id].sprite = SHORT_SHAFT_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

        // STAKES
        case STAKES:
            objects[id].type = STAKES;
            objects[id].num_sprites = 6;
            objects[id].sprite_num = 1;
            objects[id].sprite = STAKES_S;
            objects[id].position = position;
            objects[id].clockid = 0;
            objects[id].carryid = 0;
            objects[id].playersolid = 0;
            objects[id].sheepsolid  = 0;
            objects[id].plrcarry = 1;
            break;

    }
}

void carrydo(int handid, int groundid, int position)
{
    if(handid == HAND)
        if(objects[groundid].plrcarry == 1)
        {
            switch(objects[groundid].type)
            {
                case STRAIT_BRANCH:
                case STRAIT_SHAFT:
                case BENT_BRANCH:
                case BENT_SHAFT:
                    players.hand = groundid;
                    objects[groundid].position = 0;
                    map[position] = 0;
                    break;

                default:
                // is stack ?
                if((objects[groundid].num_sprites > 1)
                    && (objects[groundid].sprite_num > 1))
                // -1 stack
                {
                    players.hand = popvid();
                    setobj(players.hand, objects[groundid].type, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                }
                else
                // pickup
                {
                    players.hand = groundid;
                    objects[groundid].position = 0;
                    map[position] = 0;
                }
            }
        }
}

void replacedo(int handid, int groundid, int position)
{
    if(handid == HAND)
    {
        switch(objects[groundid].type)
        {
            case YEW:
                if(objects[groundid].sprite_num > 1)
                {
                    players.hand = popvid();
                    setobj(players.hand, YEW_BRANCH, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                    //objects[groundid].sprite
                    // 1hour time !!!!!!
                }
                break;

            // PINE
            case PINE:
                if(objects[groundid].sprite_num > 1)
                {
                    // players.hand = popvid();
                    // setobj(players.hand, needles!!!!!!!!!!!!!!, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                    // objects[groundid].sprite
                    // 1hour time !!!!!!
                }
                break;

            case MAIPEL:
                if(objects[groundid].sprite_num > 1)
                {
                    players.hand = popvid();
                    setobj(players.hand, STRAIT_BRANCH, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                    // objects[groundid].sprite
                    // 1hour time !!!!!!
                }
                break;

            case BENT:
                if(objects[groundid].sprite_num > 1)
                {
                    players.hand = popvid();
                    setobj(players.hand, BENT_BRANCH, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                    // objects[groundid].sprite
                    // 1hour time !!!!!!
                }
                break;

            // pump kit
            case PUMP_KIT:
                if(objects[groundid].sprite_num > 1)
                {
                    players.hand = popvid();
                    setobj(players.hand, BENT_SHAFT, 0);
                    objects[players.hand].sprite_num += 1;
                    objects[players.hand].sprite += 1;
                    setobj(groundid, STRAIT_SHAFT, position);
                    objects[groundid].sprite_num += 1;
                    objects[groundid].sprite += 1;
                }
                break;

            default:
                if(objects[groundid].plrcarry == 1)
                {
                // is stack ?
                if((objects[groundid].num_sprites > 1)
                    && (objects[groundid].sprite_num > 1))
                // -1 stack
                {
                    players.hand = popvid();
                    setobj(players.hand, objects[groundid].type, 0);
                    objects[groundid].sprite_num -= 1;
                    objects[groundid].sprite -= 1;
                }
                else
                // pickup
                {
                    players.hand = groundid;
                    objects[groundid].position = 0;
                    map[position] = 0;
                }
                }
        }
    }
    else
    {
        if(groundid != 0)
        if(objects[groundid].plrcarry == 1)
        {
            if(objects[groundid].carryid == 0)
            {
                // replace ground
                map[position] = players.hand;
                players.hand = groundid;
                objects[handid].position = position;
                objects[groundid].position = 0;

            }
            else
            {
                // replace in
            }
        }
    }

/*
define YEW_BRANCH 13
#define YEW_BRANCH_S 40
#define BOW_SHAFT    14
#define BOW_SHAFT_S 41
#define STRAIT_BRANCH 15
#define STRAIT_BRANCH_S 42 // +1
#define STRAIT_SHAFT 16
#define STRAIT_SHAFT_S 44 // +1
#define BENT_BRANCH 17
#define BENT_BRANCH_S 46 // +1
#define BENT_SHAFT 18
#define BENT_SHAFT_S 48 // +1
#define PUMP_KIT     19
#define PUMP_KIT_S 50

struct object
{
    int type;
    int num_sprites;
    int sprite_num;
    int sprite;
    int position;
    bool clock;
    int timeid;
    int timenum;
    int carryid;
    bool playersolid;
    bool sheepsolid;
    bool plrcarry;
    bool ret[4];
};
*/
}

void recepiedo(int handid, int groundid, int position)
{
    if(objects[groundid].type == objects[handid].type)
    {
        // stack
        if(objects[groundid].num_sprites > 1)
        if(objects[groundid].sprite_num < 
                            objects[groundid].num_sprites)
        if(objects[handid].sprite_num == 1)
        {
            players.hand = 0;
            pushvid(handid);
            objects[groundid].sprite_num += 1;
            objects[groundid].sprite += 1;
        }
    }
    if(objects[groundid].type == SPACE)
    {
        // drop
        map[position] = handid;
        objects[handid].position = position;
        players.hand = 0;
    }

    switch(objects[handid].type)
    {
        // STONE
        case STONE:
            switch(objects[groundid].type)
            {
                case BIG_STONE:
                    setobj(handid, SHARP_STONE, 0);
                    break;
                // stakes
                case STAKES:
                    if(objects[groundid].sprite_num < 
                            objects[groundid].num_sprites)
                    {
                        objects[groundid].sprite_num += 1;
                        objects[groundid].sprite += 1;
                        objects[groundid].plrcarry = 0;
                    }
                    else
                    {
                        objects[groundid].sprite_num = 1;
                        objects[groundid].sprite = STAKES_S;
                        objects[groundid].plrcarry = 1;
                    }
                    break;
                    // stakestack?
                // scewer
                    // home marker
                // adoby
                    // adoby base
                // clay 1
                    // wet clay blowl
                // wet clay blowl
                    // wet clay plate
                // wet clay plate
                    // clay
                // clay 2
                    // wet big bowl
                // clay 3
                    // wet steamer
            }
            break;

        // BIG_STONE 
// SHARP_STONE
        case SHARP_STONE:
            switch(objects[groundid].type)
            {
                // flint rock
                case FLINT_ROCK:
                    setobj(groundid, FLINT_CHIP, position);
                    objects[groundid].sprite_num = 4;
                    objects[groundid].sprite += 3;
                    break;
                    // flint chip 4
                // flint chip ?1
                case FLINT_CHIP:
                    if(objects[groundid].sprite_num == 1)
                        setobj(groundid, ARROW_HEAD, position);
                    break;
                    // arrow head
                // long strait branch (2)
                case STRAIT_BRANCH:
                    if(objects[groundid].sprite_num == 1)
                        setobj(groundid, STRAIT_SHAFT, position);
                    else
                    {
                        setobj(groundid, STRAIT_SHAFT, position);
                        objects[groundid].sprite_num = 2;
                        objects[groundid].sprite += 1;
                    }
                    break;
                    // long strait shaft (2)
                // bent branch (2)
                case BENT_BRANCH:
                    if(objects[groundid].sprite_num == 1)
                        setobj(groundid, BENT_SHAFT, position);
                    else
                    {
                        setobj(groundid, BENT_SHAFT, position);
                        objects[groundid].sprite_num = 2;
                        objects[groundid].sprite += 1;
                    }
                    break;
                    // bent shaft (2)
                // yew branch
                case YEW_BRANCH:
                        setobj(groundid, BOW_SHAFT, position);
                    break;
                    // yew shaft
                // long strait shaft 1
                case STRAIT_SHAFT:
                    if(objects[groundid].sprite_num == 1)
                        setobj(groundid, SHORT_SHAFT, position);
                    break;
                    // short strait shaft
                // short strait shaft
                case SHORT_SHAFT:
                        setobj(groundid, STAKES, position);
                    break;
                    // stakes

                // stock
                    // scewer
            }
            break;

        // FLINT_CHIP
        case FLINT_CHIP:
            switch(objects[groundid].type)
            {
                case FLINT_CHIP:
                    // stack
                    if(objects[groundid].sprite_num < 
                            objects[groundid].num_sprites)
                    {
                        players.hand = 0;
                        pushvid(handid);
                        objects[groundid].sprite_num += 1;
                        objects[groundid].sprite += 1;
                    }
                    break;
                // long strait shaft 1
                    // tongs
                // stock
                    // stock with shaving
                // dead "animal"
                    // "animal" pelt
                    // skinned "animal"
            }
            break;

        // ARROW_HEAD
                // short shaft
                    // hole punch
                // fire bow drill
                    // flint tip bow drill
                // tied skewer
                    // fetherless arrow

        // 7 - 18

        // BENT_BRANCH
        case BENT_SHAFT:
            switch(objects[groundid].type)
            {
                // strait shaft 2
                case STRAIT_SHAFT:
                    if(objects[handid].sprite_num == 2)
                    if(objects[groundid].sprite_num == 2)
                    {
                        setobj(groundid, PUMP_KIT, 0);
                        players.hand = 0;
                        pushvid(handid);
                    }
                    break;
                    // pump kit
            }
    }
}