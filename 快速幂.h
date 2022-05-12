#include <stdio.h>


int PowerMod(int a, int b, int c)   //整数的快速幂 求(a^b)%c

{
    int ans = 1;
    a = a % c;
    while(b>0)
    {
        if(b % 2 == 1)
            ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}



//复数的快速幂   （可更改改为多变量数的乘法幂）
struct SGL
{
    long long S;
    long long G;
    //long long L;
};
struct SGL Mult(struct SGL A,struct SGL B,long long mod)
{
    struct SGL C;
    C.S=((A.S*B.S-A.G*B.G)%mod+mod)%mod;
    C.G=((A.S*B.G+A.G*B.S)%mod+mod)%mod;
    //C.L=((A.S*B.L+A.L*B.S+A.G*B.G)%mod+mod)%mod;
    return C;
}
struct SGL FastPower(struct SGL base,long long exponent,long long mod)
{
    struct SGL power;
    power.S=1;
    power.G=0;
    //power.L=0;
    for(;exponent!=0;exponent>>=1)
    {

        if((exponent&1)==1)
        {
            power=Mult(power,base,mod);
        }
        base=Mult(base,base,mod);
    }
    return power;
}

int main()
{
    struct SGL abc={1,1};
    struct SGL aaa=FastPower(abc,2,998244353);
    printf("%d %d",aaa.S,aaa.G );
}