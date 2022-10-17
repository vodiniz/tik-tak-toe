#include <stdio.h>
#include "files.h"
#include "display.h"


void run_game();
void test_game();
int get_option(int gaming);








void run_game (){

    int gaming = 0;
    display_game_name();
    int option;

    do{
        display_options(gaming);
        option = get_option(gaming);

        switch (option){
            case 1:
                //new_game
                break;
            case 2:
                //load game_file
                break;

            case 3:
                //
                //return_game();
            case 4: 
                //show_ranking
                show_ranking();
                break;

            default:
                break;
        }


    } while (option);
    
}




int get_option(int gaming){

    int option;
    printf("\n\t\t\t");
    scanf("%d", &option);

    if (!gaming && option == 3){
        invalid_option();
        option = 10;
    }
    
    return option;

}






void test_game (){
    Game current = {
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

    save_game(current, "testando.txt");
    read_save("testasndo.txt");
}