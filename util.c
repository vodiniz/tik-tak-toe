//Vitor Oliveira Diniz
//22.1.4107


#include <stdio.h>
#include <string.h>
#include "structs.h"



//check file exists return 1 if so
int file_exists(const char * filename){
    FILE *file;
    if ((file = fopen(filename, "r"))){

        fclose(file);
        return 1;
    }
    return 0;
}



//fill board with -
void empty_board(char board[][3]){

    for( int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}


//change string last position from \n to \0
char* remove_new_line(char *string){

    int str_len = strlen(string);

    string[str_len - 1] = '\0';

    return string;
}


//fill string with \0
void empty_string(char* string){
    int str_len = strlen(string);
    for ( int i = 0; i < str_len; i++){
        string[i] = '\0';
    }
}


//simple sorting of ranking based on wins and then draws
void sort_ranking(Person* list, int list_size){

    //sort wins
    for (int i = 0; i < list_size; i++){
        for (int j = 0; j < list_size; j++){
            if (list[j].wins < list[i].wins){

                Person tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }

    //sort draws

    for (int i = 0; i < list_size; i++){
        for (int j = 0; j < list_size; j++){
            if(list[j].wins == list[i].wins){
                if (list[j].draws < list[i].draws){
                    Person tmp = list[i];
                    list[i] = list[j];
                    list[j] = tmp;
                }
            }
        }
    }
}


//simple ranking printing for debbuging
void print_simple_ranking(Person* list, int list_size){

    printf("\n-------RANK SIMPLES--------\n");
    for (int i = 0; i < list_size; i++){
        printf("\n|%s|   |%d %d %d|",list[i].name, list[i].wins, list[i].draws, list[i].losses);
    }
    printf("\n---------------\n");
}