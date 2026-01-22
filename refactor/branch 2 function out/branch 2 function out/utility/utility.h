// utility.h

// to do:
// refactor into linked lists

// Libraries
// #include "setters.h"

// function prototypes
int  popvid();
void pushvclocks(int id);
int  popvclocks();
void pushvid(int id);

// functions
int popvid()
{
    voidobjs[0]--;
    return voidobjs[voidobjs[0] + 1];
}

void pushvclocks(int id)
{
    voidclocks[0]++;
    voidclocks[voidclocks[0]] = id;
}

int popvclocks()
{
    voidclocks[0]--;
    return voidclocks[voidclocks[0] + 1];
}

void pushvid(int id)
{
    voidobjs[0]++;
    voidobjs[voidobjs[0]] = id;
}