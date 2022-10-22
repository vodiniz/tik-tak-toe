#include <stdio.h>
#include <string.h>
#include "files.h"
#include "display.h"
#include "game_logic.h"
#include "game.h"
#include "util.h"
#include "structs.h"


void run_game (){

    int gaming = 0;
    display_game_name();
    int option;
    Game current_game;


    do{
        display_options(gaming);
        option = get_option(gaming);

        switch (option){
            case 1:
                new_game(&current_game, &gaming);
                break;
            case 2:
                break;

            case 3:
                getchar();
                continue_game(&current_game, &gaming);
                break;

            case 4: 
                //show_ranking
                show_ranking();
                break;

            default:
                break;
        }


    } while (option);
    
}




int get_option(int gaming){

    int option = 10; // valor padrão para opção inválida.
    char option_string[200];
    printf("\n\t\t\t");
    scanf("%s", option_string);

    if(!strcmp("0", option_string)){
        option = 0;
    } else if (!strcmp("1", option_string)){
        option = 1;
    } else if (!strcmp("2", option_string)){
        option = 2;
    } else if (!strcmp("3", option_string)){
        if (!gaming && option == 3){
            invalid_option();
            option = 10;
        } else {
            option = 3;
        }
    } else if (!strcmp("4", option_string)){
        option = 4;
    }

    return option;
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


void new_game(Game *game, int *gaming){

    int player_number;
    char player_number_string[STR_SIZE];
    printf(BLUE(BOLD("\t\t\t\tDigite o número de jogadores (1 ou 2): ")));
    scanf("%s", player_number_string);
    
    while (!(!strcmp("1", player_number_string) || !strcmp("2", player_number_string))){
        printf(BLUE(BOLD("\t\t\t\tNúmero inválido, digite novamente.\n")));
        scanf("%s", player_number_string);

    }

    if (!strcmp("1", player_number_string)){
        player_number = 1;
    } else {
        player_number = 2;
    }
    
    
    char player1_name[STR_SIZE];
    char player2_name[STR_SIZE];

    if (player_number == 1){

        getchar();
        printf(BOLD(BLUE("\n\n\t\t\t\tDigite o nome do jogador 1: ")));

        fgets(player1_name, STR_SIZE, stdin);

        while (!strcmp("\n", player1_name) || !strcmp("Computador\n", player1_name)){
            printf(BOLD(RED("\n\n\t\t\t\tNome inválido! Digite o nome novamente.\n")));
            fgets(player1_name, STR_SIZE, stdin);

        }
        
        game->player_count = 2;
        strcpy(game->player1, remove_new_line(player1_name));
        strcpy(game->player2,"Computador");

        empty_board(game->board);
        
        game->last_play = 2;
            
    } else {

        getchar();
        printf(BOLD(BLUE("\n\n\t\t\t\tDigite o nome do jogador 1: ")));

        
        fgets(player1_name, STR_SIZE, stdin);

        while (!strcmp("\n", player1_name) || !strcmp("Computador\n", player1_name)){
            printf(BOLD(RED("\n\n\t\t\t\tNome inválido! Digite o nome novamente.\n")));
            fgets(player1_name, STR_SIZE, stdin);

        }

        printf(BOLD(BLUE("\n\n\t\t1\t\tDigite o nome do jogador 2: ")));
        
        fgets(player2_name, STR_SIZE, stdin);

        while (!strcmp("\n", player2_name) || !strcmp("Computador\n", player2_name) || !strcmp(player1_name, player2_name)){
            printf(BOLD(RED("\n\n\t\t\t\tNome inválido! Digite o nome novamente.\n")));
            fgets(player2_name, STR_SIZE, stdin);

        } 


        game->player_count = 2;
        strcpy(game->player1, remove_new_line(player1_name));
        strcpy(game->player2, remove_new_line(player2_name));
        empty_board(game->board);
        game->last_play = 2;
    }

    game_loop(game, gaming);

       
}




void continue_game(Game *game, int *gaming){
    game_loop(game, gaming);
}
