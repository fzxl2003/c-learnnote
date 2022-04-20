/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4230612
 Created at: Thu Mar 24 2022 23:41:02 GMT+0800 (China Standard Time)
 Problem_id: 5459	Time: 12	Memory: 1708
 题目背景
“狼人杀”已成为聚会 party 最受欢迎的桌游之一。
游戏通常会给每位玩家编号，且分为两大阵营：狼人阵营和好人阵营，狼人间知道彼此的身份，而好人之间不知道彼此的身份。
游戏最紧张的环节是白天的玩家发言，每位玩家阐述自己的想法，这时每位玩家说的话都有可能是真，也有可能是假，好人们需要明察秋毫才能赢得胜利。
图图是狼人杀新手，他很善良不会说谎，因此上帝（发牌者）给了图图一个平民身份，图图也分不清楚谁说的话是真的，因此上帝在每个白天过后都会告诉图图，有几名玩家说的是真话。
题目描述
这天，游戏中有两名狼人，上帝告诉图图，n 名玩家里有 m 名玩家说的是假话，并且已知图图是好人，且图图说的是真话，请你帮图图找到两名狼人吧。
输入格式
第一行三个以空格分隔的正整数 n,m,id_tutu，分别表示玩家数，说假话的玩家数，以及图图所在的座位编号；
接下来 n 行，每行一个整数 id，第 i （1≤i≤n）行表示编号为 i 的玩家对编号为 |id| 的玩家身份的评论，用正号表示好人，负号表示狼人；比如，−5 表示认为 5 号玩家是坏人，+4 表示认为 4 号玩家是好人。
输出格式
若有解，则第一行输出 Thank God I know! 接下来，按递增顺序输出 2 个狼人的编号，以一个空格分隔。如果存在多解，则输出多行，两编号中第一个编号较小的先输出，若第一个编号相同，则第二个编号较小的先输出；
若无解，输出一行 Still can't find.
*/


#include <stdio.h>
#include <math.h>
int main()
{int a[19]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};int speak[19]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},mm=0,sw=1,firstshow=0;
    int m,n,idtutu;
    scanf("%d%d%d",&n,&m,&idtutu);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&speak[i]);
    }
    if (speak[idtutu]<0)
    {a[-speak[idtutu]]=-1;
        for (int i=1;i<=n;i++)
        {mm=0;
            if (i==idtutu ||i==-speak[idtutu]) continue;
            a[i]=-1;
            for (int k = 1; k <= n; k++) {
                if (speak[k]*a[abs(speak[k])]<0)
                {mm++;}
            }
            if (m==mm)
            {if (firstshow==0) {printf("Thank God I know!\n");firstshow=1;}
                printf("%d %d\n",(i< -speak[idtutu])?i:-speak[idtutu],(i> -speak[idtutu])?i:-speak[idtutu]);
            }
            a[i]=1;
        }
    }
    else {

        for (int i = 1; i <= n; i++) {
            if (idtutu==i || speak[idtutu]==i) {a[i]=1;continue;}
            a[i]=-1;
            for (int j = i+1; j <= n; j++) {
                if (idtutu==j || speak[idtutu]==j) {a[j]=1;continue;}
                a[j]=-1;mm=0;
                for (int k = 1; k <= n; k++) {
                    if (k==idtutu) continue;
                    if (speak[k]*a[abs(speak[k])]<0)
                    {mm++;}

                }
                //if (tt==1) {a[j]=1;continue;}

                if (mm==m  )
                {
                    if (firstshow==0) {printf("Thank God I know!\n");firstshow=1;}
                    printf("%d %d\n",i,j);
                }
                //mm=0;
                a[j]=1;
            }
            a[i]=1;

        }












    }







    if (firstshow==0) printf("Still can't find.");

}