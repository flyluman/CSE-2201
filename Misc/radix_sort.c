#include <stdio.h>
#include <stdlib.h>

int n;

int pw10(int pow) {
    int rlt = 1;
    while(pow--) {
        rlt *= 10;
    }
    return rlt;
}

int *c_counting_sort(int ddt, int *rlt, int *s_rlt) {
    int data[10];
    for(int i=0; i<10; i++) data[i] = 0;

    for(int i=0; i<n; i++) {
        data[(rlt[i] / ddt) % 10] += 1;
    }

    for(int i=1; i<10; i++) data[i] += data[i-1];
    for(int i=9; i>0; i--) data[i] = data[i-1];
    data[0] = 0;

    for(int i=0; i<n; i++) {
        s_rlt[data[(rlt[i] / ddt) % 10]] = rlt[i];
        data[(rlt[i] / ddt) % 10] += 1;
    }
    return s_rlt;
}

int *radix_sort(int *arr) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        max = arr[i] > max ? arr[i] : max;
    }

    int max_len = 0;
    while(max / pw10(max_len)) {
        max_len += 1;
    }

    int *rlt, *s_rlt, *tmp;
    rlt = (int*) malloc(sizeof(int) * n);
    s_rlt = (int*) malloc(sizeof(int) * n);

    c_counting_sort(1, arr, rlt);

    for(int i=1; i<max_len; i++) {
        tmp = rlt;
        rlt = c_counting_sort(pw10(i), rlt, s_rlt);
        s_rlt = tmp;
    }
    free(s_rlt);
    return rlt;
}

int main() {
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(sizeof(int) * n);
    printf("Enter %d integers: ", n);

    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
    }

    int *rlt = radix_sort(arr);

    printf("\nSorted Array:");
    for(int i=0; i<n; i++) {
        printf(" %d", rlt[i]);
    }
    printf("\n");

    free(arr);
    free(rlt);
    return 0;
}
