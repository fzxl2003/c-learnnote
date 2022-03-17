#include <stdio.h>
int main()
{
    char *a="hello world";
    for (;*a!='\0';a++)
    { printf("%c",*a);}
    return 0;
}