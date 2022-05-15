/*
G 求最大斜率plus
题目描述
大家还记得E1中的求最大斜率吗
小林今天突然想起这道题目有更优秀的做法，于是他扩大了一下数据范围。
对于给定坐标的 n 个点，求任意两点所连成的直线的最大斜率。

输入
第一行一个整数 n ，表示点的个数。
接下来 n 行，每行两个正整数 x,y，描述每个点的横纵坐标。

输出
一行一个实数表示答案，保留小数点后 3 位。

输入样例
3
1 2
2 3
3 4
输出样例
1.000
数据范围
2≤n≤5×10^5
0<xi,yi≤10^7
数据保证任意两点的横坐标均不相同
 */

//读入后先排序，再比较
#include <stdio.h>
#include <stdlib.h>

typedef struct fjdsklfj{
    int x;
    int y;
}inf;
int cmp(const void *p1, const void *p2)
{
    const inf *a1=(inf *)p1;
    const inf *a2=(inf *)p2;
    if (a1->x<a2->x)
        return 1;
    else if (a1->x>a2->x)
        return -1;
    else
    {
        if (a1->y<a2->y)
            return 1;
        else if (a1->y>a2->y)
            return -1;
        else
            return 0;
    }
}
inf dian[500004];
int main()
{

    int n;

    scanf("%d",&n);
    for (int i=0;i<n;i++)
    { scanf("%d%d",&dian[i].x,&dian[i].y);}
    qsort(dian,n,sizeof (dian[0]),cmp);
    double maxsum=1.0*(dian[1].y-dian[0].y)/(dian[1].x-dian[0].x);
    for (int i = 1; i < n-1; ++i) {
        double ans=1.0*(dian[i+1].y-dian[i].y)/(dian[i+1].x-dian[i].x);
        if (ans>maxsum) maxsum=ans;
    }
    printf("%.3lf\n",maxsum);




}