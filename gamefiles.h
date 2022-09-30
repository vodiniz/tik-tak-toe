#include <stdio.h>
#include "util.h"
#define STR_SIZE 50

typedef struct {
    int player_count;
    char player1[STR_SIZE];
    char player2[STR_SIZE];
    char board[3][3];
    int last_play;
} Game;




void save_game(Game current_game, char file_name[]);
Game read_save(char save_name[]);


























void save_game(Game current_game, char file_name[]){

    FILE *save_file = fopen(file_name, "w");
    fprintf(save_file, "%d\n", current_game.player_count);
    fprintf(save_file, "%s\n", current_game.player1);
    fprintf(save_file, "%s\n", current_game.player2);

    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            fprintf(save_file, "%c", current_game.board[i][j]);
        }
        fprintf(save_file, "\n");

    }
    fprintf(save_file, "%d\n", current_game.last_play);
    fclose(save_file);
}


Game read_save(char file_name[]){


    if (file_exists(file_name)){

        FILE *save_file = fopen(file_name, "r");

        Game save_game;

        fscanf(save_file, "%d", &save_game.player_count);
        
        if(save_game.player_count == 1){
            fscanf(save_file, "%s", save_game.player1);
            save_game.player2[0] = ' ';
        } else {
            fscanf(save_file, "%s", save_game.player1);
            fscanf(save_file, "%s", save_game.player2);
        }

        for ( int i = 0; i < 3; i++){
            for ( int j = 0; j < 3; j++){
                fscanf(save_file, "%c", &save_game.board[i][j]);
            }
        }
    
        fscanf(save_file, "%d", &save_game.last_play);
        fclose(save_file);

        return save_game;    
        
    } else {
        printf("File doesn't exist\n");
        Game default_game = {
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

        return default_game;
    }
}