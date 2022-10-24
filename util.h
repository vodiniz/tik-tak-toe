//Vitor Oliveira Diniz
//22.1.4107


#ifndef UTIL_H_
#define UTIL_H_

#include "structs.h"

int file_exists(const char *filename);
char* remove_new_line(char *string);
void empty_board(char board[][3]);
void empty_string(char* string);
void sort_ranking(Person* list, int list_size);
void print_simple_ranking(Person* list, int list_size);


#endif
