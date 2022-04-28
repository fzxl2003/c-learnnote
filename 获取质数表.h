#include <stdio.h>
int isPrime(int primes[], int n)
{
    int i;
    for(i=0; primes[i]*primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
            return 0;
    }
    return 1;
}
void init_primes(int primes[], int Q) //构造Q个质数的质数表（Q>=3）
{
    int count=3, num, step;
    primes[0] = 2; primes[1] = 3; primes[2] = 5; //头3个质数
    num = 7; step = 2; //初始为2
    while(count < Q)
    {
        step = 6 - step; // 构造 4-2-4-2-...序列，减少遍历
        if (isPrime(primes, num))
            primes[count++] = num;
        num += step; // 下一个可能的质数
    }
}

int main()
{
    int a[1000];
    init_primes(a,1000);
    for (int i = 0; i < 1000; ++i) {
        printf("%d ",a[i]);
    }
}