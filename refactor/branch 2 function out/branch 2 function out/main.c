// ohol 
// ohol 2

// check invalid space interactions !!!!!

// Libraries
#include "distribution/glb_vars.c"
#include "utility/setters.h"
#include "game logic/game_logic.h"
#include "game logic/input.h"

// main
int main(){
    setvoids();
    setsprites(sprites);
    setplayer();
    setmap();

    while(1){
        printscreen();
        useraction();
        // clearscreen();
    }
    return 0;
}