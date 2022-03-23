#include <stdio.h>
int main1(double x,int n)
{int fuhao=1;double xx=x*x,nn=2,sum=1;
    for (int i = 2; i <=n; i++) {
        fuhao*=-1;
        sum+=fuhao*xx/nn;
        xx=xx*x*x;
        nn=nn*(2*i)*(2*i-1);
    }
    printf("%.8f",sum);


}
int main()
{ double x;int n;
    scanf("%lf%d",&x,&n);
main1(x,n);}