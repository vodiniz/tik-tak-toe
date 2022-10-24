#include "defines.h"

#ifndef STRUCTS_H_
#define STRUCTS_H_


//game struct for game control
typedef struct {
    int player_count;
    char player1[STR_SIZE];
    char player2[STR_SIZE]; 
    char board[3][3];
    int last_play;
} Game;


//person struct for ranking control
typedef struct {
    char name[50];
    int wins;
    int losses;
    int draws;
} Person;


//command struct for validating commands
typedef struct {
    char first_command[STR_SIZE];
    char second_command[STR_SIZE];
} Command;


#endif