#include <stdio.h>
#include <string.h>

int file_exists(const char *filename);
char* remove_new_line(char *string);
void empty_board(char board[][3]);












int file_exists(const char * filename){
    FILE *file;
    if ((file = fopen(filename, "r"))){

        fclose(file);
        return 1;
    }

    return 0;
}


void empty_board(char board[][3]){

    for( int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}




char* remove_new_line(char *string){

    int str_len = strlen(string);

    string[str_len - 1] = '\0';

    return string;
}