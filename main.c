#include <stdio.h>
int a[100000]={0};
void mian3(int num,int i)
{
    for(int j=31;j>=0;j--)
    {if ((num>>j)&1)
            a[i+j]=1;
        else a[i+j]=0;}
}


int main() {
    int n,a0,c,newnum;char b;int start,now,now1,now2;
    while ((scanf("%d",&n))!=EOF)
    {
        for (int i=n-1;i>=0;i--)
        { scanf("%d",&a0);
            a[i]=a0;
            //mian3(a0, i*32);
        }
        getchar();
        scanf("%c%d",&b,&c);
        c=c%(n*32);
        if (b=='l'){
            for (int o=n-1;o>=0;o--)
            {newnum=0;
                start=(o*32-c)%(n*32);
                for (int ll=0;ll<32;ll++)
                {
                    now=(start+ll)%(n*32);
                    if (now<0) now=n*32+now;
                    now1=now/32;
                    now2=now-now1*32;
                    newnum+=(((a[now1]&(1<<now2))>>now2)<<ll);
                }
                printf("%d ",newnum);
            }


        }
        else {
            for (int o=n-1;o>=0;o--)
            {newnum=0;
                start=(o*32+c)%(n*32);
                for (int ll=0;ll<32;ll++)
                {
                    now=(start+ll)%(n*32);
                    if (now<0) now=n*32+now;
                    now1=now/32;
                    now2=now-now1*32;
                    newnum+=(((a[now1]&(1<<now2))>>now2)<<ll);
                }
                printf("%d ",newnum);
            }}printf("\n");
    }



    //while ((scanf()))
}