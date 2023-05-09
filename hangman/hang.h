#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
