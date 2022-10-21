#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "structs.h"
#include "game_logic.h"
#include "display.h"



void game_loop(Game game){

    int running = 1;

    while(running){

        print_game_table(game);
        
        if (game.last_play == 2){

            //printf(BOLD(BLUE("%s"  game.player1)));
            printf(ANSI_BOLD ANSI_COLOR_BLUE "\n\n\n\n\t\t\t\t %s , digite o comando: ", game.player1);
            get_commands();

        } else {

            printf(ANSI_BOLD ANSI_COLOR_BLUE "\n\n\n\n\t\t\t\t %s , digite o comando: ", game.player1);
            get_commands();
        }

    }

}


void get_commands(){

    char command[3 * STR_SIZE];
    char first_command[3 * STR_SIZE];

    fgets(command, STR_SIZE, stdin);

    int str_len = strlen(command);

    for ( int i = 0; i < str_len; i++){
        ;
    }
    





}