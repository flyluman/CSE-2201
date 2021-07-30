#include <stdio.h>
#include <stdlib.h>

int n, *col, *rlt, *diag1, *diag2;

void print(int y) {
    for (int i = 0; i < y; i++) {
        printf(" %d", rlt[i]);
    }
    printf("\n");
    return;
}

void search(int y) {
    if (y == n) {
        printf("Solution:");
        print(y);
        return;
    }

    if (y) {
        printf("Backtrack From Node:");
        print(y);
    } else {
        printf("\n");
    }

    for (int x = 0; x < n; x++) {

        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;

        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        rlt[y] = x + 1;

        search(y + 1);

        col[x] = diag1[x + y] = diag2[x - y + n - 1] = rlt[y] = 0;
    }
    
    return;
}

int main() {

    printf("Enter the value of n: ");
    scanf("%d", &n);

    col = (int *)calloc(sizeof(int), n);
    rlt = (int *)calloc(sizeof(int), n);
    diag1 = (int *)calloc(sizeof(int), 2 * n - 1);
    diag2 = (int *)calloc(sizeof(int), 2 * n - 1);

    search(0);

    free(col);
    free(rlt);
    free(diag1);
    free(diag2);

    return 0;
}
