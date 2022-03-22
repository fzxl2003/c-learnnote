#include <stdio.h>
int main132()
{int a;
    while ((scanf("%d",&a))==0 ||(a>100)||a<0)
    {
        printf("赶紧输入正确值\n");
        while (getchar()!='\n');    //清空缓冲区
    }
}