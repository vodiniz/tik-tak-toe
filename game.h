#include <stdio.h>
#include <string.h>
#include "files.h"
#include "display.h"
#include "game_logic.h"


void run_game();
void test_game();
int get_option(int gaming);
void new_game();




void run_game (){

    int gaming = 0;
    display_game_name();
    int option;

    do{
        display_options(gaming);
        option = get_option(gaming);

        switch (option){
            case 1:
                new_game();
                break;
            case 2:
                //load game_file
                break;

            case 3:
                //
                //return_game();
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


void new_game(){

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
    
    Game current_game;
    
    char player1_name[STR_SIZE];
    char player2_name[STR_SIZE];

    if (player_number == 1){

        getchar();
        printf(BOLD(BLUE("\n\n\t\t\t\tDigite o nome do jogador 1: ")));
        fgets(player1_name, STR_SIZE, stdin);

        current_game.player_count = 2;
        strcpy(current_game.player1, remove_new_line(player1_name));
        strcpy(current_game.player2,"Computador");

        empty_board(current_game.board);
        
        current_game.last_play = 2;
            
    } else {

        getchar();
        printf(BOLD(BLUE("\n\n\t\t\t\tDigite o nome do jogador 1: ")));
        fgets(player1_name, STR_SIZE, stdin);

        printf(BOLD(BLUE("\n\n\t\t\t\tDigite o nome do jogador 2: ")));
        fgets(player2_name, STR_SIZE, stdin);


        current_game.player_count = 2;
        strcpy(current_game.player1, remove_new_line(player1_name));
        strcpy(current_game.player2, remove_new_line(player2_name));
        empty_board(current_game.board);
        current_game.last_play = 2;
    }


    game_loop(current_game);

       
}
