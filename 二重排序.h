#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (a[0] < b[0])return -1;
    else if (a[0] > b[0]) return 1;
    else return 0;
}
int cmp2(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (a[1] < b[1])return -1;
    else if (a[1] > b[1]) return 1;
    else return 0;
}
int cmp1(const void* p1, const void* p2) {  //降序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (*a > *b)return -1;
    else if (*a < *b) return 1;
    else return 0;
}
void paixu(int a[][2],int n)
{int begin,end,panduan=0;
    qsort(a,n,sizeof (a[0]),cmp);
    for (int i = 0; i < n-1; ++i) {
        if (a[i][0]==a[i+1][0])
        {
            if (panduan==0)
            {panduan=1;begin=i;}
        }
        else {
            if (panduan==1)
            {panduan=0;end=i;
                qsort(a+begin,i-begin+1,sizeof (a[0]),cmp2);
            }
        }
    }
}

int main(){
    int n;
    int a[100][2];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    paixu(a,n);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n",a[i][0],a[i][1]);
    }
}