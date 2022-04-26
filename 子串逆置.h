#include <stdio.h>
#include <string.h>


void gaibian(char *s,char *t)
{
    char *begin,*end;char tem;
    if ((begin= strstr(s,t))!=NULL)
    {
        end=begin+ strlen(t)-1;
        while (end>begin)
        {
           tem=*begin;
           *begin=*end;
           *end=tem;
           begin++;end--;
        }
    }
}

int main()
{
    char s[10000]={0},t[10000]={0};
    while (scanf("%s%s",s,t)!=EOF)
    {
    gaibian(s,t);
    printf("%s\n",s);
    }
}