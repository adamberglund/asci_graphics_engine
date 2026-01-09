// setters

// function prototypes
void setvoids();
void setplayer();
void setobj(int id, int type, int position);
void setmap();
void setscreen();

// functions
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