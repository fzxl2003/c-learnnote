#include <stdio.h>
//gcd指最大公约数  lcm指最小公倍数
// 原理：1.lcm(a,b)=a*b/gcd(a,b)
//      2.三个数的gcd,lcd相当于先求两个数的gcd、lcm再用求得的两个数去与第三个数求gcd、lcm
//函数数值范围long long

long long gcd(long long a, long long b)
{ if (a==0 && b==0) return EOF;
    if (b==0) return (a>0)?a:-a;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    if (a==0 && b==0) return 0;
    else {long long c=gcd(a,b);return (a*b)/c;}
}
void gcdlcm3(long long a,long long b,long long c)
{
    if ((a==0)+(b==0)+(c==0)>=2) { printf("0h that 1s t00 bad!\n0");return;}
    long long gcd1=gcd(a,b);
    long long gcd2=gcd(c,gcd1);
    long long lcm1=lcm(a,b);
    long long lcm2=lcm(c,lcm1);
    printf("%lld\n%lld",gcd2,lcm2);
}

int main()
{ long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    gcdlcm3(a,b,c);}