// libraries
#include <stdio.h>

#include "sprites.h"
#include "setters.h"
#include "globalv.h"

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

    setscreen();

    for(x = 0; x < SCREENLENGTH; x++)
    {
        if(x % SCREENWIDTH == 0)
            printf("|\n");
        printf("%c", screen[x]);
    }
}