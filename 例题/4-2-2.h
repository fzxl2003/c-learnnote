#include <stdio.h>
int main422()
{
    int a,b,r,d;
    scanf("%d%d",&a,&b);
    if (b==0) b=a;
    else
    {
        do  {
            r = a % b;
            a = b;
            b = r;

        } while (r!=0);
    }
    printf("%d\n",a<0?-a:a);
    return 0;
}

