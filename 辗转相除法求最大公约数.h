#include <stdio.h>
int mian123(int a,int b)
{
    if (b==0) return (a>0)?a:-a;
    return mian123(b,a%b);
}

int main12342()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",mian123(a,b));
}