#include <stdio.h>
//要求用户输入5位正整数
int main44()
{
    int n;
    printf("please input a 5 digit number\n");
    while (scanf("%d",&n)==0||(n<10000||n>99999))
    {
        printf("please input a 5 digit number\n");
        while (getchar()!='\n');    //用于清空
    }
}