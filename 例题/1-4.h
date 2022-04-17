#include <stdio.h>
#define MAX_N 100
//输出100以内的质数
void p13own()   //自己编的
{
    int i;
    int m;
    int sum;
    int prime_tab[MAX_N/2];
    prime_tab[0]=2;
    int prime_n=1;
    for (sum=2;sum<100;sum++)
    {
        m=0;
        for (i=0;i<prime_n;i++)
        {
            if (sum%prime_tab[i]==0)
                m++;
        }
        if (m==0)
        {
            printf("%d\n",sum);
            prime_tab[i]=sum;
            prime_n++;

        }
    }

}


int prime_tab[MAX_N/2],prime_n;
int is_prime(int a);
void gen_primes(int max_n)
{
    int i;
    prime_tab[0]=2;
    prime_n=1;
    for (i=3;i<=max_n;i+=2)
        if (is_prime(i))
            prime_tab[prime_n++]=i;

}

int p132()
{
    int i;
    gen_primes(MAX_N);
    for (i=0;i<prime_n;i++)
        printf("%d\n",prime_tab[i]);
    return 0;

}
int is_prime(int a)
{
    int i;
    for (i=0;prime_tab[i]*prime_tab[i]<=a;i++)
        if (a%prime_tab[i]==0)
            return 0;
    return 1;



}