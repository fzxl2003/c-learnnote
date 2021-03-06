/*
 二维数组的定义
1.定义语法：
 <类型><数组名>[<行数>][<列数>];
 <行数><列数>是两个大于0的整型常量表达式，分别定义数组两个维度的大小
 例 int a[4][6];定义了一个4行6列的int类型的二维数组
2.数组的使用
    <数组名> [<数组下标行>] [<数组下标列>]
    数组下标 从0开始，到n-1结束(n为元素个数)
3.数组的初始化
 常规：
 每一行的初始值由大括号括起来，大括号中各元素的值用逗号隔开
 不同行之间的大括号用逗号隔开，外面再用大括号括起来
 例如初始化2行12列的二维数组
 int a[2][12]={{1,2,3,4,5,6,7,8,9,10,11,12},{1,2,3,4,5,6,7,8,9,10,11,12}};
 字符串初始化：
 char a[2][12]={"1234","12345"};
 若初始化的表中的数据少于数组元素数量，则会优先赋值左上方元素，其他元素赋值0
 数组若初始化，[<数组下标行>]中可不加数字，将根据初始化的元素数量来定义行数，但[<数组下标列>]数字不能省略

 二维数组元素的使用
1.<数组名>[<行下标>][<列下标>]  如a[10][1]
2.例6-22 求y年m月d日sh是y年的第几天
3.二维数组可以看成一维数组
 对于数组a[2][10]  a[0][11]等价于a[1][1]
4.指针相关
 a  指向a[0][0]的指针
 a[1] 指向a[1][0]的指针

 */