#include<stdio.h>
#include<math.h>
double f(double x)
{
    return  sin(x*x); //函数表达式
}
int  main()
{
    double a=0,b,len,F=0;//求a到b的积分
    int n=1000000,i;
    //printf("请输入a,b: ");
    scanf("%lf",&b);
    //printf("请输入n的值: ");
    //scanf("%d",&n);
    len=(a+b)/n;
    for(i=0;i<n;i++)
    {
        F+=len*f(a);
        a+=len;
    }
    printf("%.2f",F);
    return 0;
}