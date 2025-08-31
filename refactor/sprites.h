#include <string.h>

#include "obj_map.h"

#define NUMSPRITES   58
#define SPRITEWIDTH  8
#define SPRITEHEIGHT 8
#define SPRITELENGTH SPRITEWIDTH * SPRITEHEIGHT

void setsprites(char sprites[NUMSPRITES][SPRITELENGTH])
{
    strcpy(sprites[SPACE_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        ");

    strcpy(sprites[OOBBARRIER_S],
                        "........"
                        "........"
                        "........"
                        "........"
                        "........"
                        "........"
                        "........"
                        "........");

    strcpy(sprites[2],  "12345678"
                        "abcdefgh"
                        "ijklmnop"
                        "qrstuvwx"
                        "yz......"
                        "        "
                        "        "
                        "        ");

    strcpy(sprites[PLAYER_S],
                        "        "
                        "   ___  "
                        "  /.,.\\ "
                        "  \\_o_/ "
                        "  /[_]\\ "
                        "   [_]  "
                        "  /   \\ "
                        "        ");

// stone 10-19 (11-10)
    strcpy(sprites[STONE_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ()   "
                        "        ");

    strcpy(sprites[STONE_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ()()  "
                        "        ");

    strcpy(sprites[STONE_S + 2],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  (())  "
                        "        ");

    strcpy(sprites[STONE_S + 3],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ()   "
                        "  (())  "
                        "        ");

    strcpy(sprites[STONE_S + 4],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ()()  "
                        "  (())  "
                        "        ");

    strcpy(sprites[STONE_S + 5],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  (())  "
                        "  (())  "
                        "        ");

    strcpy(sprites[STONE_S + 6],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  (())  "
                        " (())() "
                        "        ");

    strcpy(sprites[STONE_S + 7],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  (())  "
                        " (()()) "
                        "        ");

    strcpy(sprites[STONE_S + 8],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " (())() "
                        " (()()) "
                        "        ");

    strcpy(sprites[STONE_S + 9],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " (()()) "
                        " (()()) "
                        "        ");

// bid rock
    strcpy(sprites[BIG_STONE_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ,~~.  "
                        " {____} "
                        "        ");
// sharp stone
    strcpy(sprites[SHARP_STONE_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   <)   "
                        "        ");

    strcpy(sprites[SHARP_STONE_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  <)<)  "
                        "        ");

    strcpy(sprites[SHARP_STONE_S + 2],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   <)   "
                        "  <)<)  "
                        "        ");

    strcpy(sprites[SHARP_STONE_S + 3],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  <)<)  "
                        "  <)<)  "
                        "        ");

    strcpy(sprites[FLINT_CHIP_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   <>   "
                        "        ");

    strcpy(sprites[FLINT_CHIP_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  <><>  "
                        "        ");

    strcpy(sprites[FLINT_CHIP_S + 2],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   <>   "
                        "  <><>  "
                        "        ");

    strcpy(sprites[FLINT_CHIP_S + 3],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  <><>  "
                        "  <><>  "
                        "        ");

    strcpy(sprites[ARROW_HEAD_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   <|   "
                        "        ");

    strcpy(sprites[FLINT_ROCK_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ...  "
                        "  (___) "
                        "        ");
    strcpy(sprites[YEW_S],
                        "        "
                        "   /\\   "
                        "  {::}  "
                        "  {::}  "
                        "  {::}  "
                        "  {::}  "
                        "   ||   "
                        "        ");

    strcpy(sprites[YEW_S + 1],
                        "        "
                        "   /\\   "
                        "  {::}  "
                        "  {::}  "
                        "  {::}  "
                        "  {::}  "
                        "   || ] "
                        "        ");

    strcpy(sprites[PINE_S],
                        "        "
                        "   /\\   "
                        "  //\\\\  "
                        "  //\\\\  "
                        "  //\\\\  "
                        "  //\\\\  "
                        "   ||   "
                        "        ");

    strcpy(sprites[PINE_S + 1],
                        "        "
                        "   /\\   "
                        "  //\\\\  "
                        "  //\\\\  "
                        "  //\\\\  "
                        "  //\\\\  "
                        "  ~||~  "
                        "        ");

    strcpy(sprites[MAIPEL_S],
                        "        "
                        "        "
                        "  {\"\"}  "
                        " {\"\"\"\"} "
                        " {\"\"\"\"} "
                        " {\"\"\"\"} "
                        "   ||   "
                        "        ");
    strcpy(sprites[MAIPEL_S + 1],
                        "        "
                        "        "
                        "  {\"\"}  "
                        " {\"\"\"\"} "
                        " {\"\"\"\"} "
                        " {\"\"\"\"} "
                        "   ||[  "
                        "        ");

    strcpy(sprites[BENT_S],
                        "        "
                        "   /\\   "
                        "  {()}  "
                        "  {()}  "
                        "  {()}  "
                        "  {()}  "
                        "   ||   "
                        "        ");

    strcpy(sprites[BENT_S + 1],
                        "        "
                        "   /\\   "
                        "  {()}  "
                        "  {()}  "
                        "  {()}  "
                        "  {()}  "
                        "   || ] "
                        "        ");

    strcpy(sprites[JUNIPER_S],
                        "        "
                        "        "
                        "**    **"
                        " *\\  / *"
                        "  / /   "
                        "*+  \\** "
                        "  \\ /   "
                        "        ");

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    strcpy(sprites[YEW_BRANCH_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ////// "
                        " ______ "
                        "        ");

    strcpy(sprites[BOW_SHAFT_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ______ "
                        " ______ "
                        "        ");

    strcpy(sprites[STRAIT_BRANCH_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ////// "
                        " ------ "
                        "        ");

    strcpy(sprites[STRAIT_BRANCH_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ////// "
                        " ------ "
                        " ------ ");

    strcpy(sprites[STRAIT_SHAFT_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ------ "
                        " ------ "
                        "        ");

    strcpy(sprites[STRAIT_SHAFT_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ------ "
                        " ------ "
                        " ------ ");

    strcpy(sprites[BENT_BRANCH_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ///  "
                        "  {   } "
                        "        ");

    strcpy(sprites[BENT_BRANCH_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ////  "
                        " {{  }} "
                        "        ");

    strcpy(sprites[BENT_SHAFT_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ___  "
                        "  (   ) "
                        "        ");

    strcpy(sprites[BENT_SHAFT_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ____  "
                        " ((  )) "
                        "        ");

    strcpy(sprites[PUMP_KIT_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        " ------ "
                        " -____- "
                        " ((  )) ");

    strcpy(sprites[SHORT_SHAFT_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  ___   "
                        "  ---   "
                        "        ");

    strcpy(sprites[STAKES_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ++   "
                        "   ++   "
                        "        ");

    strcpy(sprites[STAKES_S + 1],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "+      +"
                        "+      +"
                        "        ");

    strcpy(sprites[STAKES_S + 2],
                        "        "
                        "        "
                        "        "
                        "        "
                        "   ++   "
                        "        "
                        "        "
                        "   ++   ");

    strcpy(sprites[STAKES_S + 3],
                        "        "
                        "        "
                        "        "
                        "        "
                        "   +    "
                        "       +"
                        "+       "
                        "    +   ");

    strcpy(sprites[STAKES_S + 4],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "  +  +  "
                        "  +  +  "
                        "        ");

    strcpy(sprites[STAKES_S + 5],
                        "        "
                        "        "
                        "        "
                        "        "
                        "+      +"
                        "        "
                        "        "
                        "+      +");

    strcpy(sprites[TONGS_S],
                        "        "
                        "        "
                        "        "
                        "        "
                        "  \\  /  "
                        "   \\/   "
                        "   /\\   "
                        "  /  \\  ");



    strcpy(sprites[0],
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        "
                        "        ");
}

/*

39
juniper
**    **
 *\  /*
  / /
*+  \**
  \/

branch
yew
//////
______
______
______

long strait shaft
//////
------
//////
------
------

------
------
------
------
------

tongs
\  /
 \/
 /\
/  \
short shaft
___
---

stakes
++
++
ember shaft
   /
  /
------
------


fence kit
------
--//--
------
------
-_//_-
-\__/-

 __
/__\
'  '
 ___
/_|_\
' | '

 ___
/_|_\
' | '
  '
______
\____/

   "
___|__
\__|_/
   '
seed
.

leaf
<@
<3

kindeling
*

|
*
3
*

_ 
*
pine needles
 ~~~
/~~~\

fire starter
# 
##

###
# 
###

##
###
###
###

cut wood
[]

[][]
[[]]

[]
[[]]
[][]
[[]]

[[]]
[[]]
__
||
\/
||

iron
 ___
/__/
 ____
//__/

 _____
///__/
  ___
 /__/_
///__/

 ____
//__/_
///__/
 _____
///__/
///__/

/~~\
\~~/

/33\
\33/

 ___
(___)
 ___
(333)

 __
[__]
 __
[33]

fire
/111\

/···\
 3
 3
/1\

 3 3
  3
/111\
3 3 3
 4 4
/111\\

clay bowl
___
\_/
~~~
\_/

,__
\_/
,,_ 
\_/

,,,
\_/
 ,
,,,
\_/

,,
,,,
\_/
,,,
,,,
\_/

,|,
,|,
\_/
adobe base
 _    _
( \__/ )
 \____/

oven
  ____
 / __ \
( /  \ )
( \__/ )
 \____/

kilm
  ||_
  |  \
 / __ \
( /  \ )
( \__/ )
 \____/

*/