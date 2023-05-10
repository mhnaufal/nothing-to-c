#include "hang.h"

int main(int argc, char *argv[]) {

  printf("+-----------------------------+\n");
  printf("| Welcome to \"The Hangman\"! |\n");
  printf("| Are you ready to be hanged? |\n");
  printf("+-----------------------------+\n");
  printf("[Y] Play!\n");
  printf("[Q] QUIT!\n");
  printf("> ");

  char is_menu_playing = 'Q';
  scanf_s("%c", &is_menu_playing);
  if (toupper(is_menu_playing) != 'Y') {
    printf("YOU DIE without playing anything!\n\n");
    return EXIT_SUCCESS;
  }

  srand(time(0));

  game_loop();

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

bool check_answer(char* player_ans, struct Question *q)
{
  while (strcmp(&player_ans, q->answer) != 0 || NUM_LIVES > 0) {
    printf("\nYour answer: ");
    scanf_s("%s", &player_ans);

    if (strcmp(&player_ans, q->answer) == 0) {
      return true;
    }

    if (strcmp(&player_ans, q->answer) != 0) {
      NUM_LIVES--;

      if (NUM_LIVES == 4) {
        print_hangman();
      } else if (NUM_LIVES == 3) {
        print_hangman();
      } else if (NUM_LIVES == 2) {
        print_hangman();
      } else if (NUM_LIVES == 1) {
        print_hangman();
      } else {
        print_hangman();
      }
    }

    if (NUM_LIVES <= 0) return false;
  }

  return false;
}

void print_hangman()
{
  if (NUM_LIVES == 4)
  {
    printf("+-------\n");
    printf("||    ^ \n");
    printf("||    O \n");
    printf("||    | \n");
    printf("||    | \n");
    printf("||      \n");
    printf("++====  \n");
    printf("Lives: %d", NUM_LIVES);
  }
  else if (NUM_LIVES == 3)
  {
    printf("+-------\n");
    printf("||    ^ \n");
    printf("||    O \n");
    printf("||   \\| \n");
    printf("||    | \n");
    printf("||      \n");
    printf("++====  \n");
    printf("Lives: %d", NUM_LIVES);
  }
  else if (NUM_LIVES == 2)
  {
    printf("+-------\n");
    printf("||    ^ \n");
    printf("||    O \n");
    printf("||   \\|/ \n");
    printf("||    | \n");
    printf("||      \n");
    printf("++====  \n");
    printf("Lives: %d", NUM_LIVES);
  }
  else if (NUM_LIVES == 1)
  {
    printf("+-------\n");
    printf("||    ^ \n");
    printf("||    O \n");
    printf("||   \\|/ \n");
    printf("||    | \n");
    printf("||   /  \n");
    printf("++====  \n");
    printf("Lives: %d", NUM_LIVES);
  }
  else if (NUM_LIVES == 0)
  {
    printf("+-------\n");
    printf("||    ^ \n");
    printf("||    O \n");
    printf("||   \\|/ \n");
    printf("||    | \n");
    printf("||   / \\ \n");
    printf("++====  \n");
    printf("Lives: %d", NUM_LIVES);
  }
}

void game_loop()
{
  struct Quesion_list q_list = create_question_list();
  Question q = get_question(q_list);

  printf("\n=========================================================\n");
  printf("%s\n", q.question);
  int ans_length = strlen(q.answer);
  char* player_ans = " ";

  printf("The answer consists of %d letter\t", ans_length);
  for (int i = 0; i < ans_length; ++i) {
    printf("_ ");
  }
  printf("\n");

  bool is_correct = check_answer(&player_ans, &q);

  if (!is_correct) {
    printf("+-----------------+\n");
    printf("|     YOU DIE!    |\n");
    printf("|     YOU DIE!    |\n");
    printf("|     YOU DIE!    |\n");
    printf("+-----------------+\n");
  } else {
    printf("+-----------------+\n");
    printf("|   YOU SURVIVE!  |\n");
    printf("|   YOU SURVIVE!  |\n");
    printf("|   YOU SURVIVE!  |\n");
    printf("+-----------------+\n");
  }
}
