// game_logic.h

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

    setscreen();

    printf("%d", objects[players.hand].type);

    for(x = 0; x < SCREENLENGTH; x++)
    {
        if(x % SCREENWIDTH == 0)
            printf("|\n");
        printf("%c", screen[x]);
    }
}

int collisioncheck(int positionToCheck)
{
    return objects[map[positionToCheck]].playersolid;
}