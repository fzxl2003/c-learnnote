#include <stdio.h>
int main123(){
    int n, sum = 0, nn = 1;
    scanf("%d", &n );
    for (int i = 1; i <= n; i++)
    {
        nn*= i;
        sum += nn; }
    printf("%d", sum );
}