#include <stdio.h>
#include <ctype.h>
int main62()
{
    int c,low[26]={0},supper=0,total=0,i;
    while ((c=getchar())!=EOF)
    {
        if (islower(c)) low[c-'a']++;
        if (isupper(c)) supper++;
        total++;
    }
    for (i=0;i<26;i++)
    {
        if (low[i]!=0) printf("%c:%d\n",i+'a',low[i]);
    }
    printf("supper:%d;total:%d",supper,total);
    return 0;
}