#include "tic.h"
#include <assert.h>

char BOARD[BOARD_ROWS][BOARD_COLS];

int main(int argc, char *argv[]) {

  // Main Menu
  printf("Welcome to Toe-Tac-Tic!\n");
  printf("Press \"Y\" to start playing or \"Q\" to quit\n");

  char is_menu_playing = 'Q';
  scanf_s("%c", &is_menu_playing);
  if (toupper(is_menu_playing) != 'Y') {
    return EXIT_SUCCESS;
  }

  // Print Board
  reset_board();
  print_board();

  // Player Turn & Check for winner
  player_turn();
  print_board();

  // Enemy Turn & Check for winner
  enemy_turn();
  print_board();

  return EXIT_SUCCESS;
}

void reset_board() {
  for (int i = 0; i < BOARD_ROWS; ++i) {
    for (int j = 0; j < BOARD_COLS; ++j) {
      BOARD[i][j] = ' ';
    }
  }
}

void print_board() {
  printf("\n");
  printf(" %c | %c | %c \n", BOARD[0][0], BOARD[0][1], BOARD[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", BOARD[1][0], BOARD[1][1], BOARD[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", BOARD[2][0], BOARD[2][1], BOARD[2][2]);
}

void player_turn() {
  int player_row, player_col;

  do {
    printf("PLAYER: Enter row number (1-3): ");
    scanf_s("%d", &player_row);

    printf("PLAYER: Enter column number (1-3): ");
    scanf_s("%d", &player_col);

    assert(player_row <= 3 && player_row >= 1);
    assert(player_col <= 3 && player_col >= 1);

    player_row--;
    player_col--;

    if (BOARD[player_row][player_col] == ' ') {
      BOARD[player_row][player_col] = PLAYER;
      break;
    } else {
      printf("Board already filled, try another row and col!\n");
    }
  } while (BOARD[player_row][player_col] != ' ');

  // check winner
}

void enemy_turn() {
  int enemy_row, enemy_col;

  do {
    printf("ENEMY: Enter row number (1-3): ");
    scanf_s("%d", &enemy_row);

    printf("ENEMY: Enter col number (1-3): ");
    scanf_s("%d", &enemy_col);
    enemy_row--;
    enemy_col--;

    assert(enemy_row <= 3 && enemy_row >= 1);
    assert(enemy_col <= 3 && enemy_col >= 1);

    if (BOARD[enemy_row][enemy_col] == ' ') {
      BOARD[enemy_row][enemy_col] = ENEMY;
      break;
    } else {
      printf("Board already filled, try another row and col!\n");
    }
  } while (BOARD[enemy_row][enemy_col] != ' ');

  // check winner
}

void check_winner();
