#include <stdio.h>
#include <stdlib.h>

//bsearch函数
int cmpfunc(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int values[] = { 5, 20, 29, 32, 63 ,66,63};

int main ()  //找到元素打印found，否则返回no found
{
    int *item;
    int key = 63;

    /* 使用 bsearch() 在数组中查找值 32 */
    item = (int*) bsearch (&key, values, 7, sizeof (int), cmpfunc);
    if( item != NULL )
    {
        printf("Found item = %d\n", *item);
    }
    else
    {
        printf("Item = %d could not be found\n", key);
    }

    return(0);
}


//下界二分查找  大于等于
//a: 要查找的有序数组, 默认是从小到大排序，可与qsort配合使用
//lo, hi: 要查找的范围是从a[lo]到a[hi]之间(包含a[lo]和a[hi])
//val: 要查找的值
//返回的值: 找到的元素在数组a中的下标
//如果所有数都小于val,则返回hi+1
int lower_bound(int a[], int lo, int hi, int val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;}


//上界二分查找  严格大于
//a: 要查找的有序数组, 默认是从小到大排序  可与qsort配合使用
//lo, hi: 要查找的范围是从a[lo]到a[hi]之间(包含a[lo]和a[hi])
//val: 要查找的值
//返回的值: 找到的元素在数组a中的下标
//如果所有数都小于等于val,则返回hi+1
int upper_bound(int a[], int lo, int hi, int val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;}
    return lo;}

    //下界二分查找 查询数值是否存在，并返回第一个下标
#include<stdio.h>
int lower_bound(int a[], int lo, int hi, int val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int n, m;
int a[1919810], x;
int pos;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);//从a[1]开始读入 读到a[n]
    while (m--) {
        scanf("%d", &x);
        pos = lower_bound(a, 1, n, x);//下界二分查找的下标 注意起点是1 终点是n
//如果是从a[0]读到a[n-1] 那么上面的函数就应该传入0和n-1才对
        if (a[pos] == x) printf("%d\n", pos);//相等:我们找到了所求解
        else printf("-1\n");//大于:要查找的值没有出现过
    }
}


//用bsearch实现lower_bound和upper_bound

/*
 *
#include<stdio.h>
#include<stdlib.h>
int A[100005];  // 示例全局数组
// 查找首个不小于待查元素的元素的地址
int lower(const void *p1, const void *p2) {
int *a = (int *)p1;
int *b = (int *)p2;
if ((b == A || compare(a, b - 1) > 0) && compare(a, b) > 0)
  return 1;
else if (b != A && compare(a, b - 1) <= 0)
return -1;  // 用到地址的减法，因此必须指定元素类型
else
return 0;
}
// 查找首个大于待查元素的元素的地址
int upper(const void *p1, const void *p2) {
int *a = (int *)p1;
int *b = (int *)p2;
if ((b == A || compare(a, b - 1) >= 0) && compare(a, b) >= 0)
  return 1;
else if (b != A && compare(a, b - 1) < 0)
return -1;  // 用到地址的减法，因此必须指定元素类型
else
return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++)
    {scanf("%d",&A[i]);}

int k;
while(scanf("%d",&k)!=EOF)
{
int *temp1=bsearch(&k,A,n,sizeof(int),lower);
if(temp1==NULL)
{
temp1=A+n;
}
int *temp2=bsearch(&k,A,n,sizeof(int),upper);
if(temp2==NULL)
{
temp2=A+n;
}
printf("%d %d\n",temp1-A,temp2-A);
}
}
 */
