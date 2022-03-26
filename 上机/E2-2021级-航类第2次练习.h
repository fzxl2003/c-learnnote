/*
 https://accoding.buaa.edu.cn/contest-ng/index.html#/819
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

 判断2的次幂方法
 1.判断方法：(n & (n - 1))，若为2的次幂输出0，反之不输出0
 2.比如1024 二进制为10000000000 1023二进制为01111111111 两者异位与得0





 a^a=0    具体代码见在成对数字中找单蹦.h
 异或运算的部分性质
    0^a = a
    a^a =0
    异或具有交换律
    异或具有结合律




 异或运算求解二进制不同位的个数
unsigned long long k = tem ^ b; //异或运算求解不同位的个数
 int c = 0;
 for (int i = 0; i < 64; i++)
 {
 if ((1ull << i) & k)
 { //若该位为1，说明该位⼆进制码不同
 c++;
 }



 memcpy()函数
 使用<string.h>函数库中的memcpy函数可以将一个float类型变量逐比特地复制进一个int类型变量
 具体用法可以参考如下代码：
    #include <stdio.h>
    #include <string.h>
     int main() {
    float a = 3.14;
    int da;
    memcpy(&da, &a, 4); // 将float类型变量a逐比特复制进int类型变量da
    return 0;
    }

 */