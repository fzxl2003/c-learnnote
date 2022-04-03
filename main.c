#include<stdio.h>
int arr[25];//arr记录每⼀⾏⼤师的坐标
int all;
int total;//合法数
int isPlaceOK(int n, int c)//检查位置是否可以放，c是将要放置的位置
{
    int i;
    for(i=1; i<=n-1; ++i)
    {
        if (arr[i] == c || arr[i]-i == c-n || arr[i]+i == c+n)//a[i] == c放在同⼀列；a[i]-+ i = c -+ n 在对⻆线上
        {
            return 0;
        }
    }
    return 1;
}
void addMaster(int n)//n为当前⾏
{
    if(n>all)
    {
        total++;
        return;
    }
    int i;
    for (i=1; i<=all; ++i)//i从第1列到第all列遍历
    {
        if (isPlaceOK(n, i)){
            arr[n]=i;//如果可以放置，就把⼤师放在第n⾏第i列
            addMaster(n+1);
        }
    }
}
int main()
{
    total=0;
    scanf("%d",&all);
    addMaster(1);//从第⼀⾏开始放置
    printf("%d\n",total);
}