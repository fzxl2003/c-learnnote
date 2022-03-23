#include <stdio.h>
#include <math.h>
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