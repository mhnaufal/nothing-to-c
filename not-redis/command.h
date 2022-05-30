#ifndef COMMAND_H
#define COMMAND_H

#define BUFF_SIZE 1024

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
void show_instruction();
void show_help();
void show_get(char *key);
void show_keys(char *pattern);
void set_key(char *key, char *value);
FILE *open_database_file(char *file_path, char *mode);

#endif