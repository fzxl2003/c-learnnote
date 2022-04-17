#include <stdio.h>
int main613()
{
    int space[200000]={1,4,3,10,4,6,-1},i,min=space[0],max=space[1];
    for (i=0;i<200000;i=i+2)
    {    if (space[i+2]==-1)
        {printf("[%d,%d]\n",min,space[i+1]);break;}
        if (min>space[i+2]) min=space[i+2];
        if (max<space[i+3]) max=space[i+3];
        if (space[i+1]>=min)
                continue;
          printf("[%d,%d]\n",min,max);min=space[i+2];
        }


    return 0;
}