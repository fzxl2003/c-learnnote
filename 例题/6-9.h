#include <stdio.h>
int main69(int a[],int sum)
{
    int i,j,minno=0,min;
    for (i=0;i<sum;i++)
    {
        minno=i;
        for (j=i;j<sum;j++)
        {
            if (a[j]<a[minno]) {
                minno = j;
            }
        }
        min=a[minno];
        a[minno]=a[i];
        a[i]=min;
    }
    for (i=0;i<sum;i++)
    { printf("%d",a[i]);}
    return 0;
}