#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

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
        set_key(key_param, value_param);
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

void show_help()
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
        fprintf(stderr, "[❌] Can't open file '%s'\n", file_path);
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
    bool found = false;

    while (fscanf(db_file, "%s", datas) == 1)
    {
        if (!strcmp(key, datas))
        {
            found = true;
            continue;
        }

        if (found)
            break;
    }

    if (!found)
    {
        printf("[⛔] Key '%s' doesn't exist\n", key);
    }
    else
    {
        printf("%s [%s]", key, datas);
    }

    puts("");
    fclose(db_file);
}

void show_keys(char *pattern)
{
    FILE *db_file = open_database_file("db.txt", "r");
    char datas[BUFF_SIZE];

    if (!strcmp(pattern, "all") || !strcmp(pattern, ""))
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

void set_key(char *key, char *value)
{
    if (!key)
    {
        fprintf(stderr, "[❌] Can't process 'set' command. No key provided\n");
        exit(1);
    }
    else if (!value)
    {
        fprintf(stderr, "[❌] Can't process 'set' command. No value provided\n");
        exit(1);
    }

    FILE *db_file = open_database_file("db.txt", "r");
    char data[BUFF_SIZE];
    bool found = false;

    while (fscanf(db_file, "%s", data) == 1)
    {
        if (!strcmp(key, data))
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        printf("[⛔] Data with the key '%s' already existx exist\n", key);
        exit(1);
    }
    else
    {
        FILE *reopen_db_file = freopen("db.txt", "a+", db_file);
        char *saved_data;

        if ((saved_data = calloc(strlen(key) + strlen(value) + 1, sizeof(char))) != NULL)
        {
            saved_data[0] = '\0';
            strcat(saved_data, key);
            strcat(saved_data, " ");
            strcat(saved_data, "\"");
            strcat(saved_data, value);
            strcat(saved_data, "\"");
            strcat(saved_data, "\n");

            fflush(stdin);
            fputs(saved_data, reopen_db_file);

            free(saved_data);
        }
        else
        {
            fprintf(stderr, "[❌] Failed to save data into the database\n");
        }
    }

    puts("");
    fclose(db_file);
}