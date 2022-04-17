/*
 一维数组的定义
 1.定义语法：<类型> <数组名> [<元素个数>]  int a[50]
  元素个数必须为大于0的整型常量表达式
 2.数组的使用
    <数组名> [<数组下标>]
    数组下标 从0开始，到n-1结束(n为元素个数) 如 int a[50]   下标范围为0~49
 3.数组的初始化
  全局数组各个元素初始值为0
  局部数组各个元素初始值不确定
  初始化例子  int a[6]={1,2,3,4,5,6};
  如果{}中的数据数量少于数组元素数量，后面的元素会被初始化为0
  如果{}中的数据数量多于数组元素数量，编译器报错
  数组若初始化，[]中可不加数字，将根据初始化的元素数量来定义元素个数



 一维数组的使用
 1.获取数组元素数量
   =sizeof(x)/sizeof(x[0])
   sizeof(x)代表数组x占用的字节数
   sizeof(x[0])代表元素x[0]占用的字节数
   两者相除即为数组元素数量
   #define NumberOf(x) (sizeof(x)/sizeof(x[0]))
 2.元素使用
   <数组名>[<下标>]  如a[10]


 数组函数
 memcpy()    数组复制
 memset()    数组替换
 qsort()     数组快排
 maopao()    冒泡排序（自有函数）
 数组复制
1. 实例： int copy()
 {
 int a[10],b[10],i;
 for (i=0;i<10;i++)
 {
    b[i]=a[i];
 }
 return 0;
 }
 2.复制函数memcpy()
    1.定义： void *memcpy( void *dest,const void *src,size_t count);
         void *dest为被复制数据的地址  const void *src为数据原地址   size_t count为需要复制的字节数
    2.实例：上述实例等价于memcpy(b,a,sizeof(a));
 数组替换
1.函数：memset()
2.函数声明:void *memset(void *s,int ch,size_t n);
  void *s为将要改变的数据的地址（通常为数组）  ch为替换的数字  n为替换个数
3.函数作用：将s中当前位置后面的n个字节用ch替换并返回s(指针),常用于清零



  数组元素查找
见数组元素二分查找



  数组排序
//仅适用于int数组
1.函数qsort()
  1.库： stdlib.h
  2.声明：void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
  3.参数：
    base -- 指向要排序的数组的第一个元素的指针。
    nitems -- 由 base 指向的数组中元素的个数。
    size -- 数组中每个元素的大小，以字节为单位。
    compar -- 用来比较两个元素的函数
    比如：qsort(values, 5, sizeof(int), cmpfunc);
     values为要排序的数组名，5代表要排前五个元素，sizeof(int)代表元素大小，cmpfunc为附加函数
  4.附加函数cmpfunc
     升序排列
        int cmp(const void* p1, const void* p2) {
    int* a = (int*)p1, * b = (int*)p2;
    if (*a < *b)return -1;//a要排在b前面时，返回负数值
    else if (*a > *b) return 1;//a要排在b后面时，返回正数值
    else return 0;//不需要变动时，返回0
}
    降序排列
        int cmp(const void* p1, const void* p2) {
    int* a = (int*)p1, * b = (int*)p2;
    if (*a > *b)return -1;//a要排在b前面时，返回负数值
    else if (*a < *b) return 1;//a要排在b后面时，返回正数值
    else return 0;//不需要变动时，返回0
}
 5.实例见qsort.h
 6.平均速度 O(nlogn)
2.冒泡排序（适用于所有数组）（但效率低）
 见冒泡排序法.h



 数组作为函数使用
1.参数表中如果包含数组，在该参数后添加[]即可，无需说明该数组元素数量
2.函数内部不能从参数本身直接判断数组大小，如作为参数的数组的大小不确定，应当使用附加参数说明数组的大小
3.函数对参数数组的修改效果是全局性的
4.函数声明  int hanshu(double [],double [],int);   //int作用：见2
5.函数调用  hanshu(a,b,c);
6.函数本体  int hanshu(a[],b[],c) {}

 例6-9 选择排序






 */