#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "command.h"

/* MAIN */
int main(int argc, char *argv[])
{
    char *command = argv[1];
    char *key_param = argv[2];
    char *value_param = argv[3];

    if (!command)
    {
        show_instruction();
    }
    else if (!strcmp(command, commands[GET]))
    {
        show_get(key_param);
    }
    else if (!strcmp(command, commands[SET]))
    {
        printf("writing...\n");
    }
    else if (!strcmp(command, commands[KEYS]))
    {
        char *pattern;

        // To prevent from giving a NULL argument into show_keys() function
        if (key_param == NULL)
        {
            pattern = "";
        }
        else
        {
            pattern = key_param;
        }

        show_keys(pattern);
    }
    else
    {
        printf("[❌] Can't continue the process. Undefined command '%s'\n", command);
    }

    puts("-OK-\n");

    return 0;
}

void show_instruction()
{
    printf(
        "db [command] [params]\n\n"
        "📌 get    : take a key as the parameter and return the value if the given key is exists\n"
        "📌 set    : take a key and a value as the paramters and save it to the file db\n"
        "📌 keys   : take a pattern of key and return the value base on the pattern\n");
}

FILE *open_database_file(char *file_path, char *mode)
{
    FILE *opened_file = fopen(file_path, mode);

    if (opened_file == NULL)
    {
        fprintf(stderr, "[❌] Can't not open file '%s': %m\n", file_path);
        exit(1);
    }

    return opened_file;
}

void show_get(char *key)
{
    if (!key)
    {
        fprintf(stderr, "[❌] Can't process 'get' command. No key provided\n");
        exit(1);
    }

    FILE *db_file = open_database_file("db.txt", "r");

    char datas[BUFF_SIZE];

    while (fgets(datas, sizeof(datas), db_file) != NULL)
    {
        printf("[%s] %s", key, datas);
        if (!strcmp(key, datas))
        {
            printf("[%s] %s", key, datas);
        }
    }

    puts("");
    fclose(db_file);
}

void show_keys(char *pattern)
{
    FILE *db_file = open_database_file("db.txt", "r");

    char datas[BUFF_SIZE];

    if (!strcmp(pattern, "all") || pattern == "")
    {
        while (fgets(datas, sizeof(datas), db_file) != NULL)
        {
            fputs(datas, stdout);
        }
    }
    else
    {
        printf("[❌] Can't process 'keys' command. Unknown options '%s'", pattern);
    }

    puts("");
    fclose(db_file);
}