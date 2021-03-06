/*
真值为1   假值为0
1.关系运算符
 < 小于   <= 小于等于  > 大于  >= 大于等于
 == 等于  != 不等于
 1.上一行优先级高于下一行
 2.对于浮点数判断==，由于误差可能实际返回值不同
   如double a=0.0
   则a==0.0返回值为0，所以在对浮点变量进行比较时，通常判断两个比较的数值是否小于某个给定的误差范围
   例如在判断x是否为0时，往往写成fabs(x)<EPS，fabs()是对浮点数取绝对值， EPS是允许的最大误差（自行定义）
2.逻辑运算符
 !     一元逻辑非运算，把0值变为1，非0值变成0
 &&    逻辑与，两端表达式都为非0值时产生1，否则产生0      and
 ||    逻辑或，两端表达式中有1个为非0值时产生1，否则产生0  or
 1.优先级：!>&&>||
 2.整型变量只要不等于0，这一运算对象在逻辑表达式中为真
 3.&&和||连接的表达式按照从左到右顺序求值，在计算过程中，一旦可以明确表达式的值，求值会立刻停止

 3.特殊运算符
     符号 & 和 | 这两个运算符都是二进制的按位操作符。
          &: 二进制“与”(都为1时，结果是1，否则是0。)，比如:1010 & 1011 = 1010，1010 & 1000 = 1000。
          |: 二进制“或”(有1时，结果是1，都是0时，结果为0。)，比如:1010 | 1011 = 1011，1010 | 1000 = 1010。
     运算符<<  >>
     a<<b   左移,就是把a的二进制所有位都向左移动b位   丢弃最高位,0补最低位,其余左移
     a>>b   右移,就是把a的二进制所有位都向右移动b位   符号位向右移动后,正数的话补0,负数补1，丢弃最低位，其余右移
     注意：a b 和左移或右移得到的数必须为整数，否则会出错  左移<<表示乘以2，右移>>表示除以2
     对于有符号的整数，右移符号不变，左移符号可能会改变且可能出错

     对于有符号的

3.运算符的优先级
课本p46略




 */