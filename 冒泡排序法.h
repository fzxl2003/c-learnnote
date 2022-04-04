/*冒泡排序法
 以升序为例
对数组多次遍历，当遇到前列数大于后列数，则两者交换顺序。直至遍历到没发生顺序交换位置

 https://accoding.buaa.edu.cn/contest-ng/index.html#/823/problems  J


 */



#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{return ( *(int*)a - *(int*)b );}
int main()
{
    int n;double a[1002]={0};
    scanf("%d",&n);
    for (int i = 0; i <n ; ++i) {
        scanf("%lf",&a[i]);
    }
    int need=1;double tmp;
    while (need)
    {
        need=0;
        for (int i = 0; i < n-1; ++i) {
            if (a[i]>a[i+1]) {tmp=a[i];a[i]=a[i+1];a[i+1]=tmp;need++;}
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%.5f\n",a[i]);
    }

}