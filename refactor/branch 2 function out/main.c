// ohol 
// ohol 2

// check invalid space interactions !!!!!

// Libraries
#include "distribution/distribution.h"
#include "utility/utility.h"
#include "game logic/game_logic.h"

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