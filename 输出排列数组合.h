#include <stdio.h>
#include <stdlib.h>
int aa[8];
int put[8];
void pailie(int m,int n,int shendu)
{
    if (shendu==n)
    {
        for (int i = 0; i < n; ++i) {
            printf("%d ",put[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= m; ++i) {
        if (aa[i]==0)
        {
            aa[i]=1;
            put[shendu]=i;
            pailie(m,n,shendu+1);
            aa[i]=0;
        }
    }
}
int main()  //给出m,n，请帮小雷枚举输出正整数1~m中取n个数的全部情况。
{   //输出格式     按从小到大的顺序输出（比较大小时优先比较靠左边的元素），每行输出一种情况
    int m,n;
    scanf("%d%d",&m,&n);
    pailie(m,n,0);

}