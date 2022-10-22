#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_

void game_loop(Game *game, int *gaming);
Command get_commands(Game game);
void make_move(Game *game, Command command);
int check_winner(Game *game);


#endif