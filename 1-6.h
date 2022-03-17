#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int min=1,max=100;
int rand1(max1,min1)
{
    srand((unsigned)time(NULL));   //初始化随机数生成器
    int a = rand();
    while ((a>max1-1) ||(a<min1+1) )
    {
        a=rand();
    }
    return a;
}
int main2()
{
    int low,high,random,ans,num=0,oldans;
    low= rand1(max,min);
    high= rand1(max,low+1);
    random= rand1(high,low);
    printf("%d\n",random);
    ans=0;
    while (ans!=random)
    {
        printf("answer is wrong answer between%d and %d\nshow your answer \n", low, high);
        scanf("%d", &ans);
        num++;
        if (ans<high && ans>low)
        {
            if (ans > random) high = ans;
            else low = ans;
        }
        else
        {
            while ((ans=rand1(high,low))==random);
            printf("answer is wrong answer between%d and %d\n", low, high);
        }
    }
    printf("you are right,%d",num);
    return 0;
}