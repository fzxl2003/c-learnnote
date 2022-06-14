/*
 题目描述
按照给定的顺序计算n个矩阵的乘积。

输入
第一行为一个正整数n(2⩽n⩽10)，表示矩阵的个数。
第二行2n个整数，分别为a1,b1,a2,b2,...,an,bn,（1⩽a1,b1,a2,b2,...,an,bn⩽10)，其中ai表示第i个矩阵的行数，bi表示第i个矩阵的列数，保证有bm−1=am ，(2⩽m⩽n）。
之后有a1+a2+...+an行，首先的a1行每行有b1个非负整数，表示第一个矩阵，后面的矩阵同理，矩阵中的每一个元素不超过100。

输出
程序的输出应该是一个a1∗bn的矩阵。
输出a1行，每行有bn个非负整数，两个整数之间用空格隔开。
保证输出结果在long long范围内。

输入样例
3
2 2 2 3 3 3
1 0
0 1
0 3 0
1 0 1
1 0 0
0 1 0
0 0 1
输出样例
0 3 0
1 0 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int nowhangshu,nowlieshu;
long long result[103][103];
void jisuan(int a1,int b1,int a2,int b2,long long m[][103],long long n[][103])
{
    long long num;

    for (int i = 1; i <=a1 ; ++i) {
        for (int j = 1; j <=b2 ; ++j) {
            num=0;
            for (int k = 1; k <=b1 ; ++k) {
                num+=m[i][k]*n[k][j];

            }
            result[i][j]=num;
        }
    }
    memcpy(m,result,103*103*8);

}

int main() {
    int n;int hangshu[13][2];int moren=0;long long nn[103][103];long long mm[103][103];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&hangshu[i][0],&hangshu[i][1]);
    }
    nowhangshu=hangshu[0][0];nowlieshu=hangshu[0][1];
    for (int k = 1; k <=nowhangshu ; ++k) {
        for (int j = 1; j <=nowlieshu ; ++j) {
            scanf("%lld",&mm[k][j]);
        }
    }
    for (int i = 1; i <n ; ++i) {
        int a2=hangshu[i][0],b2=hangshu[i][1];
        for (int k = 1; k <=a2 ; ++k) {
            for (int j = 1; j <=b2 ; ++j) {
                scanf("%lld",&nn[k][j]);
            }
        }
        jisuan(nowhangshu,nowlieshu,a2,b2,mm,nn);
        nowlieshu=b2;
    }
    for (int k = 1; k <=nowhangshu ; ++k) {
        for (int j = 1; j <=nowlieshu ; ++j) {
            printf("%lld ",result[k][j]);
        }
        printf("\n");
    }

}


/*
 两个实矩阵乘法

 Author: 潘宇恒
 Result: AC    Submission_id: 4310910
 Created at: Wed Apr 13 2022 19:44:57 GMT+0800 (China Standard Time)
 Problem_id: 5565    Time: 10    Memory: 1764

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int a1,b1,a2,b2;int m[103][103]={0},n[103][103]={0},num;
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    for (int i = 1; i <=a1 ; ++i) {
        for (int j = 1; j <=b1 ; ++j) {
            scanf("%d",&m[i][j]);
        }
    }
    for (int i = 1; i <=a2 ; ++i) {
        for (int j = 1; j <=b2 ; ++j) {
            scanf("%d",&n[i][j]);
        }
    }
    for (int i = 1; i <=a1 ; ++i) {
        for (int j = 1; j <=b2 ; ++j) {
            num=0;
            for (int k = 1; k <=b1 ; ++k) {
                num+=m[i][k]*n[k][j];
            }
            printf("%d ",num);
        }
        printf("\n");
    }
}
 */