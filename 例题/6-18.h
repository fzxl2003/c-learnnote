#include <stdio.h>
int main618(char *a)
{
    int i,j;char b[30],c;
    for (i=0;*a!='\0';a++,i++)
    { b[i]=*a;}
    b[i+1]='\0';
    i=0;
    while (b[i]!='\0'){i++;}

    for (i--,j=0;i>j;j++,i--)
    {
        c=b[i];
        b[i]=b[j];
        b[j]=c;
    }
    for (i=0;b[i]!='\0';i++)
    { printf("%c",b[i]);}
    return 0;
}