#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
#include "defines.h"
#include "structs.h"
#include "display.h"
#include "files.h"
#include <math.h>



//clear screen with regex
void clear_screen(){
    printf("\e[1;1H\e[2J");
}


//game initial art
void display_game_name(){
    
    clear_screen();
    printf("\n\n\n\n");
    printf(MAGENTA(BOLD("\t\t     ▄█  ▄██████▄     ▄██████▄   ▄██████▄       ████████▄     ▄████████       ▄█    █▄     ▄████████  ▄█          ▄█    █▄       ▄████████ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███   ███    ███ ███    ███      ███   ▀███   ███    ███      ███    ███   ███    ███ ███         ███    ███     ███    ███ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███   ███    █▀  ███    ███      ███    ███   ███    ███      ███    ███   ███    █▀  ███         ███    ███     ███    ███ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███  ▄███        ███    ███      ███    ███   ███    ███      ███    ███  ▄███▄▄▄     ███        ▄███▄▄▄▄███▄▄   ███    ███ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███ ▀▀███ ████▄  ███    ███      ███    ███ ▀███████████      ███    ███ ▀▀███▀▀▀     ███       ▀▀███▀▀▀▀███▀  ▀███████████ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███   ███    ███ ███    ███      ███    ███   ███    ███      ███    ███   ███    █▄  ███         ███    ███     ███    ███ \n")));
    printf(MAGENTA(BOLD("\t\t    ███ ███    ███   ███    ███ ███    ███      ███   ▄███   ███    ███      ███    ███   ███    ███ ███▌    ▄   ███    ███     ███    ███ \n")));
    printf(MAGENTA(BOLD("\t\t█▄ ▄███  ▀██████▀    ████████▀   ▀██████▀       ████████▀    ███    █▀        ▀██████▀    ██████████ █████▄▄██   ███    █▀      ███    █▀  \n")));
    printf(MAGENTA(BOLD("\t\t▀▀▀▀▀▀                                                                                               ▀                                     \n")));
    printf("\n");
}


//display game options
void display_options(int ongoing_game){

    printf("\n\n\n\n\n");
    printf((BLUE(BOLD("\t\t\t0. Sair.\n\n"))));
    printf((BLUE(BOLD("\t\t\t1. Começar um jogo novo.\n\n"))));
    printf((BLUE(BOLD("\t\t\t2. Continuar um jogo salvo.\n\n"))));
    if (ongoing_game){
        printf((BLUE(BOLD("\t\t\t3. Voltar para o jogo em andamento.\n\n"))));
    } else {
        printf((BLACK(BOLD("\t\t\t3. Voltar para o jogo em andamento.\n\n"))));
    }
    
    printf((BLUE(BOLD("\t\t\t4. Exibir o ranking.\n\n"))));
    printf(GREEN(BOLD("\n\t\t\tDurante o jogo digite “voltar” para retornar ao menu.\n\n")));


}

//print invalid option
void invalid_option(){
    printf("\n\n");
    printf((BLUE(BOLD("\t\t\tOPÇÃO INVÁLIDA.\n\n"))));
}

//repeat same string n times
void print_n_times(int n, char string[]){
    for (int i = 0; i < n; i++){
        printf("%s", string);
    }
}

//print empty spaces inside table line
void print_table_space_line(){
    printf("\t\t\t\t\t\t");
    printf("%*c" RED(BOLD(TAB_VER)), 6, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 20, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 16, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 15, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 16, ' ');

}


//print table with horizontal lines
void print_table_horizontal_lines(){

    printf("\n\t\t\t\t\t\t");

    //TAB NUMEROS
    print_n_times(6, RED(BOLD(TAB_HOR)));
    printf(RED(BOLD(TAB_MJ)));

    //TAB NOMES
    print_n_times(20, RED(BOLD(TAB_HOR)));
    printf(RED(BOLD(TAB_MJ)));

    //TAB VITORIAS
    print_n_times(16, RED(BOLD(TAB_HOR)));
    printf(RED(BOLD(TAB_MJ)));

    //TAB EMPATES
    print_n_times(15, RED(BOLD(TAB_HOR)));
    printf(RED(BOLD(TAB_MJ)));

    //TAB DERROTAS
    print_n_times(16, RED(BOLD(TAB_HOR)));
    printf(RED(BOLD(TAB_MJ)));

    print_n_times(6, RED(BOLD(TAB_HOR)));
    printf("\n");

    
}


//printf persone name inside table
void print_person_table(int n_lines, Person *players){

    
    printf("%*c" RED(BOLD(TAB_VER)), 54, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 20, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 16, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 15, ' ');
    printf("%*c" RED(BOLD(TAB_VER)), 16, ' ');



    for ( int i = 0; i < n_lines; i++){

        //printf("NAME: %s\n", players[i].name);
        int name_size = strlen(players[i].name);
        printf("\n");
        printf("%50d.   "RED(BOLD(TAB_VER)), i+1);

        printf("%*c", (int)ceil((double) (20 - name_size)/2), ' ');
        printf("%s", players[i].name);
        printf("%*c", (int)ceil((double)(20 - name_size))/2, ' ');
        printf(RED(BOLD(TAB_VER)));

        if (players[i].wins > 9){

            printf("%*c", 8 , ' ');
            printf("%d", players[i].wins);
            printf("%*c", 8 , ' ');

        } else {
            printf("%*c", 8 , ' ');
            printf("%d", players[i].wins);
            printf("%*c", 7 , ' ');
        }

        printf(RED(BOLD(TAB_VER)));


        if (players[i].draws > 9){

            printf("%*c", 8 , ' ');
            printf("%d", players[i].draws);
            printf("%*c", 7 , ' ');

        } else {
            printf("%*c", 7 , ' ');
            printf("%d", players[i].draws);
            printf("%*c", 7 , ' ');
        }

        printf(RED(BOLD(TAB_VER)));

        
        if (players[i].losses > 9){

            printf("%*c", 8 , ' ');
            printf("%d", players[i].losses);
            printf("%*c", 8 , ' ');

        } else {
            printf("%*c", 7 , ' ');
            printf("%d", players[i].losses);
            printf("%*c", 8 , ' ');
        }
        
        printf(RED(BOLD(TAB_VER)));
        printf("\n");
        printf("    ");
        print_table_space_line();
        print_table_horizontal_lines();
        print_table_space_line();

    }
}





//print ranking art
void print_ranking_title(){
    printf(MAGENTA(BOLD("\t\t\t\t\t\t\t██████   █████  ███    ██ ██   ██ ██ ███    ██  ██████  \n")));
    printf(MAGENTA(BOLD("\t\t\t\t\t\t\t██   ██ ██   ██ ████   ██ ██  ██  ██ ████   ██ ██       \n")));
    printf(MAGENTA(BOLD("\t\t\t\t\t\t\t██████  ███████ ██ ██  ██ █████   ██ ██ ██  ██ ██   ███ \n")));
    printf(MAGENTA(BOLD("\t\t\t\t\t\t\t██   ██ ██   ██ ██  ██ ██ ██  ██  ██ ██  ██ ██ ██    ██ \n")));
    printf(MAGENTA(BOLD("\t\t\t\t\t\t\t██   ██ ██   ██ ██   ████ ██   ██ ██ ██   ████  ██████  \n")));
    printf("\n");

}


//main show ranking function
void show_ranking(){


    if (file_exists(RANKING_FILE)){

        int list_size;
        FILE *ranking_file = fopen(RANKING_FILE, "r");
        
        Person *rank_list = read_ranking(&list_size);

        print_ranking_title();


        
        printf("\n\n\t\t\t\t\t\t      "BOLD(RED(TAB_VER)));
        printf(BOLD(MAGENTA("\t       NOME        ")));
        printf(BOLD(RED(TAB_VER)));


        printf(BOLD(MAGENTA("\tVITORIAS    ")));
        printf(BOLD(RED(TAB_VER)));


        printf(BOLD(MAGENTA("\t EMPATES    ")));
        printf(BOLD(RED(TAB_VER)));


        printf(BOLD(MAGENTA("\t DERROTAS    ")));
        printf(BOLD(RED(TAB_VER)));


        printf("\n\t\t\t\t\t\t");

        //TAB NUMEROS
        print_n_times(6, RED(BOLD(TAB_HOR)));
        printf(RED(BOLD(TAB_MJ)));

        //TAB NOMES
        print_n_times(20, RED(BOLD(TAB_HOR)));
        printf(RED(BOLD(TAB_MJ)));

        //TAB VITORIAS
        print_n_times(16, RED(BOLD(TAB_HOR)));
        printf(RED(BOLD(TAB_MJ)));

        //TAB EMPATES
        print_n_times(15, RED(BOLD(TAB_HOR)));
        printf(RED(BOLD(TAB_MJ)));

        //TAB DERROTAS
        print_n_times(16, RED(BOLD(TAB_HOR)));
        printf(RED(BOLD(TAB_MJ)));

        print_n_times(6, RED(BOLD(TAB_HOR)));

        printf("\n");

        print_person_table(list_size, rank_list);

        fclose(ranking_file);
        free(rank_list);

    }


}


//print X or O on choosen color
char* player_char_color(char letter){

    if (letter == '-'){
        return("   ");
    } else if (letter == 'X'){
        return(BLUE(" X "));
    } else {
        return(GREEN(" O "));
    }
    return("");
}



//print game_table
void print_game_table(Game game){

    printf("\n\n\n\n\n\n\n");
    printf ("\t\t\t\t\t\t"RED(TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TR) "\n");
    printf ("\t\t\t\t\t\t"RED(TAB_VER)BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER) "\n",
     player_char_color(game.board[0][0]), player_char_color(game.board[0][1]), player_char_color(game.board[0][2]));
    
    printf ("\t\t\t\t\t\t"RED(TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");
    printf ("\t\t\t\t\t\t"RED(TAB_VER) BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER) "\n",
     player_char_color(game.board[1][0]), player_char_color(game.board[1][1]), player_char_color(game.board[1][2]));

    printf ("\t\t\t\t\t\t"RED(TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");
    printf ("\t\t\t\t\t\t"RED(TAB_VER) BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER ) BLUE("%s") RED(TAB_VER) "\n",
     player_char_color(game.board[2][0]), player_char_color(game.board[2][1]), player_char_color(game.board[2][2]));

    printf ("\t\t\t\t\t\t"RED(TAB_BL TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BR) "\n");
    printf ("\n");  
    

}