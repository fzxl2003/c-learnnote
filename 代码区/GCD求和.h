/*K GCD求和
 * https://accoding.buaa.edu.cn/contest-ng/index.html#/855/problems
问题分析  //详情见C8题解
        先考虑⼀个时间复杂度 的做法：从左到右遍历 序列，设当前遍历到 ，⽤⼀个数组 ， 表示
        的最⼤公约数。当要遍历到 时，遍历 数组，更新即可。答案就是
        如何优化时间复杂度？可以发现 存在⼀个性质，如果 ，那么 ，因此对于⼀个
        数量级的数，不停和其他数取 ，直到1的过程中，最多仅会出现 个不同的数。
回到题⽬， 数组也可以看作是 不停取gcd的结果，也就是说， 数组中最多仅仅会存在60个不同的数。把相同的
        数合并，这样我们可以把 数组压缩到⻓度只有64的⼩数组，记录下每个数的个数，同样可以统计答案。
时间复杂度： ， 为序列中最⼤的数。
*/
/*
 K GCD求和
时间限制：1000ms   内存限制：65536kb

通过率：3/39 (7.69%)    正确率：3/100 (3.00%)

题目描述
给定一个长度为 n 的序列 a={a1,a2,…,an}，求
∑1≤i≤j≤ngcd (ai,ai+1,...,aj)
输入
第一行一个整数 n，代表序列长度
第二行 n 个整数，代表序列a
输出
一行输出，代表答案对998244353取模的结果
输入样例
5
2 6 3 9 9
输出样例
58
样例解释
58=(2+6+3+9+9)+(2+3+3+9)+(1+3+3)+(1+3)+(1)

数据范围
1≤n≤1000000
ai 是longlong范围内的正整数
 */
#include<stdio.h>
#include<stdlib.h>
#define mod 998244353
long long a[1000005],ans;
int n,cnt;
struct steins{
    int pos;
    long long x;
};
struct steins k[105];
long long gcd(long long x,long long y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void merge(){
    int g=0;
    for(int i=1;i<=cnt;i++)
        if(k[i].x!=k[i-1].x)
            k[++g]=k[i];
    cnt=g;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cnt; j++)
            k[j].x = gcd(k[j].x, a[i]);
        k[++cnt].x = a[i];
        k[cnt].pos = i;
        merge();
        k[cnt + 1].pos = i + 1;
        for (int j = 1; j <= cnt; j++)
            ans = (k[j].x % mod * (k[j + 1].pos - k[j].pos) + ans) % mod;
    }
    printf("%lld", ans);
}