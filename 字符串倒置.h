//字符串倒置
#include <stdio.h>

void strdaozhi(char s[])
{
    int hi=0,low=0;char tem;
    while (s[hi]!='\0')
    {
        hi++;
    }
    for (hi--;hi>=low;low++)
    {
        tem=s[low];
        s[low]=s[hi];
        s[hi]=tem;
    }

}


int main()
{
  char s[1000];
  gets(s);
  puts(s);
    strdaozhi(s);
    puts(s);
}