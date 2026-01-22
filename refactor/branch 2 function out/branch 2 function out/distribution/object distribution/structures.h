// structures.h

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