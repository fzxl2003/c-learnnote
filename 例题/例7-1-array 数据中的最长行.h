#include <stdio.h>
#include <string.h>
int main()
{  char a[10000]={0},b[10000]={0};
    char *maxz,*shuruz,*tem;
    shuruz=a;
    maxz=b;
    while ((scanf("%s",shuruz))!=EOF)
    {
        if (strlen(shuruz)> strlen(maxz))
        {
            tem=shuruz;
            shuruz=maxz;
            maxz=tem;
        }
    }
    printf("%d %s", strlen(maxz),maxz);
}