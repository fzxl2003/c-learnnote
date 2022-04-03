/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4264524
 Created at: Wed Mar 30 2022 21:52:48 GMT+0800 (China Standard Time)
 Problem_id: 5488	Time: 47	Memory: 3180

https://accoding.buaa.edu.cn/problem/5488/index


 题目描述
一元多项式的定义如下：

设 c0,c1,...,cn 都是数域 F 中的数，n 是非负整数，那么表达式
cn×xn+cn−1×xn−1+...+c2×x2+c1×x+c0
就是数域 F 上关于变量 x 的多项式或一元多项式。

其中，ck×xk   (1≤k≤n) 代表该一元多项式中的一个项，ck 是该项的系数，k 是该项的指数。

现在给定两个整数数域上关于变量 x 的一元多项式 f(x) 和 g(x)，请你求出二者相加后产生的一元多项式 f(x)+g(x)，并要求不再输出系数为 0 的项。

输入格式
第一行两个整数 N,M  (1≤N,M≤100000)，分别代表 f(x) 和 g(x) 的项数。

第二行 2×N 个整数，第 2×i−1 和 2×i 个整数分别代表 f(x) 中第 i 项的系数 ai 和指数 si，ai 和 si 在 int 范围内，且 ai≠0 。

第三行 2×M 个整数，第 2×j−1 和 2×j 个整数分别代表 g(x) 中第 j 项的系数 bj 和指数 tj，bj 和 tj 在 int 范围内，且 bj≠0 。

保证多项式 f(x) 和 g(x) 中的项按指数严格降序给定。

输出格式
输出一行，包含偶数个整数，第 2×k−1 和 2×k 个整数分别代表 f(x)+g(x) 中第 k 项的系数和指数，并以指数严格降序输出。

样例输入
3 2
6 3 3 2 9 1
-6 3 -5 1
样例输出
3 2 4 1
样例解释
根据题意可知
f(x)=6×x3+3×x2+9×x g(x)=−6×x3−5×x
因而
f(x)+g(x)=3×x2+4×x
即输出 3 2 4 1。
*/



#include <stdio.h>

long long  f[2][100009] = {0};
long long g[2][100009] = {0};

int main() {

    long long l, n, m, n1, m1;
    long long k;
    long long a;
    long long maxkn = 0;long long maxkm = 0;
    scanf("%lld%lld", &n, &m);
    n1 = n;
    m1 = m;
    for (int i = 1; i <=n ; ++i) {
        scanf("%lld%lld", &a, &k);
        f[0][i] = a;
        f[1][i] = k;
    }
    for (int i = 1; i <=m ; ++i) {
        scanf("%lld%lld", &a, &k);
        g[0][i] = a;
        g[1][i] = k;
    }

    int p=1,q=1;
    while (p<=n ||q<=m)
    {
        if (f[1][p]>g[1][q])
        {if (f[0][p]!=0) printf("%d %d ",f[0][p],f[1][p]);
            p++;}
        else if (f[1][p]<g[1][q])
        {
            if (g[0][q]!=0) printf("%d %d ",g[0][q],g[1][q]);
            q++;
        }
        else {if (g[0][q]+f[0][p]!=0) printf("%d %d ",g[0][q]+f[0][p],g[1][q]);
            p++;q++;}
    }
}