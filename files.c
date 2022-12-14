//Vitor Oliveira Diniz
//22.1.4107


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "defines.h"
#include "structs.h"



//save game on .txt file
void save_game(Game current_game, char file_name[]){

    FILE *save_file = fopen(file_name, "w");
    fprintf(save_file, "%d\n", current_game.player_count);
    fprintf(save_file, "%s\n", current_game.player1);
    fprintf(save_file, "%s\n", current_game.player2);

    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            fprintf(save_file, "%c", current_game.board[i][j]);
            if (j < 2){
                fprintf(save_file," ");
            }
        }
        fprintf(save_file, "\n");

    }
    fprintf(save_file, "%d\n", current_game.last_play);
    fclose(save_file);
}





//load save from .txt file
Game read_save(char file_name[]){

    if (file_exists(file_name)){

        FILE *save_file = fopen(file_name, "r");

        Game save_game;

        fscanf(save_file, "%d", &save_game.player_count);
        fgetc(save_file);
        if(save_game.player_count == 1){
            fgets(save_game.player1, STR_SIZE, save_file);
            save_game.player2[0] = ' ';
        } else {
            fgets(save_game.player1, STR_SIZE, save_file);
            save_game.player1[strlen(save_game.player1) - 1] = '\0';

            fgets(save_game.player2, STR_SIZE, save_file);
            save_game.player2[strlen(save_game.player2) - 1] = '\0';

        }

        for ( int i = 0; i < 3; i++){
            for ( int j = 0; j < 3; j++){
                fscanf(save_file, "%c", &save_game.board[i][j]);
                if ( j < 2){
                    fgetc(save_file);
                }
            }
            fgetc(save_file);
        }


    
        fscanf(save_file, "%d", &save_game.last_play);
        fclose(save_file);

        return save_game;    
        
    } else {
        printf(BOLD(RED("\n\n\t\t\t\tArquivo não existe. Tente novamente\n")));
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






//read ranking from file and return Person list
Person* read_ranking(int *list_size){

    Person *person_list;
    *list_size = 0;

    if (file_exists(RANKING_FILE)){


        FILE *ranking_file = fopen(RANKING_FILE, "r");
        fscanf(ranking_file, "%d", list_size);

        person_list = malloc ( *list_size * sizeof(Person));

        for (int i = 0; i < *list_size; i++){


            Person new_person;

            fgetc(ranking_file);
            fgets(new_person.name, STR_SIZE, ranking_file);
            
            int string_size = strlen(new_person.name);
            new_person.name[string_size - 1] = '\0';

            fscanf(ranking_file, "%d", &new_person.wins);
            fscanf(ranking_file, "%d", &new_person.draws);
            fscanf(ranking_file, "%d", &new_person.losses);

            person_list[i] = new_person;
        }
        //printf("NOME = %s\n", ranking_list[4].name);

        fclose(ranking_file);
    } else {
        printf(RED(BOLD("ARQUIVO NÃO EXISTE!\n")));
        person_list = malloc ( 1 * sizeof(Person));
    }

    return person_list;
}



//write Person list on velha.ini file
void save_ranking(char *player_name, char op){


    int list_size = 0;
    int new_list_size = 0;

    int is_on_rank = 0;

    Person *rank_list = read_ranking(&list_size);
    new_list_size = list_size + 1;
    Person *new_list = malloc ((new_list_size) * sizeof(Person));


    for( int i = 0; i < list_size; i++){
        if(!strcmp(player_name, rank_list[i].name)){
            is_on_rank++;
            switch (op){
                case 'w':
                    rank_list[i].wins++;
                    break;
                case 'd':
                    rank_list[i].draws++;
                    break;
                case 'l':
                    rank_list[i].losses++;
                    break;
                default:
                    break;
            }
        }
    }

    sort_ranking(rank_list, list_size);

    if (!is_on_rank){
        for( int i = 0; i < list_size; i++){
            new_list[i] = rank_list[i];
        }
        
        Person new_entry;

        strcpy(new_entry.name, player_name);
        new_entry.wins = 0;
        new_entry.draws = 0;
        new_entry.losses = 0;
        
        switch (op){
            case 'w':
                new_entry.wins++;
                break;
            case 'd':
                new_entry.draws++;
                break;
            case 'l':
                new_entry.losses++;
                break;
            default:
                break;
        }

        new_list[new_list_size - 1] = new_entry;
    }

    sort_ranking(new_list, new_list_size);


    for( int i = 0; i < list_size; i++){
        if (!strcmp(new_list[i].name, "Computador")){
            if ( i > 9){
                sort_ranking(new_list, new_list_size);
                new_list[9] = new_list[i];
            }
        }
    }

    if (list_size > 10){
        list_size = 10;
    } 

    if (new_list_size > 10){
        new_list_size = 10;
    } 

    FILE *rank = fopen("velha.ini","w"); 


    if(is_on_rank){

        fprintf(rank, "%d", list_size);
        for( int i = 0; i < list_size; i++){
            fprintf(rank,"\n%s\n", rank_list[i].name);
            fprintf(rank,"%d %d %d", rank_list[i].wins, rank_list[i].draws, rank_list[i].losses);
        }

    } else {
        fprintf(rank, "%d", new_list_size);
        
        for( int i = 0; i < new_list_size; i++){
            fprintf(rank,"\n%s\n", new_list[i].name);
            fprintf(rank,"%d %d %d", new_list[i].wins, new_list[i].draws, new_list[i].losses);       
        }
    }


    fclose(rank);
    free(rank_list); //free erro
    free(new_list);

}

