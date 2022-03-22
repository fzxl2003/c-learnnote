#include <stdio.h>
int main1234()
{int n;
    scanf("%d",&n);
    for (int i = 1; i <=n ; ++i) {
        for (int j = 0; j <n-i ; ++j) {
            printf(" ");
        }
        for (int j1 = 0; j1 < 2*n; ++j1) {
            printf("*");

        }
        printf("\n");
    }
}