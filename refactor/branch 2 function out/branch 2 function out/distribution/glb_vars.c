// glb_vars.c

// how to distribute:
// nested libraries
// global variables

// can distribute: through include files
// global definitions
// functions
// structures

// Libraries
// ditribution standar_libraries
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "object distribution/sprites.h"
*/
#include "object distribution/spr_const.h"
#include "object distribution/map_const.h"
#include "object distribution/structures.h"

// ditribution global_variables
int            map[MAPLENGTH];
char           screen[SCREENLENGTH];

char           sprites[NUMSPRITES][SPRITELENGTH];
struct player  players;
int            voidobjs[MAPLENGTH + 1];
struct object  objects[MAPLENGTH];
int            voidclocks[MAPLENGTH + 1];
struct clock   clocks[MAPLENGTH];