// libraries
#include <stdio.h>

#include "sprites.h"
#include "setters.h"
#include "globalv.c"

void printscreen();

// main
int main(){
   setsprites();
   map[0] = 0;
   map[1] = 1;

   printscreen();
}

void printscreen()
{
    int x;
    int y = 0;

    setscreen();

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