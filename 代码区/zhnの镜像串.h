/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4395366
 Created at: Thu Apr 28 2022 09:44:26 GMT+0800 (China Standard Time)
 Problem_id: 5693	Time: 3	Memory: 1608
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char a,char b)
{
    char aa[]="AbdHIMOopqTUVvWwXxY";
    char bb[]="AdbHIMOoqpTUVvWwXxY";
    int len=strlen(aa);
    for (int i = 0; i <len; i++) {
        if (a==aa[i]&&b==bb[i])
            return 1;
    }
    return 0;

}

int main()
{
    char str[1004];
    while (scanf("%s",str)!=EOF)
    {
        int len= strlen(str);int flag=1;
        for (int i = 0; i < len; ++i) {
            if (check(str[i],str[len-i-1])==0)
            {flag=0;break;}
        }
        if (flag==0) puts("OH,NO!");
        else puts("Cool");
    }
}