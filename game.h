#include <stdio.h>
#include "game_logic.h"
#include "display.h"

void run_game ();




void run_game (){

    int gaming = 1;

    display_game_name();
    display_options(gaming);
}
