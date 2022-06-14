//法一：利用三角形计算，适合多次重复获取组合数的题目
#include <stdio.h>
unsigned long long aa[113][119];
void jisuan()
{
    aa[0][0]=1ull;
    aa[1][0]=1ull;
    aa[1][1]=1ull;
    for (int i = 2; i <=103 ; ++i) {
        aa[i][0]=1ull;
        for (int j = 1; j <i ; ++j) {
            aa[i][j]=(unsigned long long)aa[i-1][j]+(unsigned long long)aa[i-1][j-1];
        }
        aa[i][i]=1ull;
    }
}
int main()    //
{
    int a;
    jisuan();
    scanf("%d",&a);
    while (a--)
    {
        int m,n;
        scanf("%d%d",&n,&m);
        if (m>n) printf("You're kidding me!\n");
        else
            printf("%llu\n",aa[n][m]);
    }
}



//法二：递归计算，适合计算单个组合数
#include<stdio.h>
#include<string.h>

long long fun1(int m, int n) {
    if (n == 0 || n == m) {
        return 1ll;
    } else {
        return fun1(m - 1, n) + fun1(m - 1, n - 1);
    }
}
int main() {    //
    int m = 3, n = 2;
    long long resFact1 = fun1(m, n);
    printf("%lld\n", resFact1);
    return 0;
}



