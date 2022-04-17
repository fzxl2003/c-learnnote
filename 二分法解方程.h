//所解方程在选定区间内必须单调
#include <stdio.h>
double f(double x)
{
    return x*x;//函数表达式
}

double solve(double low,double high,double eps,double fx)  //eps为误差范围  fx为所求函数值  //适用于单增函数
{double mid;
    while (high-low>eps)
    {
        mid=(high+low)/2;
        if (f(mid)>fx)   //若为单减函数，仅需改变不等号
        {high=mid;}
        else low=mid;
    }
    return low;
}

int main()
{
    printf("%f", solve(0,2,0.00001,2));
}