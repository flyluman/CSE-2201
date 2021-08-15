#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int x, int y) {
	return (x > y) ? x : y;
}

int lcs( char *str1, char *str2) {

    int m = strlen(str1);
    int n = strlen(str2);

    int (*dp)[n+1] = (int (*)[n+1]) malloc(sizeof(int) * (m+1) * (n+1));

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
        if (i == 0 || j == 0)
            dp[i][j] = 0;
        else if (str1[i-1] == str2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int ret = dp[m][n];
    free(dp);
    return ret;
}



int main() {
    char str1[101], str2[101];

    printf("Enter 1st string: ");
    scanf(" %s", str1);
    printf("Enter 2nd string: ");
    scanf(" %s", str2);

    printf("\nLCS Count: %d\n", lcs(str1, str2));

    return 0;
}