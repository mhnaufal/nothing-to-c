#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

enum database_commands
{
    GET,
    SET,
    KEYS
};

static const char *const commands[] = {
    [GET] = "get",
    [SET] = "set",
    [KEYS] = "keys",
};

void show_instruction()
{
    printf(
        "db [command] [params]\n\n"
        "📌 get    : take a key as the parameter and return the value if the given key is exists\n"
        "📌 set    : take a key and a value as the paramters and save it to the file db\n"
        "📌 keys   : take a pattern of key and return the value base on the pattern\n");
}

void show_keys(char *pattern)
{
    FILE *db_file = fopen("db.txt", "r");

    if (db_file == NULL)
    {
        fprintf(stderr, "ERROR: could not open file\n");
        exit(1);
    }

    // compare the pattern

    char datas[255];

    while (fgets(datas, sizeof(datas), db_file) != NULL)
    {
        fputs(datas, stdout);
    }

    puts("");
    fclose(db_file);
}

int main(int argc, char *argv[])
{
    char *command = argv[1];

    if (!command)
    {
        show_instruction();
    }
    else if (!strcmp(command, commands[GET]))
    {
        printf("reading...\n");
    }
    else if (!strcmp(command, commands[SET]))
    {
        printf("writing...\n");
    }
    else if (!strcmp(command, commands[KEYS]))
    {
        char *pattern = "*";
        show_keys(pattern);
    }
    else
    {
        printf("[❌] Can't continue the process. Undefined command \"%s\"\n", command);
    }

    puts("-OK-\n");

    return 0;
}
