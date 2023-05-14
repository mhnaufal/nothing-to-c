#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

int const HEIGHT = 10;
int const WIDTH = 20;
static char BOARD[HEIGHT][WIDTH];
int PLAYER_X = (HEIGHT / 2) - 1;
int PLAYER_Y = (WIDTH / 2) - 1;

char const HEAD = 'X';
char const UPWARD = '^';
char const DOWNWARD = 'v';
char const RIGHT = '>';
char const LEFT = '<';

int score = 0;
char move;

void init_board();
void display_board();
void movement();