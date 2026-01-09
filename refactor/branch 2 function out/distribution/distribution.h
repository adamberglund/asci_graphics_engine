// distribution.h

// Libraries
// ditribution standar_libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "obj_map.h"
#include "sprites.h"

// ditribution Global_Utility_Definitions {
#define MAPWIDTH     32
#define MAPHEIGHT    32
#define MAPLENGTH    MAPWIDTH * MAPHEIGHT
#define TILEWIDTH    8
#define TILEHEIGHT   4
#define TILELENGTH   TILEWIDTH * TILEHEIGHT
#define SCNTLEWIDTH  6
#define SCNTLEHEIGHT 6
#define SCNTLELENGTH SCNTLEWIDTH * SCNTLEHEIGHT
#define SCREENWIDTH  TILEWIDTH   * SCNTLEWIDTH
#define SCREENHEIGHT TILEHEIGHT  * SCNTLEHEIGHT
#define SCREENLENGTH SCREENWIDTH * SCREENHEIGHT

// ditribution Object_Structures  {
struct player
{
    int position;
    int hunger;
    int hungertime;
    int age;
    int bdaytime;
    int hand;
    int back;
    int head;
    int body;
    int legs;
    int lfoot;
    int rfoot;
};

struct object
{
    int type;
    int num_sprites;
    int sprite_num;
    int sprite;
    int position;
    int clockid;
    int timeid;
    int timenum;
    int carryid;
    int playersolid;
    int sheepsolid;
    int plrcarry;
    int ret[5];
};

struct objcarry
{
    int carrymun;
    int carry1;
    int carry2;
    int carry3;
    int carry4;
    int carry5;
    int carry6;
};

struct clock
{
    int timeleft;
    int objid;
};

// ditribution global_variables
int            map[MAPLENGTH];
char           screen[SCREENLENGTH];

char           sprites[NUMSPRITES][SPRITELENGTH];
struct player  players;
int            voidobjs[MAPLENGTH + 1];
struct object  objects[MAPLENGTH];
int            voidclocks[MAPLENGTH + 1];
struct clock   clocks[MAPLENGTH];