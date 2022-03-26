/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4232156
 Created at: Sat Mar 26 2022 09:43:34 GMT+0800 (China Standard Time)
 Problem_id: 5425	Time: 10	Memory: 1680
*/

#include <stdio.h>
#include <math.h>
double p=1e-8;        //精度
double pp=1e-10;
int main()
{
    double a;double top,low,mid=0;
    scanf("%lf",&a);
    low=0;
    top=a;
    while (fabs((mid*mid-a))>p)
    {
        mid=(top+low)/2;
        if (mid*mid>a)
        {top=mid;}
        else if (mid*mid<a)
        {
            low=mid;
        }

    }
    printf("%.8f",mid);

}