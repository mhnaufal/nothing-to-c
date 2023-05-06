#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const size_t BOARD_COLS = 3;
const size_t BOARD_ROWS = 3;
const char PLAYER = 'O';
const char ENEMY = 'X';

void reset_board();
void print_board();
void player_turn();
void enemy_turn();
char check_winner(char winner);
int show_winner(char winner);
