
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[100][3];int b;
int cmp0(const void* p1, const void* p2) {  //降序排列     //按照数组a的第0列排序
    double* abc = (double*)p1, * abcd = (double*)p2;
    if (abc[0] > abcd[0])return -1;
    else if (abc[0] < abcd[0]) return 1;
    else return 0;
}
int cmp1(const void* p1, const void* p2) {  //降序排列      //按照数组a的第1列排序
    double* abc = (double*)p1, * abcd = (double*)p2;
    if (abc[1] > abcd[1])return -1;
    else if (abc[1] < abcd[1]) return 1;
    else return 0;
}
int cmp2(const void* p1, const void* p2) {  //升序排列       //按照数组a的第2列排序
    double* abc = (double*)p1, * abcd = (double*)p2;
    if (abc[2] < abcd[2])return -1;
    else if (abc[2] > abcd[2]) return 1;
    else return 0;
}
void paixu(int aaa[][3], int n)    //3根据实际数组的列数调整
{int begin,end,panduan=0;
    qsort(aaa, n, sizeof (aaa[0]), cmp0);   //按照数组a的第0列优先排序
    for (int i = 0; i < n-1; ++i) {
        if (aaa[i][0] == aaa[i + 1][0])                       //与第一次排列的列保持一致
        {
            if (panduan==0)
            {panduan=1;begin=i;}
        }
        else {
            if (panduan==1)
            {panduan=0;end=i;
                qsort(aaa + begin, i - begin + 1, sizeof (aaa[0]), cmp1);  //按照数组a的第1列次排序

            }
        }
    }
    if (panduan==1)
    {panduan=0;
        qsort(aaa + begin, n - 1 - begin + 1, sizeof (aaa[0]), cmp1);}       //按照数组a的第1列次排序
    for (int i = 0; i < n-1; ++i) {
        if (aaa[i][0] == aaa[i + 1][0] && aaa[i][1] == aaa[i + 1][1])   //与第一次排列第二次排列的列保持一致
        {
            if (panduan==0)
            {panduan=1;begin=i;}
        }
        else {
            if (panduan==1)
            {panduan=0;end=i;
                qsort(aaa + begin, i - begin + 1, sizeof (aaa[0]), cmp2);//按照数组a的第2列次次排序
            }
        }
    }
    if (panduan==1)
    {panduan=0;
        qsort(aaa + begin, n - 1 - begin + 1, sizeof (aaa[0]), cmp2);     //按照数组a的第2列次次排序
    }  //其他重排序依次类推
}

int main(){
    int n;

    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    paixu(a,n);     //排序的数组要是全局数组
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
}