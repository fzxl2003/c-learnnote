#include <stdio.h>
int main49()
{
    int n,h,i,blank;
    scanf("%d",&n);
    for(h=1;h<=n;h++)
    {
        blank=n-h;

            for (i=1;i<=blank;i++)
            {
                printf(" ");
            }
            for (i=1;i<=2*n;i++)
            {
                printf("*");
            }
        printf("\n");


    }
    return 0;
}