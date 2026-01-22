// input.h

#include <stdio.h>

#include "game_logic.h"
#include "../distribution/glb_vars.c"
#include "action_do.h"

// function prototypes
int  usermove(char in);
void useraction();
void action(char in);
void objaction(char in, char der);

// functions
int usermove(char in)
{
    int position = players.position;

    switch(in)
    {
        case 'k':
            if(collisioncheck(position - MAPWIDTH) == 1)
                return position;
            else 
            {
                printf("you head north");
                position = position - MAPWIDTH;
            }
            break;
        case ',':
            if(collisioncheck(position + MAPWIDTH) == 1)
                return position;
            else 
            {
                printf("you head south");
                position = position + MAPWIDTH;
            }
            break;
        case 'm':
            if(collisioncheck(position - 1) == 1)
                return position;
            else 
            {
                printf("you head west");
                position = position - 1;
            }
            break;
        case '.':
            if(collisioncheck(position + 1) == 1)
                return position;
            else 
            {
                printf("you head east");
                position = position + 1;
            }
            break;
    }
    players.position = position;

    return position;
}

void useraction()
{
    char in, ret;
                    //interact carry replace
    printf("\nMove(km,.) down(l) up(o) press(p):");
    scanf("%c%c", &in, &ret);

    switch(in)
    {
        case 'k':
        case '.':
        case 'm':
        case ',':
            usermove(in);
            break;
        case 'l':
        case 'o':
        case 'p':
            action(in);
            break;
        default:
            printf("?: ");
            break;
    }
}

void action(char in)
{
    char der, ret;

    printf("\ndirection(km,. pi) to ");
    switch(in)
    {
        case 'l':
            printf("down");
            break;
        case 'o':
            printf("up");
            break;
        case 'p':
            printf("press");
            break;
    }
    printf(":");
    scanf("%c%c", &der, &ret);

    switch(der)
    {
        case 'k':
        case '.':
        case 'm':
        case ',':
        case 'p':
        // case 'i':
            objaction(in, der);
            break;
        default:
            printf("?: ");
            break;
    }
}

void objaction(char in, char der)
{
    int position;
    int groundid;

    switch(der)
    {
        case 'k':
            position = players.position - MAPWIDTH;
            break;
        case '.':
            position = players.position + 1;
            break;
        case 'm':
            position = players.position - 1;
            break;
        case ',':
            position = players.position + MAPWIDTH;
            break;
        case 'p':
            position = players.position;
            break;
    }

    groundid = map[position];

    switch(in)
    {
        case 'l':
            recepiedo(players.hand, groundid, position);
            break;
        case 'o':
            carrydo(players.hand, groundid, position);
            break;
        case 'p':
            replacedo(players.hand, groundid, position);
            break;
    }
}