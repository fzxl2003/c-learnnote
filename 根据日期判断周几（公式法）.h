/*
https://accoding.buaa.edu.cn/contest-ng/index.html#/820/problems
输入格式
n+1行。
第1行为总日期数n
第2行至n+1行每行输入一个特殊日期信息，格式为yyyymmdd。（如2022年3月23日应输入为20220323）

输出格式
多行，每行输出两个整数，分别是星期i的数字缩写和在星期i的特殊日期总数，中间用空格分开。
按照星期日一二三四五六的顺序依次输出。如果星期i没有特殊日期，那么不输出这行。
 */

#include <stdio.h>
int main() {
    int a[7]={0};
    int c, y, m, w, d, longday = 1;
    int n;
    scanf("%d",&n);
    while (n--) {

        scanf("%d", &longday);
        y = longday / 10000;
        m = (longday % 10000) / 100;
        d = longday % 100;
        if (m < 3) {
            y--;
            m += 12;
        }
        c = y / 100;
        y = y % 100;
        w = (y + y / 4 + c / 4 - 2 * c
             + (26 * (m + 1)) / 10 + d - 1) % 7;
        if (w < 0) w += 7;
        a[w]++;


    }
    for (int i = 0; i < 7; ++i) {
        if (a[i]!=0) printf("%d %d\n",i,a[i]);
    }
    return 0;
}