// setters.h
// map/screen

#include "globalv.h"

void setscreen(){
   int start = 0;

   screen[0] = sprites[0][0];
   screen[1] = sprites[0][1];
   screen[2] = sprites[1][0];
   screen[3] = sprites[1][1];
   screen[4] = sprites[0][2];
   screen[5] = sprites[0][3];
   screen[6] = sprites[1][2];
   screen[7] = sprites[1][3];
}

/*

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

*/