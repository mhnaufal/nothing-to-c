#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("reading from a file...\n");
    FILE *input_file = fopen("db.txt", "r");

    if (input_file == NULL)
    {
        perror("ERROR: No such file\n");
        return -1;
    }

    char datas[255];

    while (fgets(datas, sizeof(datas), input_file) != NULL)
    {
        fputs(datas, stdout);
        // printf("%s\n", datas);
    }

    fclose(input_file);
    printf("finish reading form a file...\n");

    return 0;
}