#include "tic.h"
#include <assert.h>
#include <stdio.h>

char BOARD[BOARD_ROWS][BOARD_COLS];

int main(int argc, char *argv[]) {
  printf("\n\n");
  printf("      ,-'``_.-'` \\   / `'-._``'-. \n");
  printf("    ,`   .'      |`-'|      `.   `. \n");
  printf("  ,`    (    /\\  |   |  /\\    )    `. \n");
  printf(" /       `--'  `-'   `-'  `--'       \\ \n");
  printf(" |                                   | \n");
  printf(" \\      .--.  ,--.   ,--.  ,--.     / \n");
  printf("  `.   (       \\/\\ / /\\/     )   ,' \n");
  printf("   `._ `--.___    V    ___.--' _,' \n");
  printf("      `'----'`         `'----'` \n");
  printf("\n");

  printf("Welcome to Toe-Tac-Tic!\n");
  printf("Press \"Y\" to start playing or \"Q\" to quit\n");

  char is_menu_playing = 'Q';
  scanf_s("%c", &is_menu_playing);
  if (toupper(is_menu_playing) != 'Y') {
    return EXIT_SUCCESS;
  }

  reset_board();
  char winner = ' ';

  game_loop(winner);

  return EXIT_SUCCESS;
}

void game_loop(char winner) {
  do {
    print_board();
    player_turn();
    winner = check_winner(PLAYER);
    if (winner == PLAYER) {
      print_board();
      show_winner(winner);

      printf("Do you want to play again? \"Y\" or \"N\": \n");
      char is_again = 'N';
      scanf_s(" %c", &is_again); // watch out with the space!

      if (toupper(is_again) == 'Y') {
        winner = ' ';
        reset_board();
        continue;
      } else {
        break;
      }
    }

    print_board();
    enemy_turn();
    winner = check_winner(ENEMY);
    if (winner == ENEMY) {
      print_board();
      show_winner(winner);

      printf("Do you want to play again? \"Y\" or \"N\": \n");
      char is_again = 'N';
      scanf_s(" %c", &is_again); // watch out with the space!

      if (toupper(is_again) == 'Y') {
        winner = ' ';
        reset_board();
        continue;
      } else {
        break;
      }
    }

  } while (winner == ' ');
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

    player_row--;
    player_col--;

    assert(player_row <= 2 && player_row >= 0);
    assert(player_col <= 2 && player_col >= 0);

    if (BOARD[player_row][player_col] == ' ') {
      BOARD[player_row][player_col] = PLAYER;
      break;
    } else {
      printf("\nBoard already filled, try another row and col!\n");
    }
  } while (BOARD[player_row][player_col] != ' ');
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

    assert(enemy_row <= 2 && enemy_row >= 0);
    assert(enemy_col <= 2 && enemy_col >= 0);

    if (BOARD[enemy_row][enemy_col] == ' ') {
      BOARD[enemy_row][enemy_col] = ENEMY;
      break;
    } else {
      printf("\nBoard already filled, try another row and col!\n");
    }
  } while (BOARD[enemy_row][enemy_col] != ' ');
}

char check_winner(char winner) {
  // Checking rows
  if (BOARD[0][0] == winner && BOARD[0][0] == BOARD[0][1] &&
      BOARD[0][0] == BOARD[0][2]) {
    return winner;
  } else if (BOARD[1][0] == winner && BOARD[1][0] == BOARD[1][1] &&
             BOARD[1][0] == BOARD[1][2]) {
    return winner;
  } else if (BOARD[2][0] == winner && BOARD[2][0] == BOARD[2][1] &&
             BOARD[2][0] == BOARD[2][2]) {
    return winner;
  }
  // Checking cols
  else if (BOARD[0][0] == winner && BOARD[0][0] == BOARD[1][0] &&
           BOARD[0][0] == BOARD[2][0]) {
    return winner;
  } else if (BOARD[0][1] == winner && BOARD[0][1] == BOARD[1][1] &&
             BOARD[0][1] == BOARD[2][1]) {
    return winner;
  } else if (BOARD[0][2] == winner && BOARD[0][2] == BOARD[1][2] &&
             BOARD[0][2] == BOARD[2][2]) {
    return winner;
  }
  // Checking diagonals
  else if (BOARD[0][0] == winner && BOARD[0][0] == BOARD[1][1] &&
           BOARD[0][0] == BOARD[2][2]) {
    return winner;
  } else if (BOARD[0][2] == winner && BOARD[0][2] == BOARD[1][1] &&
             BOARD[0][2] == BOARD[2][0]) {
    return winner;
  }

  return ' ';
}

int show_winner(char winner) {
  if (winner == PLAYER) {
    printf("+------------------+\n");
    printf("| $_$ Player wins! |\n");
    printf("+------------------+\n\n");
  } else {
    printf("+------------------+\n");
    printf("| *_* Enemy wins! |\n");
    printf("+------------------+\n\n");
  }
}
