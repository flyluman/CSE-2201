#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./2  input_file_name");
        return 0;
    }

    int n;
    FILE *in = fopen(argv[1], "r");

    if (!in)
    {
        printf("Input file not found!!\n");
        return -1;
    }

    sscanf(argv[1], "random_%d.txt", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        if (fscanf(in, "%d", &arr[i]) == -1)
        {
            n = i + 1;
            break;
        }
    }

    clock_t clk = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }

    clk = clock() - clk;
    printf("Time eclapsed: %lfs\n", (double)clk / CLOCKS_PER_SEC);

    free(arr);
    fclose(in);
    return 0;
}