/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4232006
 Created at: Sat Mar 26 2022 09:20:08 GMT+0800 (China Standard Time)
 Problem_id: 5391	Time: 61	Memory: 1668
*/

#include <stdio.h>
#include <string.h>
char aa[500]={0},bb[500]={0};

void zifuchuannumadd()
{int af[1000]={0},bf[1000]={0},c[1000];
    int f;int kk=0;
    int i1,an,bn,k;
    an=strlen(aa);
    bn= strlen(bb);
    k=an>bn?an:bn;                         //找a,b中最长字符串，作为循环加法的依据
    c[0]=0;
    //int f=0;
    for(i1=0;i1<an;i1++)
        af[i1]=aa[an-i1-1]-'0';
    for(i1=0;i1<bn;i1++)
        bf[i1]=bb[bn-i1-1]-'0';           //将字符串转为数字

    for(i1=0;i1<k;i1++)
    {
        c[i1]+=(af[i1]+bf[i1])%10;
        if (c[i1]>=10) {c[i1]-=10;kk=1;}
        c[i1+1]=(af[i1]+bf[i1]+kk)/10;   //如果超过十，该位退十，更高一位加一
        kk=0;
    }
    if(c[i1]!=0)
    {k++;kk=1;}                        //计算后，如果多了一位，将输出位数增加一位
    for(i1=k-1;i1>=0;i1--)
    {
        printf("%d",c[i1]);
    }
    printf("\n");
    for(i1=0;i1<k;i1++)
        af[i1]=bf[i1]=0;

}
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s %s",&aa,&bb);
        zifuchuannumadd();
    }
}