#include <stdio.h>
#include "gamefiles.h"
#include "display.h"

#define STR_SIZE 50



void run_game ();
void test_game ();

















void run_game (){

    int gaming = 1;

    display_game_name();
    display_options(gaming);
    test_game();
}

void test_game (){
    Game current = {
            0,
            "NULL",
            "NULL",
            {
                {'-', '-', '-'},
                {'-', '-', '-'},
                {'-', '-', '-'},
            },
            2
    };

    save_game(current, "testando.txt");
    read_save("testasndo.txt");
}