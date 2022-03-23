#include <stdio.h>
int a[1000]={0};
int main()
{int n,i=0;
    while ((scanf("%d",&n))!=EOF)
    {
       a[i]=n;
       i++;
    }
    while (i--)
    { printf("%d\n",a[i]);}
}