#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in = fopen("fibonacci.txt", "r");

    if (!in)
    {
        printf("Error finding fibonacci.txt\n");
        return 0;
    }

    int n, count;

    fscanf(in, "%d", &n);

    if (n < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    unsigned long long *fib = (unsigned long long *)malloc(sizeof(unsigned long long) * (n + 1));

    count = 4; // initialize i, fib[0], fib[1] + first (i<=n) checksum
    fib[0] = 0, fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        count += 4; // 2 substraction + 1 addition + 1 assignment
        fib[i] = fib[i - 1] + fib[i - 2];
        count += 2; // increase i + (i<=n) checksum
    }

    printf("Fibonacci number upto %d : \n\n", n);
    for (int i = 0; i <= n; i++) printf("%d : %llu\n", i, fib[i]);
    printf("\nStep count = %d\n", count);

    fclose(in);
    free(fib);
    return 0;
}