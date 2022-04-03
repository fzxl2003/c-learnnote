/*
 问题分析
本题实质上是求所有数最⼤公约数算法的应⽤，
在具体代码实现中，可以将求最⼤公约数的函数封装多次调⽤，求得所有货币⾯值的最⼤公约数，再判断其能否整
除总⾦额，即可求解。
 https://accoding.buaa.edu.cn/contest-ng/index.html#/822/problems  J
 */


#include <stdio.h>
int gcd(int a, int b);
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = 0;
        while (n--)
        {
            int a;
            scanf("%d", &a);
            ans = gcd(ans, a);
        }
        if (k % ans)
        {
            printf("Nyet.\n");
        }
        else
        {
            printf("Da!\n");
        }
    }
    return 0;
}
int gcd(int a, int b) {
    if (b > a) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}