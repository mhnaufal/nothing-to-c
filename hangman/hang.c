#include "hang.h"

int main(int argc, char *argv[]) {

  printf("+-----------------------------+\n");
  printf("| Welcome to \"The Hangman\"! |\n");
  printf("| Are you ready to be hanged? |\n");
  printf("+-----------------------------+\n");
  printf("Press \"Y\" to start playing or \"Q\" to quit\n");

  char is_menu_playing = 'Q';
  scanf_s("%c", &is_menu_playing);
  if (toupper(is_menu_playing) != 'Y') {
    printf("YOU DIE without playing anything!\n\n");
    return EXIT_SUCCESS;
  }

  srand(time(0));

  struct Quesion_list q_list = create_question_list();
  Question q = get_question(q_list);

  return EXIT_SUCCESS;
}

struct Quesion_list create_question_list()
{
  struct Quesion_list q_list;

  q_list.list[0].question = "Ikan, ikan apa yang taurus?";
  q_list.list[0].answer = "gurame";

  q_list.list[1].question = "Ikan, ikan apa yang jadi kota?";
  q_list.list[1].answer = "bandeng";

  q_list.list[2].question = "Ikan, ikan apa yang suka berhenti?";
  q_list.list[2].answer = "paus";

  q_list.list[3].question = "Ikan, ikan apa yang banyak omong?";
  q_list.list[3].answer = "bawal";

  q_list.list[4].question = "Ikan, ikan apa yang berkuasa?";
  q_list.list[4].answer = "megalodon";

  return q_list;
}

struct Question get_question(struct Quesion_list q_list)
{

  int rand_num = (rand() % (5 - 1 + 1));

  return q_list.list[rand_num];
}
