//H 全排列组合  https://accoding.buaa.edu.cn/contest-ng/index.html#/822/problems
#include <stdio.h>
#include <stdlib.h>
int search[5]={0};
int a[5]={0};
int ssearch(int m)
{
    for (int i = 0; i < 5; ++i) {
        if (search[i]==0) return m+i;
    }
    return -1;
}
void print(int l)
{
    for (int i = 0; i <= l; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void pailie(int m,int n,int i)
{int aa;
    if (i==n+1)
    { print(n-m);
        return;}
    for (int j = m; j <= n; j++) {
        if (search[j-m]!=1){
            a[i-m]=j;
            //printf("%d ",j);
            search[j-m]=1;
            pailie(m,n,i+1);
            search[j-m]=0;
        }}
}


int main()
{int m,n;
    scanf("%d%d",&m,&n);  //生成m-n这些数的所有排列 ，m-n<=5
    pailie(m,n,m);

}