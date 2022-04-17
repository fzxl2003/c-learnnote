/*冒泡排序法
 以升序为例    对数组多次遍历，当遇到前列数大于后列数，则两者交换顺序。直至遍历到没发生顺序交换位置

 https://accoding.buaa.edu.cn/contest-ng/index.html#/823/problems  J
 */



#include <stdio.h>
#include <stdlib.h>


void maopao(int a[],int n)  //升序
{int temp,aa=0;
    for (int i = 0; i < n-1; ++i) {
        aa=0;
        for (int j = 0; j < n-1-i; ++j) {
            if (a[j]>a[j+1])
            {temp=a[j+1];
                aa=1;
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        if (aa==0) break;
    }
}
int main()
{
    int n;int a[1002]={0};int i;
    scanf("%d",&n);
    for (i = 0; i <n ; ++i) {
        scanf("%d",&a[i]);
    }
    maopao(a,i);
    for (i = 0; i <n ; ++i) {
        printf("%d",a[i]);
    }

}