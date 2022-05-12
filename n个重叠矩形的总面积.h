#include <stdio.h>
#include <stdlib.h>

#define MAXn 100

int n;
long long x1[MAXn+1],y1[MAXn+1];
long long x2[MAXn+1],y2[MAXn+1];
long long x[2*MAXn+1],y[2*MAXn+1];
long long S,ans;
int cmp(const void* p1, const void* p2) {  //升序排列
    long long* a = (long long*)p1, * b = (long long*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i]);
        x[2*i-1]=x1[i];
        x[2*i]=x2[i];
        y[2*i-1]=y1[i];
        y[2*i]=y2[i];
    }
    qsort(x+1,  2 * n , sizeof (long long), cmp);
    qsort(y+1,  2 * n , sizeof (long long), cmp);
    for(int i=1;i<=2*n-1;i++) //枚举每一个单位横坐标，这两句看图
        for(int j=1;j<=2*n-1;j++)  //枚举每一个单位纵坐标
        {
            S=(x[i+1]-x[i])*(y[j+1]-y[j]);
            for(int k=1;k<=n;k++) //枚举每一个矩形块
                if(x[i]>=x1[k]&&y[j]>=y1[k]&&x[i+1]<=x2[k]&&y[j+1]<=y2[k])//这句是离散化
                { ans+=S; break; }//注意这个break,用的妙
        }
    printf("%lld",ans); return 0;
}