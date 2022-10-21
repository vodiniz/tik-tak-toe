
#ifndef DISPLAY_H_
#define DISPLAY_H_


void clear_screen();
void display_game_name();
void display_options(int ongoing_game);
void print_ranking_title();
void print_n_times(int n, char string[]);
void print_table_space_line();
void print_table_horizontal_lines();
void print_person_table(int n_lines, Person players[]);
void invalid_option();
void show_ranking();
char *player_char_color(char letter);
void print_game_table(Game game);

#endif