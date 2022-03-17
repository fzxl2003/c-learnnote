#include <stdio.h>
int main410()
{
    int sum,i,addsum,n,l,a=0;
    scanf("%d",&sum);
    for (i=1;i<=sum/2+2;i++)
    {
        addsum=0;
        n=i;
        while (addsum<sum)
        {
            addsum+=n;
            n=n+1;
            if (addsum==sum)
            {
                a=1;
                printf("\n%d=",sum);
                for (l=1;l<n-i;l++ )
                {printf("%d+",i+l-1);
                }
                printf("%d",i+l-1);
            }
        }
    }
    if (a==0) printf("none");
}