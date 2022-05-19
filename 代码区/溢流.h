/*
 I 溢流

时间限制：1000ms   内存限制：65536kb
题目描述
在一个 m×n 的网格中，每个格子是边长为10m的正方形，网格四周是无限高的墙壁。
现在网格内部开始涨水，这里假设水只会从最低处的网格开始累积，当有多个格子海拔高度相同时，认为它们是联通的(即同时开始积水)。
现在，给出每个格子的海拔高度，要求你输出降水量为V时，水平面的海拔高度

输入
第一行，两个整数m和n
第2到m+1行，每行n个用空格隔开的整数 hij ，表示该网格的海拔高度
之后多行输入，每行一个整数 Vk，表示一次需要查询的降水量，单位为 m3
输出
对于每一个询问 Vk ，请输出一行，一个保留到小数点后六位的浮点数（%lf即可），表示水平面高度（单位为m）
SPJ提示：采用不同的计算方式，可能会有精度误差，故只要你的答案与标准答案相差在 ±2×10−6 范围内即被认为是正确答案

输入样例
3 3
25 37 45
51 12 34
94 83 27
10000
100000
输出样例
46.666667
156.444444
数据范围
1≤m,n≤800

0≤hij≤231−1
1≤ 查询次数 ≤105
0≤Vk≤107


HINT
注意题目假设，可以不用二维数组来储存高度
特别的，注意算法效率问题，避免纯模拟





题⽬分析
⾸先，注意到题⽬假设，将⽹格⾼度从⼩到⼤排序后进⾏处理
从原理上，⽔从最低处开始累积，每到⼀个新的⽔平⾯⾼度，⾼度的变化速率就会不同(因为底⾯积增加了，相同体
积对应的⾼度不同)
考虑到算法效率问题，我们采⽤建表+⼆分查找的⽅式来确定当前输⼊⽔量的底⾯积，当然，由于本题的数据范围
存在⼀些有趣的特点，⼤家也可以考虑使⽤哈希+线性查找等⽅法进⾏优化，也能通过本题。
示例代码


 */


#include<stdio.h>
#include<stdlib.h>
long long v[640005];//体积
int h[640005];//⾼度
int n,m;
int cmp(const void *a , const void *b)
{
    return *(int *)a - *(int *)b; //为什么可以这么写？注意数据范围
}
//求下界，既在单调递增序列中查找>=index的数中最⼩的⼀个（即index或index的后继）
int lower_bound(long long index)//这⾥⽤int也⾏，懒得改了
{
    int low = 1;
    int high = m*n;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] >=index) high=mid;
        else low = mid + 1;
    }
    return low;
}
int main(){
    int i,j;
    long long total;
    int fo;
    double ans;
    scanf("%d%d",&m,&n);
    for(i=0;i<m*n;i++)
        scanf("%d",&h[i]);
    qsort(h,m*n,sizeof(h[0]),cmp);
    h[m*n] = 2147483647;
    for(i=1;i<=m*n;i++)
        v[i] = (long long)100*i*(h[i]-h[i-1])+v[i-1];
    while(scanf("%lld",&total)!=EOF)
    {
        fo = lower_bound(total);
        ans = h[fo-1]+(total - v[fo-1]) /100.0/fo;
        //⾼度=上⼀个⾼度+（总⽔量-上⼀个⾼度对应的⽔量）/当前底⾯积
        printf("%lf\n",ans);
    }
}