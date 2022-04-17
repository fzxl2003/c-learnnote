#include <stdio.h>
int main421()
{
  int a,b,r,d;
    scanf("%d%d",&a,&b);
    if (b==0) r=a;
    else
    {
        for (r=a%b;r!=0;) {
            a = b;
            b = r;
            r = a % b;
        }
    }
    printf("%d\n",b<0?-b:b);
    return 0;
}

