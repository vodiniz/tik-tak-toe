#include <stdio.h>
#include "structs.h"

void game_loop(Game current_game);








void game_loop(Game game){

    int running = 1;
    char command[STR_SIZE];

    while(running){

        print_game_table(game);
        
        if (game.last_play == 2){

            printf(BOLD(BLUE()));
            printf("\n\n\t\t\t\t%s, digite o comando: ", game.player1);
            fgets(command, STR_SIZE, stdin);


        } else {

        }

    }

}