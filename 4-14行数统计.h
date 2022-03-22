#include <stdio.h>
int main123()
{char a;int i=0;
    while ((a=getchar())!=EOF)
    {
        if (a=='\n') i++;
    }
    printf("%d",i);
}