#include "snacke.h"

int main(int argc, char *argv[]) {

  printf("+-----------------------------+\n");
  printf("|      Let's play Snacke!     |\n");
  printf("|   You already hungry, huh?  |\n");
  printf("+-----------------------------+\n");
  printf("[Y] Play!\n");
  printf("[Q] QUIT!\n");
  printf("> ");

  char is_menu_playing = 'Q';
  scanf_s("%c", &is_menu_playing);
  if (toupper(is_menu_playing) != 'Y') {
    printf("Good Bye!\n\n");
    return EXIT_SUCCESS;
  }

  do {
    system("cls");

    init_board();
    display_board();

    movement();

  } while(score < 5);

  return EXIT_SUCCESS;
}

void init_board()
{
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      BOARD[i][j] = ' ';
    }
  }
  BOARD[PLAYER_X][PLAYER_Y] = HEAD;
}

void display_board()
{
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", BOARD[i][j]);
    }
    printf("\n");
  }
}

void movement()
{
  move = getch();

  switch (move) {
    case 'w':
      PLAYER_X = PLAYER_X - 1;
      BOARD[PLAYER_X][PLAYER_Y] = HEAD;
      break;
    case 's':
      PLAYER_X = PLAYER_X + 1;
      BOARD[PLAYER_X][PLAYER_Y] = HEAD;
      break;
    case 'a':
      PLAYER_Y = PLAYER_Y - 1;
      BOARD[PLAYER_X][PLAYER_Y] = HEAD;
      break;
    case 'd':
      PLAYER_Y = PLAYER_Y + 1;
      BOARD[PLAYER_X][PLAYER_Y] = HEAD;
      break;
  }
}
