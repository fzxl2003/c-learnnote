#include <stdio.h>
int main412()
{
    char A,B,C;
    for (A='X';A<='Z';A++)
    {
        for (B='X';B<='Z';B++)
        {
            for (C='X';C<='Z';C++)
            {
                if (A==B||A==C||B==C) continue;
                if (A!='X'&&C!='X'&&C!='Z') printf("A=%c,B=%c,C=%c",A,B,C)  ;
            }
        }



    }
    return 0;
}