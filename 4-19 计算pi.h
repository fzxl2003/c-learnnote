#include <stdio.h>
#include <math.h>
int main1233()
{
    double a=0,b=0,a1,b1,jingdu=1;int fuhao=-1;long long wu=5,ersanjiu=239;
    for (int i = 0; jingdu>1e-11; i++) {
        fuhao*=-1;
        a1=1.0*fuhao/(2*i+1)/wu;
        b1=1.0*fuhao/(2*i+1)/ersanjiu;
        wu=wu*25;ersanjiu=ersanjiu*239*239;
        jingdu=fabs(16*a1-4*b1);
        a+=a1;b+=b1;
    }
    printf("%.11f",a*16-b*4);
}