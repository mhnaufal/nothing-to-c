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

  return EXIT_SUCCESS;
}
