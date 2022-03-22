#include <stdio.h>
int main43()
{
    int n,a=1,b=1;
    scanf("%d",&n);
    for (int i=3;i<=n;i++)
    {
        b=a+b;
        a=b-a;

    }
    printf("%d",b);
}