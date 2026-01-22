// action_do.h

#include "../distribution/object distribution/obj_map.h"

// function prototypes
void carrydo(int handid, int groundid, int position);
void replacedo(int handid, int groundid, int position);
void recepiedo(int handid, int groundid, int position);

// functions
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