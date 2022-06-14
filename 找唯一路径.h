/*
 题目背景
狗和驴是一对非常好的朋友，可惜天有不测风云，驴有旦夕祸福，驴被一个坏蛋抓起来锁在笼子里了，狗焦急不已，可是狡猾的坏蛋在笼子面前放了一个迷宫，狗必须以最快速度在坏蛋出去打猎的时候解救朋友，机会只有一次，你能帮帮它嘛？

题目描述
迷宫均为n阶矩阵的形式并由0和1两种数字组成，0表示道路，1表示障碍，已知狗(G)和驴(L)的初始位置，且数据保证有且仅有唯一的一条道路可以让G找到L。

输入
第一行一个数 n 表示 n 阶矩阵迷宫
第二行是2个非负整数对(G1,G2),(L1,L2)表示G和L在迷宫中的位置(左上角为(0，0))
接着输入 n 阶迷宫

输出
n 阶矩阵迷宫，用S(Step)来标注狗能够找到驴的唯一道路

输入样例
12
0 0 11 11
G00000011111
110111011111
110111000011
110011111011
110111111011
110000001011
101111011011
101000011011
100010111011
111010001001
111011111101
10001111110L
输出样例
GSSSSSS11111
110111S11111
110111SSSS11
110011111S11
110111111S11
110000001S11
101111011S11
101000011S11
100010111S11
111010001SS1
1110111111S1
1000111111SL
数据范围
10≤n≤200
 */



//题解代码
#include<stdio.h>
#include<string.h>
char maze[105][105];
int book[10005][2];
int D[2],L[2];
int get(int x,int y,int n)
{
    if(x<(n-1)&&maze[x+1][y]=='L')return 1;
    else if(y<(n-1)&&maze[x][y+1]=='L')return 1;
    else if(x>0&&maze[x-1][y]=='L')return 1;
    else if(y>0&&maze[x][y-1]=='L')return 1;
    return 0;
}
void Find_way(int x,int y,int n,int step,int last_x,int last_y)
{
    book[step][0]=x;
    book[step][1]=y;
    //printf("%d%d\n",x,y);
    if(get(x,y,n))
    {
        for(int i=1;i<=step;i++)
        {
            if(maze[book[i][0]][book[i][1]]=='0')maze[book[i][0]][book[i][1]]='S';
        }
        return;
    }
    book[step][0]=x;
    book[step][1]=y;
    step++;
    if(x<(n-1)&&maze[x+1][y]=='0'&&x+1!=last_x)Find_way(x+1,y,n,step+1,x,y);
    if(y<(n-1)&&maze[x][y+1]=='0'&&y+1!=last_y)Find_way(x,y+1,n,step+1,x,y);
    if(x>0&&maze[x-1][y]=='0'&&x-1!=last_x)Find_way(x-1,y,n,step+1,x,y);
    if(y>0&&maze[x][y-1]=='0'&&y-1!=last_y)Find_way(x,y-1,n,step+1,x,y);
    book[step][0]=0;
    book[step][1]=0;
    return;
}
int main() {
    int n, i, j;
    char laji[5];
    scanf("%d", &n);
    scanf("%d%d%d%d", &D[0], &D[1], &L[0], &L[1]);
    gets(laji);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            maze[i][j] = getchar();
        gets(laji);
    }
    Find_way(D[0], D[1], n, 0, D[0], D[1]);
    for (i = 0; i < n; i++) {
        puts(maze[i]);
    }
}



//仅过一个测试点的代码
/*Author: 潘宇恒
        Result: WA	Submission_id: 4509741
Created at: Thu Jun 09 2022 14:12:00 GMT+0800 (China Standard Time)
Problem_id: 5463	Time: 3	Memory: 1632
*/

#include <stdio.h>
char juzhen[219][219];

void scjuzhen(int n)
{
    for (int i = 0; i <= n+1; ++i) {
        juzhen[0][i]='1';
        juzhen[i][0]='1';
        juzhen[n+1][i]='1';
        juzhen[i][n+1]='1';
    }
    getchar();
    for (int i = 1; i <=n ; ++i) {
        gets(juzhen[i]+1);
    }
}
int find(int n,int g1,int g2,int l1,int l2,int x,int y,int fangxiang)
{
    if (x==l1&&y==l2)
    {return 1;}
    if (juzhen[x][y-1]!='0'&&juzhen[x][y+1]!='0'&&juzhen[x-1][y]!='0'&&juzhen[x+1][y]!='0')
    {return 0;}
    if (juzhen[x-1][y]=='0'&&fangxiang!=1)
    {juzhen[x-1][y]='S';
        int l= find(n,g1,g2,l1,l2,x-1,y,3);
        if (l==0)
            juzhen[x-1][y]='0';
        else return 1;
    }
    if (juzhen[x+1][y]=='0'&&fangxiang!=3)
    {juzhen[x+1][y]='S';
        int l= find(n,g1,g2,l1,l2,x+1,y,1);
        if (l==0)
            juzhen[x+1][y]='0';
        else return 1;
    }
    if (juzhen[x][y-1]=='0'&&fangxiang!=4)
    {juzhen[x][y-1]='S';
        int l= find(n,g1,g2,l1,l2,x,y-1,2);
        if (l==0)
            juzhen[x][y-1]='0';
        else return 1;
    }
    if (juzhen[x][y+1]=='0'&&fangxiang!=2)
    {juzhen[x][y+1]='S';
        int l= find(n,g1,g2,l1,l2,x,y+1,4);
        if (l==0)
        {juzhen[x][y+1]='0';}
        else return 1;
    }
    return 0;
}

int main()
{
    int n;int g1,g2,l1,l2;
    scanf("%d%d%d%d%d",&n,&g1,&g2,&l1,&l2);
    scjuzhen(n);
    juzhen[l1+1][l2+1]='0';
    find(n,g1+1,g2+1,l1+1,l2+1,g1+1,g2+1,0);
    juzhen[l1+1][l2+1]='L';
    for (int i = 1; i <=n ; ++i) {
        puts(juzhen[i]+1);
    }

}
