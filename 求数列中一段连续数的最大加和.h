/*
 求数列中一段连续数的最大加和
 https://www.cnblogs.com/conw/p/5896155.html
 动态规划递推法
 数列num中第n项及其之前数的连续最大和dp[n]=max{0，d[n-1]+num[n]}

 */


//代码

#include <stdio.h>

//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
int N, num[134217728];

int main()
{
    //输入数据
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);

    num[0] = 0;
    int ans = num[1];
    for(int i = 1; i <= N; i++) {
        if(num[i - 1] > 0) num[i] += num[i - 1];
        else num[i] += 0;
        if(num[i] > ans) ans = num[i];
    }

    printf("%d\n", ans);

    return 0;
}