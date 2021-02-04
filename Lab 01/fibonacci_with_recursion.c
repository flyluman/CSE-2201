#include <stdio.h>
#include <stdlib.h>

int count;
unsigned long long *fib;

unsigned long long fibonacci(int n)
{
    count += 1; // if() checksum

    if (fib[n])
    {
        count += 1; // return
        return fib[n];
    }

    count += 4; // 3 compare + if() checksum

    if (n == 0 || n == 1)
    {
        count += 1; // return
        return (unsigned long long) n;
    }

    count += 7; // 2 function call + 2 substraction + 1 addition + 1 assignment + return
    return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    FILE *in = fopen("fibonacci.txt", "r");

    if (!in)
    {
        printf("Error finding fibonacci.txt\n");
        return 0;
    }

    int n;

    fscanf(in, "%d", &n);

    if (n < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    
    fib = (unsigned long long *)calloc(sizeof(unsigned long long), n + 1);

    fibonacci(n);

    printf("Fibonacci number upto %d : \n\n", n);
    for(int i = 0; i <= n; i++) printf("%d : %llu\n", i, fib[i]);
    printf("\nStep count = %d\n", count);

    fclose(in);
    free(fib);
    return 0;
}