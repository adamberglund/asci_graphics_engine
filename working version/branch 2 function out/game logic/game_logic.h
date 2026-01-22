// game_logic.h

#pragma once

#include <stdio.h>

// functions
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
    int y = 0;

    setscreen();

    printf("%d", objects[players.hand].type);

    for(x = 0; x < SCREENLENGTH; x++)
    {
        if(y == SCREENWIDTH){
            printf("|\n");
            y = 0;
        }
        printf("%c", screen[x]);
        y++;
    }
}

int collisioncheck(int positionToCheck)
{
    return objects[map[positionToCheck]].playersolid;
}