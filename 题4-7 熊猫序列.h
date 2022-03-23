#include <stdio.h>
int main()
{
    long long a1=1,a2=0,a3=0,a4=0,a5=0;
    int n;
    scanf("%d",&n);
    n--;
    while (n--)
    {a5+=a4;
        a4=a3;
        a3=a2;
        a2=a1;
        a1=a5;}
    printf("%d",(a1+a2+a3+a4+a5)%10000007);
}