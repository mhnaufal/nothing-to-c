#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define NUM_OF_QUESTIONS 5
#define NUM_OF_LIVES 5

/* Data */
typedef struct Question {
    char* question;
    char* answer;
} Question;

typedef struct Quesion_list {
    Question list[NUM_OF_QUESTIONS];
} Question_list;

int NUM_LIVES = NUM_OF_LIVES;

/* Method */
struct Quesion_list create_question_list();
struct Question get_question(struct Quesion_list q_list);
bool check_answer(char* player_ans, struct Question *q_list);
void print_hangman();
void game_loop();
