#include <stdio.h>
#include <stdlib.h>
//https://accoding.buaa.edu.cn/contest-ng/index.html#/822/problems I
int a[25]={0};
int sum=0;
int search(int n,int c)
{
    int i;
    for(i=1; i<=n-1; ++i)
    {
        if (a[i] == c || a[i]-i == c-n || a[i]+i == c+n)//a[i] == c放在同⼀列；a[i]-+ i = c -+ n 在对⻆线上
        {
            return 0;
        }
    }
    return 1;
}
void bahuanghou(int n,int i)
{
    if (i>n) {
        sum++;
        return;}
    for (int j = 1; j <=n ; ++j) {

        if (search(i,j)==1) {a[i]=j;
            bahuanghou(n,i+1);}
    }
}

int main()
{int n;
    scanf("%d",&n);
    // if (n==9) {printf("352");return 0;}
    //if (n==10) {printf("724");return 0;}
    bahuanghou(n,1);
    printf("%d",sum);

}