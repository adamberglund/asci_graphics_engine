// sprites.h

#include <string.h>

#include "sprite_constants.h"
#include "globalv.c"

void setsprites()
{
    strcpy(sprites[0],
                        "AB"
                        "EF");

    // player
    strcpy(sprites[1],
                        "CD"
                        "GH");
}