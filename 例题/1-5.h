#include <stdio.h>

int draw(h,c1,c2)
{
    int line,row;

    for (line=1;line<=h;line++)
    {
        for (row=1;row<=h-line;row++)
        {
            putchar(' ');
        }
        putchar(c1);
        for (row=h-line+2;row<=h+line-2;row++)
        {
            putchar(c2);

        }
        if (line!=1)
        {
            putchar(c1);
        }
        putchar('\n');

    }



}



int main1_5()
{
    int h,c1,c2;
    scanf("%d %c %c",&h,&c1,&c2);
    if (h>40 || h<3)
    {
        printf("123");
        return 1;
    }
    draw(h,c1,c2);
    return 0;








}