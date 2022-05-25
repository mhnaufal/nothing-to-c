#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* DATAS */
enum database_commands
{
    GET,
    SET,
    KEYS
};

/**
 * 'static' here means that this const
 * only available within this unit/file
 */
static const char *const commands[] = {
    [GET] = "get",
    [SET] = "set",
    [KEYS] = "keys",
};

/* METHODS */
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
        fprintf(stderr, "ERROR: could not open file \"%s\": %m\n", file_path);
        exit(1);
    }

    return opened_file;
}

void show_get(char *key)
{
    if (!key)
    {
        fprintf(stderr, "ERROR: no key given\n");
        exit(1);
    }

    FILE *db_file = open_database_file("db.txt", "r");

    char datas[255];

    // make it read per string, instead of per newline
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

    // compare the pattern

    char datas[255];

    while (fgets(datas, sizeof(datas), db_file) != NULL)
    {
        fputs(datas, stdout);
    }

    puts("");
    fclose(db_file);
}

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
