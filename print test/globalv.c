// globalv.c

#include "map_screen.h"
#include "sprite_constants.h"

/*
struct object
{
    int position;
    int sprite;
};
*/

int           map[MAPLENGTH];
char          screen[SCREENLENGTH];
char          sprites[NUMSPRITES][SPRITELENGTH];
// struct object objects[MAPLENGTH];