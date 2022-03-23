#include <stdio.h>
int mian123(int a,int b)
{
    if (b==0) return (a>0)?a:-a;
    return mian123(b,a%b);
}

int main1()
{
    int t,a,b,c,d,son,mother,l;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        mother=b*d;
        son=a*d+b*c;
        l=mian123(mother,son);
        printf("%d %d\n",mother/l,son/l);
    }
}



