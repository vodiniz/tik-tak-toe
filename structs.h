#include "defines.h"
#ifndef STRUCTS_H_
#define STRUCTS_H_


typedef struct {
    int player_count;
    char player1[STR_SIZE]; // pode mudar para Person
    char player2[STR_SIZE]; // pode mudar para Person
    char board[3][3];
    int last_play;
} Game;




typedef struct {
    char name[50];
    int wins;
    int losses;
    int draws;
} Person;

#endif