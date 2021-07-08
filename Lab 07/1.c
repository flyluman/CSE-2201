#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t t;
    srand((unsigned)time(&t));

    if (argc != 2)
    {
        printf("Usage: ./1  N");
        return 0;
    }

    int n = atoi(argv[1]);

    char file_name[25];
    sprintf(file_name, "random_%d.txt", n);

    FILE *in = fopen(file_name, "w");

    for (int i = 0; i < n; i++)
    {
        fprintf(in, "%d\n", rand() % 10001);
    }

    fclose(in);
    return 0;
}