#include <stdio.h>
//行数统计
int main43()
{
    int a,c,n=0;
    scanf("%d",&a);
    while ((c=getchar())!=EOF)
    {
        if (c=='\n')
        n++;
    }
    printf("%d",n);
}