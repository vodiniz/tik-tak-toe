#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "structs.h"
#include "game_logic.h"
#include "display.h"
#include "util.h"



void game_loop(Game *game, int *gaming){

    int running = 1;

    Command command = {"", ""};
    
    while(running){

        print_game_table(*game);
        
        if (game->last_play == 2){
            command = get_commands(*game);
            
            if (!strcmp("marcar", command.first_command)){
                make_move(game, command);
            } else if (!strcmp("salvar", command.first_command)){
                ;
            } else if (!strcmp("voltar", command.first_command)){
                *gaming = 1;
                break;
            }

        } else {
            if (!strcmp(game->player2, "Computador")){
                ;
            } else {
                command = get_commands(*game);
            }

            if (!strcmp("marcar", command.first_command)){
                make_move(game, command);
            } else if (!strcmp("salvar", command.first_command)){
                ;
            } else if (!strcmp("voltar", command.first_command)){
                *gaming = 1;
                break;
            }
        }

        int winner  = check_winner(game);
        if (winner){
            print_game_table(*game);
            if(winner == 1){
                printf("\n\t\t\t\t\t"ANSI_BOLD ANSI_COLOR_RED "Parabéns %s, você ganhou!",game->player1);
            } else {
                printf("\n\t\t\t\t\t"ANSI_BOLD ANSI_COLOR_RED "Parabéns %s, você ganhou!",game->player1);
            }

            printf(BOLD(BLUE("\n\t\t\t\t\tDigite qualquer tecla para continuar!\n")));
            getchar();
            clear_screen();
            break;
        }

    }

}


Command get_commands(Game game){

    char command[3 * STR_SIZE];
    int invalid_command = 0;
    Command current_command;

    do{

        if (game.last_play == 2){
            printf(ANSI_BOLD ANSI_COLOR_BLUE "\n\n\n\n\t\t\t\t %s, digite o comando: ", game.player1);
        } else {
            printf(ANSI_BOLD ANSI_COLOR_BLUE "\n\n\n\n\t\t\t\t %s, digite o comando: ", game.player2);
        }


        invalid_command = 0;
        fgets(command, 3*STR_SIZE, stdin);
        strcpy(command, remove_new_line(command));

        int str_len = strlen(command);
        int second_command_index = 0;


        for ( int i = 0; i < str_len; i++){
            
            current_command.first_command[i] = command[i];

            if (command[i] == ' '){
                current_command.first_command[i] = '\0';
                second_command_index = i;
                break;
            }
        }

        current_command.first_command[str_len] = '\0';

        int second_command_counter = 0;
        for ( int i = second_command_index + 1; i < str_len; i ++){
            current_command.second_command[second_command_counter] = command[i]; 
            second_command_counter++;
        }

        current_command.second_command[str_len - second_command_index - 1] = '\0'; // TOMAR CUIDADO PODE DAR MERDA


        if (!strcmp(current_command.first_command, "marcar")){
            for ( int i = 0; i < 3; i++){
                for ( int j = 0; j < 3; j++){
                    if((game.board[i][j] == 'O' && game.last_play == '1') || 
                    (game.board[i][j] == 'X' && game.last_play == '2') ){
                        invalid_command++;
                    }
                }
            }

            if(!(!strcmp(current_command.second_command, "11") ||
                !strcmp(current_command.second_command, "12") ||
                !strcmp(current_command.second_command, "13") ||
                !strcmp(current_command.second_command, "21") ||
                !strcmp(current_command.second_command, "22") ||
                !strcmp(current_command.second_command, "23") ||
                !strcmp(current_command.second_command, "31") ||
                !strcmp(current_command.second_command, "32") ||
                !strcmp(current_command.second_command, "33"))){
                
                invalid_command++; // somando 1 aqui

                }
                
        }else if(!strcmp(current_command.first_command, "salvar")){
            int second_command_lenght = strlen(current_command.second_command);

            if(!(current_command.second_command[second_command_lenght - 1] == 't')){
                invalid_command++;

            }
            if(!(current_command.second_command[second_command_lenght - 2] == 'x')){
                invalid_command++;
                
            }
            if(!(current_command.second_command[second_command_lenght - 3] == 't')){
                invalid_command++;
            }
        } else if (!strcmp(current_command.first_command, "voltar")){
            ;
        } else{
            invalid_command++;
        }

        if (invalid_command){
            printf(BOLD(RED("\n\t\t\t\t\tComando inválido. Digite novamente")));
        }

    } while (invalid_command);

    return current_command;

}
    


void make_move(Game *game, Command command){

    int x = command.second_command[0] - 49;
    int y = command.second_command[1] - 49;

    if (game->last_play == 2){  

        if ( game->board[x][y] == 'X' || game->board[x][y] == 'O'){
            printf(BOLD(RED("\n\t\t\t\t\tPosição já marcada")));
        } else {
            game->board[x][y] = 'X';
            game->last_play = 1;
        }

    }else {

        if (!strcmp(game->player2, "Computador")){
            ;
        } else {
            
            if ( game->board[x][y] == 'X' || game->board[x][y] == 'O'){
                printf(BOLD(RED("\n\t\t\t\t\tPosição já marcada")));
            } else {
                game->board[x][y] = 'O';
                game->last_play = 2;
            }
   
        }
    }
}




int check_winner(Game *game){
    
    int x_counter = 0;
    int o_counter  = 0;

    //checar vencedor linhas
    for (int i = 0; i < 3; i++){
        x_counter = 0;
        o_counter  = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[i][j] == 'X'){
                x_counter++;
            } else if (game->board[i][j] == 'O'){
                o_counter++;
            }
        }
        if (x_counter >= 3){
            return 1;
        } else if (o_counter >= 3){
            return 2;
        }
    }

    //checar vencedor colunas
    for (int i = 0; i < 3; i++){
        x_counter = 0;
        o_counter  = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[j][i] == 'X'){
                x_counter++;
            } else if (game->board[i][j] == 'O'){
                o_counter++;
            }
        }

        if (x_counter >= 3){
            return 1;
        } else if (o_counter >= 3){
            return 2;
        }
    }


    //checar vencedor diagonal principal

    x_counter = 0;
    o_counter  = 0;

    for (int i = 0; i < 3; i++){
        if (game->board[i][i] == 'X'){
            x_counter++;
        } else if (game->board[i][i] == 'O'){
            o_counter++;
        }
    }

    if (x_counter >= 3){
        return 1;
    } else if (o_counter >= 3){
        return 2;
    }



    //checar vencedor diagonal secundária
    x_counter = 0;
    o_counter  = 0;

    for (int i = 0; i < 3; i++){
        if (game->board[i][2 - i] == 'X'){
            x_counter++;
        } else if (game->board[i][2 - i] == 'O'){
            o_counter++;
        }
    }

    if (x_counter >= 3){
        return 1;
    } else if (o_counter >= 3){
        return 2;
    }

    
    return 0;
}


