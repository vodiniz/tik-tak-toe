#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bot.h"
#include "structs.h"



Command bot_movement(Game *game){

    srand(time(NULL));

    Command bot_move = {"marcar", ""};

    int x_counter = 0;
    int o_counter  = 0;

    //-------------------------------------RESPOSTA MOVIMENTO INICIAL-------------------------

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (game->board[i][j] == 'X'){
                x_counter++;
            } else if (game->board[i][j] == 'O'){
                o_counter++;
            }
        }
    }

    if (x_counter == 1 && game->board[1][1] == '-'){
        strcpy(bot_move.second_command, "22");
        return bot_move;
    } else if (x_counter == 1 && game->board[1][1] == 'X'){
        int random = rand() % 4;
        switch (random){
        case 0:
            strcpy(bot_move.second_command, "11");
            break;

        case 1:
            strcpy(bot_move.second_command, "13");
            break;

        case 2:
            strcpy(bot_move.second_command, "31");
            break;

        case 3:
            strcpy(bot_move.second_command, "33");
            break;

        default:
            break;
        }

        return bot_move;

    } 

    //-----------------------CHECAR SE VAI GANHAR -------------------



    //checar se vai ganhar nas linhas

    o_counter  = 0;
    for (int i = 0; i < 3; i++){
        o_counter  = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[i][j] == 'O'){
                o_counter++;
            }
        }

        if (o_counter == 2){
            for (int j = 0; j < 3; j++){
                if (game->board[i][j] == '-'){
                    sprintf(bot_move.second_command, "%d%d", i + 1, j + 1);
                    return bot_move;
                }
            }
        }
        
    }


    //checar se vai ganhar nas colunas
    o_counter  = 0;

    for (int i = 0; i < 3; i++){
        o_counter  = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[j][i] == 'O'){
                o_counter++;
            }
        }
        if (o_counter == 2){
            for (int j = 0; j < 3; j++){
                if (game->board[j][i] == '-'){
                    sprintf(bot_move.second_command, "%d%d", j + 1, i + 1);
                    return bot_move;
                }
            }
        }
    }

    //checar se vai ganhar NA  diagonal principal
    o_counter  = 0;
    for (int i = 0; i < 3; i++){
        if (game->board[i][i] == 'O'){
            o_counter++;
        }
    }

    if (o_counter == 2){
        for (int i = 0; i < 3; i++){
            if (game->board[i][i] == '-'){
                sprintf(bot_move.second_command, "%d%d", i + 1, i + 1);
                return bot_move;
            }
        }
    }

    //checar se vai ganhar na diagonal secundária
    o_counter  = 0;

    for (int i = 0; i < 3; i++){
        if (game->board[i][2 - i] == 'O'){
            o_counter++;
        }
    }

    if (o_counter == 2){
        for (int i = 0; i < 3; i++){
            if (game->board[i][2 - i] == '-'){
                sprintf(bot_move.second_command, "%d%d", i + 1, 3 - i);
                return bot_move;
            }
        }
    }


    //---------------------------------CHECAR SE VAI PERDER ------------------------------
    //checar se vai se vai perder de X nas linhas
    for (int i = 0; i < 3; i++){
        x_counter = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[i][j] == 'X'){
                x_counter++;
            }
        }
        if (x_counter == 2){
            for (int j = 0; j < 3; j++){
                if (game->board[i][j] == '-'){
                    sprintf(bot_move.second_command, "%d%d", i + 1, j + 1);
                    return bot_move;
                }
            }
        }
        
    }

    //checar se vai se vai perder de X nas colunas
    x_counter = 0;

    for (int i = 0; i < 3; i++){
        x_counter = 0;
        for (int j = 0; j < 3; j++){
            if (game->board[j][i] == 'X'){
                x_counter++;
            }
        }
        if (x_counter == 2){
            for (int j = 0; j < 3; j++){
                if (game->board[j][i] == '-'){
                    sprintf(bot_move.second_command, "%d%d", j + 1, i + 1);
                    return bot_move;
                }
            }
        }
    }

    //checar se vai se vai perder de X na diagonal principal
    x_counter = 0;
    o_counter  = 0;
    for (int i = 0; i < 3; i++){
        if (game->board[i][i] == 'X'){
            x_counter++;
        }
    }

    if (x_counter == 2){
        for (int i = 0; i < 3; i++){
            if (game->board[i][i] == '-'){
                sprintf(bot_move.second_command, "%d%d", i + 1, i + 1);
                return bot_move;
            }
        }
    }

    //checar se vai se vai perder de X na diagonal secundária
    x_counter = 0;
    o_counter  = 0;

    for (int i = 0; i < 3; i++){
        if (game->board[i][2 - i] == 'X'){
            x_counter++;
        }
    }

    if (x_counter == 2){
        for (int i = 0; i < 3; i++){
            if (game->board[i][2 - i] == '-'){
                sprintf(bot_move.second_command, "%d%d", i + 1, 3 - i);
                return bot_move;
            }
        }
    }


    //tratar aqui tá faltando evitar de perder se o player marca nos opostos
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (game->board[i][j] == '-'){
                sprintf(bot_move.second_command, "%d%d", i + 1, j + 1);
                return bot_move;
            }
        }
    }

    strcpy(bot_move.second_command, "33");

    return bot_move;


}