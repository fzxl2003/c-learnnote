/*
CO-2021级C语言程序设计-热身赛
A加法
B求余
C判断成绩
D打印星星
E打印星星
F打印星星
Gdwy考美院
H击败爆炎树**    注意攻击为0的特殊情况
I MRIYA我们回家了(一维最小步数)  ？？
J 呱呱泡蛙的数学卡片（猜谜）？？
K  雀魂绝艺总纲-基础篇（判断麻将糊了没）？？


C1-2021级-航类第1次上机
 A 转义字符输出
 B 字符也是数
 C 一元二次方程
 D 火仙草数
 E 简单的后缀计算
 F 大小写转换
 G 统计成绩
 H 名次预测
 I 时刻2.0  **
 J 科学计数法！  **注意各种特殊情况
1
E1-2021级-航类第1次练习
 A 雪容融               打印雪容融  对于单引号'、双引号"、百分号%、反斜杠\需要转义为\',\",%%,\\
 B 时刻1.0
 C 来计算圣遗物评分吧！
 D 猜猜我是倒还是不倒!     打印三角形
 E 中间位取数
 F 求最大斜率
 G 驼峰命名与短横线命名
 H 计算 ln2           注意log(n)可输出ln2值 log10(n)返回以10为底的对数
 I zhn の 奇妙魔法ln2
 J 810975ln2 * 九把七鸡五连鸡  注意条件判断

 C2-2021级-航类第2次上机
 A 水水的a+b>c       注意变量范围
                        int 可表示数的范围即是 [−2^31,2^31) ，但两个 int 类型的数相加可能会溢出 int ，因此我们可以用 long long 来读入数据，long long 的范围是 [−2^63,2^63) ；
 B 等差数列求和
 C 一元二次方程进阶版
 D LJF的位运算加密     注意如何替换二进制特定位的值
 E 统计字母
 F 小冰的烦恼     注意如何提取二进制的特定位
 G 进制转换plus ***   注意 0,如何十进制转其他进制
 H 原码，反码，补码***  注意正负数的原码、反码与补码
 I 送蚂蚁回家      注意解题思想
 J 双重循环移位***** 注意二进制32个1如何表示和unsigned的运用

 C3-2021级航类-第三次上机题解
 A Ct     数值范围判断
 B 求Fibo数列的第n项    //注意中间取模，取模与加减乘除顺序可交换
 C 三⻆形形状判断  条件判断
 D LJF坐地铁      三层循环
 E 胆密欧&傅⾥叶   求数列和
 F 普通的GCD和LCM       //求三个数的最小公倍数和最大公倍数
 G X同学的⽇期统计      //根据日期判断星期几的公式
 H zhn の 数论（⼀）
 I 图图玩狼⼈杀?        //过于复杂
 J LJF算复数?          //条件一大坨
 K cxccxc与谢尔宾斯基三⻆形???  //答案直接看不懂


 E2-2021级-航类第2次练习
 A 简单浮点数(水题速来)
 B 简单位运算
 C 简单的字符串统计
 D 2的次幂      //判断2的次幂方法  判断方法：(n & (n - 1))，若为2的次幂输出0，反之不输出0
 E 找内鬼       //a^a=0  具体代码见在成对数字中找单蹦.h
 F LJF赶校车   几何概型，公式推导较麻烦
 G 今天也要牵绊变身 原理不详，照着hint写
 H 5421码    //注意数据类型,unsigned long long,格式化字符串中为%llu  //异或运算求解二进制不同位的个数
 L 浮点数协议   //memcpy()函数
 J n重循环移位####   代码没有debug


 E3-2021级-航类第3次练习
 A 数数逆序对  条件加循环
 B 判断完全数  求因子加和
 C 求e的近似值
 D 统计胜场数  注意输出方式
 E 直线数局
 F 溢0数      //两数相乘得到的数的二进制末尾0的个数等于这两个数末尾0的个数相加
 G 高精度加法   //字符串加法
 H zhn の money  //按要求分解数字（使数字能表示任意数字）  //代码详见鬼谷子的钱袋.h
 I 林士谔算法  仅需添加输入输出
 J 测评机没有 sqrt() ！ //二分法开根   //代码详见二分法开方.h
 K 荷家军 进攻 汉诺塔   //汉诺塔       //代码详见汉诺塔.h


  C4-2021级-航类第4次上机
 A <math.h>              //math库
 B 宋老师的名次预测2.0
 C 滴滴滴递归             //给公式的递归
 D 求差向量的无穷范数
 E 多项式相加2022***       //多项式相加.h
 F 简单的基物数据处理
 G 来个神奇日历
 H 全排列组合****      //超级递归 //见全排列组合.h
 I 大师问题*****      //超级递归 //见八皇后问题.h
 J dwy逛超市*****     //求多个数的最大公约数//见组合数能否凑成某数问题.h
 */