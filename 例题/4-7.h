#include <stdio.h>

int kaifang(sum1,sum2)
{
    int i,b=1;
    for (i=1;i<=sum2;i++)
    {
        b*=sum1;
    }
    return b;
}

int main47()
{
    double a=0,b=0,a1,b1,e=(1e-8)/16.0;
    int i;
    for (i=0,a1=16*0.2;a1>e;i++)
    {
        int a2=kaifang(5,2*i+1);
        if (i%2==0)  a1=1.0/((2.0*i+1.0)*a2);
        else a1=(-1*1.0)/((2.0*i+1.0)*a2);
        a+=a1;
    }
    for (i=0,b1=4.0/239;b1>e;i++)
    {
        if (i%2==0) b1=1.0/((2.0*i+1.0)*(239^(2*i+1)));
        else b1=(-1*1.0)/((2.0*i+1.0)*(239^(2*i+1)));
        b+=b1;
    }
    double pi=a*16-b*4;
    printf("%.8f\n",pi);
    return 0;
}