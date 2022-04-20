/*
 题目描述
西方不能没有耶路撒冷，就像AAUB不能没有超市，但作为一个神奇的超市，超市 只接受和找零特定面值的货币，请你帮助不会数学的 dwy 判断她能否使用特定面值的货币在 超市 购买总价值为 k 的商品。
假设dwy和超市都有足够多数量的货币。

输入格式
共 2t+1 行。
第一行，一个整数 t ，表示共有 t 组数据。
接下来的 2t 行，每 2 行为一组数据。每组数据的第一行为两个整数，分别表示货币种数 n 和商品的总价值 k，第二行有 n 个数据，表示每种货币的面值。

输出格式
共 t 行。
对于每组数据输出一行，若可以购买，输出Da!，否则输出Nyet.
 */

/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4273322
 Created at: Sun Apr 03 2022 23:06:59 GMT+0800 (China Standard Time)
 Problem_id: 5404	Time: 5	Memory: 1732
*/

#include <stdio.h>

int gcd(int a, int b)
{ if (a==0 && b==0) return EOF;
    if (b==0) return (a>0)?a:-a;
    return gcd(b,a%b);
}

int main()
{
    int t,n,m,k,maxgcd=0;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&k);
        maxgcd=0;
        while (n--)
        {
            scanf("%d",&m);maxgcd=gcd(maxgcd,m);}
        if (k%maxgcd==0) { printf("Da!\n");}else { printf("Nyet.\n");}
    }

}