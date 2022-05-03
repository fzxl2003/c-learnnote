/*
题目描述
现在有好多好多行字符串，请你找出前20长的字符串，并按照输入顺序输出；如果第20长的字符串有多个，输出先出现的。

输入格式
多行输入，每行一个字符串 s ；
保证字符串 s 的长度 len 满足 1≤len≤1000 ，保证输入的字符串总数 n 满足 20≤n≤100000；
字符串仅包含可见字符。

输出格式
按照输入的顺序，输出前20个最长的字符串。

输入样例
as
Ren jiangyi
Ai chizhujiaodezhujiao
cbj
Great-designer
JJJ
Lucienlrq
Shi Shangzuiqiangdexingjierxuanshou
wqhgg
Long Juanfeng
lxy
ljh
Guo Lichen
zymdka
yuruzan
Wang Wenhan
cbd
Li Nanbing
SongYou
Bodan's dog
casual name
I don't know


输出样例
Ren jiangyi
Ai chizhujiaodezhujiao
cbj
Great-designer
JJJ
Lucienlrq
Shi Shangzuiqiangdexingjierxuanshou
wqhgg
Long Juanfeng
lxy
ljh
Guo Lichen
zymdka
yuruzan
Wang Wenhan
Li Nanbing
SongYou
Bodan's dog
casual name
I don't know
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (a[0] > b[0])return -1;
    else if (a[0] < b[0]) return 1;
    else return 0;
}
int cmp1(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (a[1] < b[1])return -1;
    else if (a[1] > b[1]) return 1;
    else return 0;
}
int upper_bound(int a[][3], int lo, int hi, int val) {
    if (val <= a[hi][0]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi][0] >= val) lo = mi + 1;
        else hi = mi;}
    return lo;}
int main()
{
    char str[20][1009]={0};
    int leni[20][3]={0};
    int lenmin=999999;int lenminn;
    char str1[1009];int num=0;
    while (gets(str1)!=NULL)
    {

        int len= strlen(str1);
        if (num<20)
        {strcpy(str[num],str1);
            leni[num][0]=len;leni[num][1]=num;leni[num][2]=num;
            if (len<lenmin) {lenmin=len;lenminn=num;}
            num++;continue;
        }
        if (num==20){
            qsort(leni,20,sizeof (leni[0]),cmp);
            lenmin=leni[19][0];lenminn=leni[19][2];}
        if (len>lenmin)
        {
            strcpy(str[leni[19][2]],str1);
            leni[19][0]=len;leni[19][1]=num;
            num++;
            qsort(leni,20,sizeof (leni[0]),cmp);
            lenmin=leni[19][0];lenminn=leni[19][2];
        }
        //qsort(leni,20,sizeof (leni[0]),cmp);

    }
    qsort(leni,20,sizeof (leni[0]),cmp1);
    for (int i = 0; i < 20; ++i) {
        printf("%s\n",str[leni[i][2]]);
    }
}