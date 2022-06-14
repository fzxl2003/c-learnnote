/*
 题目描述
魔法少女 zhn 决定取出自己在 ATM 里的所有储蓄出去玩。他忘记了自己有多少存款（但是银行卡密码他还记得），并且这个奇怪的 ATM 机器不支持余额查询功能。他唯一记得的事情就是存款的上限是 K 元。我们这里把问题进行简化，他的存款是 0−K 之间的任意整数（包括0和k）。
每次 zhn 都可以尝试从 ATM 中拿出一些钱，如果他要拿的 y 元钱不大于他的存款，那么 ATM 机器将会立即给他 y 元。但是如果他的存款小于 y，他将收到一次机器的警告⚠。
如果他被警告超过 w 次，警察叔叔就会来把他抓走。
魔法少女会魔法，他希望在保证不被抓走的前提下，用最少的次数取出所有钱，请你求出这个最小次数的期望。
注意，由于 zhn 足够聪明，他总是采取最优策略。

输入
每个测试点包含多组测试数据（最多10组）
每组测试数据包含两个整数K和W (1≤K,W≤2000)
输出
对于每组测试数据，输出最小取钱次数的期望值，保留至小数点后6位。

输入样例
1 1
4 2
20 3
输出样例
1.000000
2.400000
4.523810
 */
/*
 Author: 潘宇恒
 Result: AC    Submission_id: 4333545
 Created at: Sun Apr 17 2022 14:11:05 GMT+0800 (China Standard Time)
 Problem_id: 5540    Time: 437    Memory: 2076
*/
#include <stdio.h>
double INF = 1e12;
double eps = 1e-7;
double aa[2005][20];
double min(double a,double b)
{return (a>b)?b:a;}
double solve(int k, int w)
{
    if(k == 0)
        return aa[k][w] = 0;
    if(w == 0)
        return INF;
    if(aa[k][w] > eps)
        return aa[k][w];
    aa[k][w] = INF;
    for(int i=1; i<=k; i++)
        aa[k][w] = min(aa[k][w],(double)(k-i+1)/(k+1)*solve(k-i,w)+(double)i/(k+1)*solve(i-1,w-1)+1);
    return aa[k][w];
}
int main()
{
    int k, w;
    while((scanf("%d%d",&k,&w)!=EOF))
    {
        w = (w>12)?12:w;
        printf("%.6lf\n",solve(k,w));
    }
    return 0;
}