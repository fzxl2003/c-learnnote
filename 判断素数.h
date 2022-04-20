#include <stdio.h>
#include <math.h>
int swichsushu(int n)
{int l=0;
    if (n==1||n<=0) {return 0;}
    if (n==2){return 1;}
    int k=(int)sqrt( (double)n );
    for (int i=2;i<=k;i++)
    {if (!(n%i))
        {l=1;break;}

    }
    if (l) return 0;
    else return 1;
}


int main()
{
    int n;int l;
    while ((scanf("%d",&n))!=EOF)
    {l=0;
        if (n==1||n<=0) {printf("no\n");continue;}
        if (n==2){printf("yes\n");continue;}
        int k=(int)sqrt( (double)n );
        for (int i=2;i<=k;i++)
        {if (!(n%i))
            {l=1;break;}

        }
        if (l) printf("no\n");
        else printf("yes\n");
    }
}