#include <stdio.h>
int main46()
{
    int sum,a,b,c;
    for (sum=100;sum<1000;sum++)
    {
        a=sum/100;
        b=(sum-a*100)/10;
        c=(sum-a*100-b*10);
        if (sum==(a*a*a+b*b*b+c*c*c))
            printf("%d\n",sum);

    }
}