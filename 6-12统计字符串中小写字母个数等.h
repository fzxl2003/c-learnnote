#include <stdio.h>
#include <ctype.h>
int main612()
{
    int i,c,loc[26]={0},b=0;
    for (i=1;(c=getchar())!=EOF;i++)
    {
        if  (islower(c) &&loc[c-'a']!=0)
        {printf("%c %d:%d",c,loc[c-'a'],i);b=1;}

        else loc[c-'a']=i;

    }
    if (b==0) printf("0");
}