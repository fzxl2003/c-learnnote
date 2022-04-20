/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4186472
 Created at: Thu Mar 17 2022 21:49:32 GMT+0800 (China Standard Time)
 Problem_id: 5418	Time: 5	Memory: 1724
输入
一个signed char类型的数x。
输出
共三行，第一行为x的原码；第二行为x的反码；第三行为x的补码；每行均由八个0或1组成。
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
int main()
{
    signed char x;
    scanf("%hhd",&x);
    if(x>=0)
    {
        for(int k=1;k<=3;k++)
        {
            for(int i=7;i>=0;i--) printf("%d",(x>>i)&1);
            printf("\n");
        }
    }
    else
    {
        printf("1");
        for(int i=6;i>=0;i--)
        {
            printf("%d",((~(x-1))>>i)&1);
        }
        printf("\n");
        for(int i=7;i>=0;i--)
        {
            printf("%d",((x-1)>>i)&1);
        }
        printf("\n");
        for(int i=7;i>=0;i--)
        {
            printf("%d",(x>>i)&1);
        }
        printf("\n");
    }
    // system("pause");
    return 0;
}