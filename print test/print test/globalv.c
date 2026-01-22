// globalv.c
#pragma once

#include "map_screen.h"
#include "sprite_constants.h"
#include "structs.h"

int  map[MAPLENGTH];
char screen[SCREENLENGTH];
char sprites[NUMSPRITES][SPRITELENGTH + 1];
struct object objects[MAPLENGTH];