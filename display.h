#include <stdio.h>
#include "defines.h"
#include "structs.h"

#define RANKING_FILE "velha.ini"


void clear_screen();
void display_game_name();
void display_options(int ongoing_game);
void invalid_option();
void show_ranking();









void clear_screen(){
    printf("\e[1;1H\e[2J");
}



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


}

void invalid_option(){
    printf("\n\n");
    printf((BLUE(BOLD("\t\t\tOPÇÃO INVÁLIDA.\n\n"))));
}

void show_ranking(){

    if (file_exists(RANKING_FILE)){

        int list_size;
        FILE *ranking_file = fopen(RANKING_FILE, "r");
        fscanf(ranking_file, "%d", &list_size);

        printf("\t\t\t\t\t\t%s"TAB_TL);
    }



}