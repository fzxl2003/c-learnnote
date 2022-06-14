/*
 题目描述
你和对手赛马,双方都有n 匹马,每匹马的能力数值为ai(0≤ai≤1000),由你来规定双 方马匹出场的顺序,请编程求出你最多能赢多少场。对局时你的马能力值大于对方的算赢,相 等则算平手。

输入
第一行,一个整数n(1≤n≤100);接下来的两行,每行n 个整数a1,a2,…,an 代表 每匹马的能力值,用空格分隔;第二行是你的马的能力指数;第三行则是对手的马的能力指数。

输出
一行,一个整数,表示你最多胜利的场次。

输入样例
5
5 4 3 2 1
1 2 3 4 5
输出样例
4
 */

#include<stdio.h>
#include<stdlib.h>
/* 定义comp以实现快排函数qsort，从大到小排序*/
int comp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    int num;

    scanf("%d", &num);/*读取data.in文件，获取马匹数*/


    int tj[1001], qw[1001];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &tj[i]);/*获取田忌马速*/
    }
    for (int j = 0; j < num; j++)
    {
        scanf("%d", &qw[j]);/*获取齐王马速*/
    }
    /*接下来是贪心算法的内容*/
    qsort(tj, num, sizeof(tj[0]), comp);//对田忌马速排序
    qsort(qw, num, sizeof(qw[0]), comp);//对齐王马速排序
    int a = 0;
    int b = 0;
    int m = num - 1;
    int n = num - 1;
    int t = 0;
    while (a <= m)//开始比试
    {
        if (tj[m] > qw[n])//如果田忌的劣马胜过齐王劣马，赢一次
        {
            m--;
            n--;
            t++;
        }
        else if (tj[m] < qw[n])//如果劣马略逊一筹，则消耗齐王一匹好马，输一局
        {
            m--;
            b++;
            //t--;
        }
        else if (tj[a] > qw[b])//如果田忌好马胜过齐王好马，赢一次
        {
            a++;
            b++;
            t++;
        }
        else//田忌劣马换掉齐王好马，绝对贪心
        {
            if (tj[m] > qw[b])//田忌最劣马换掉齐王好马，赢一次
            {
                b++;
                m--;
                t++;
            }
            else if (tj[m] < qw[b])// 田忌最劣马换掉齐王好马，输一次
            {
                b++;
                m--;
                //t--;
            }
            else// 平局，不比了
            {
                b++;
                m--;
            }
        }
    }
    printf("%d\n", t);/*将结果输出至answer.out文件*/
    //fscanf(in, "%d", &num);/*读取下一组数据的马匹数*/



}
