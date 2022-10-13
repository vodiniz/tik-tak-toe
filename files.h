#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "structs.h"
#define STR_SIZE 50
#define RANKING_FILE "velha.ini"





void save_game(Game current_game, char file_name[]);
Game read_save(char save_name[]);
void read_ranking(Person *ranking_list);





















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



void read_ranking(Person *ranking_list){

    if (file_exists(RANKING_FILE)){

        int list_size;
        FILE *ranking_file = fopen(RANKING_FILE, "r");
        fscanf(ranking_file, "%d", &list_size);

        ranking_list = malloc ( list_size * sizeof(Person));

        for (int i = 0; i < list_size; i++){

            Person new_person;
            
            fscanf(ranking_file, "%s", new_person.name);
            fscanf(ranking_file, "%d", &new_person.wins);
            fscanf(ranking_file, "%d", &new_person.draws);
            fscanf(ranking_file, "%d", &new_person.losses);

            ranking_list[i] = new_person;
        }


        fclose(ranking_file);

    }

}
