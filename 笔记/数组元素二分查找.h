/*
 数组线性查找
 1.实例
  int find(int x[],int key,int size)
  {
     for (int j=0;j<size;j++)
     {
           if (x[j]==key)
           return j;
     }
     return -1;
  }



 数组二分查找
 一.函数bsearch()
 1.函数声明:
   void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
 2.参数
       key -- 指向要查找的元素的指针，类型转换为 void*。          在要查找的变量前加&
       base -- 指向进行查找的数组的第一个对象的指针，类型转换为 void*。     写入要搜索的数组名称
       nitems -- base 所指向的数组中元素的个数。                        要搜索数组的元素个数（可根据需要搜索的范围调整）
       size -- 数组中每个元素的大小，以字节为单位。                       可以使用sizeof(),比如数组为int类型，可写sizeof(int)
       compar -- 用来比较两个元素的函数                                写入函数名，具体函数见下
 int cmpfunc(const void * a, const void * b)
{   return ( *(int*)a - *(int*)b );}    //目前可用
 或
 int cmpfunc(const void * a, const void * b) {
   int* a = (int*)p1, * b = (int*)p2;
   if (*a < *b)return -1;
      else if (*a > *b) return 1;
      else return 0;  }

二、下界二分查找
 lower_bound 在一个有序的序列中，找到第一个大于等于某个数的值
 1.条件：数组升序排列
 2.返回值：数组中从左到右第一个大于等于某值的下标
 3.代码：
    //下界二分查找
    //a: 要查找的有序数组, 默认是从小到大排序
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
4.具体例子如下:
        假如说我们要查找的有序数列为{1,2,2,2,3,5} 此时假定数组第一个元素的下标为1
        在查找 的时候，那么我们此时返回的下标就是2 (注意：只需要找到第一个)
        在查找 的时候，那么我们此时返回的下标就是5
        在查找 的时候，那么我们此时返回的下标就是6

三、upper_bound 上界二分查找
 upper_bound 在一个有序的序列中，找到第一个严格大于某个数的值
1.条件：数组升序排列
2.返回值：数组中从左到右第一个严格大于某值的数值的数组下标
3.代码：
    //上界二分查找
    //a: 要查找的有序数组, 默认是从小到大排序
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
4.具体例子如下:
假如说我们要查找的有序数列为 此时假定数组第一个元素的下标为{1,2,2,2,3,5}
在查找1 的时候，那么我们此时返回的下标就是2 (注意：这里要找的是第一个严格大于的)
在查找3 的时候，那么我们此时返回的下标就是6
在查找5 的时候，那么我们此时返回的下标就是7
(这个下标不存在，他反应的就是数列里的所有数都不大于5 ，返回的是下标，所以也不需要担心数
组越界)





 */