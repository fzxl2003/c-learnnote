#include <stdio.h>
int main63(max)
{
    int single[30000]={2},i,j=0,k,type;
    for (i=3;i<=max;i++)
    {
        for(k=0,type=1;k<=j;k++)
        {
            if (i%single[k]==0)
            {type=0;
                break;}
        }
        if (type==1)
        {
            j++;
            single[j]=i;
        }
    }
    for (i=0;i<=j;i++)
    {
        printf("%d  ",single[i]);
    }
    return 0;
}