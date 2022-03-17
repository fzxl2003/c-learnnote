#include <stdio.h>
//求最大公约数
int main42()
{
    int a,b,gcd;
    scanf("%d%d",&a,&b);
    int i=1;
    while (i<=a && i<=b)
    {
        if (a%i==0 && b%i==0) gcd=i;
        i=i+1;
    }
    printf("agc=%d",gcd);
    return 0;
}