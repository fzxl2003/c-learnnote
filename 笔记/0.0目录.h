/*
 PPT
P1-程序设计引言quicklntro.pdf
P2-C语言编程基础框架framework(1).pdfP3-基本数据处理dataProcessing.pdfP4-结构化编程structProg.pdf
P5-函数function.pdf
关于二分查找的那些事.pdf常见错误第一期(2).pdf
推荐大家使用qsort而非手写快排的那点事(3).pdf


上机
C0-2021级C语言程序设计-热身赛.h
C1-2021级-航类第1次上机.h
C2-2021级-航类第2次上机.h
C3-2021级航类-第三次上机题解.h
C4-2021级-航类第4次上机.h
C5-2021级航类-第五次上机.h
E1-2021级-航类第1次练习.h
E2-2021级-航类第2次练习.h
E3-2021级-航类第3次练习.h
E4-2021级-航类第4次练习.hoj简介.h
R0-针对期中的专题复习:简单题训练.h
R1-针对期中的专题预习与复习:排序和二分查找.h
简单题练习.h
题目检索.h

上机与练习赛题解
C0-2021级C语言程序设计-热身赛题解.pdf
C1-2021级-航类第1次上机题解.pdf
C2-2021级-航类第2次上机题解.pdf
C3-2021级航类-第三次上机.pdf
C3-2021级航类-第三次上机题解.pdf
C4-2021级航类-第四次上机.pdf
C4-2021级航类-第四次上机题解.pdf
E1-2021级-航类第1次练习题解.pdf
E2-2021级航类-第二次练习赛题解.pdf
E3-2021级航类-第三次练习赛题解.pdf
E4-2021级航类-第四次练习赛题解.pdf
知识点汇总.pdf


代码区
5421码.h
H zhn 字符串.h
LJF算复数.h
今天也要羁绊变身.h
复矩阵乘法.h
未归档.h
浮点数协议.h
狼人杀1.0.h
直线数局.h
逛超市.h
验证偶数可以拆成素数.h


笔记
1.2 c程序基本组成.h
2.1.1常量.h
2.2 5.6变量.h
2.3算数表达式.h
2.4强制类型转换.h
2.5函数printf() scanf().h
2.6常量.h
3.1关系运算符和逻辑运算符.h
3.4条件语句.h
4.1-4.7循环语句.h
4.8 goto语句.h
5.1-5.5 函数相关概念.h
5.8标准库函数.h
6.1一维数组.h
6.2.2栈.h
6.2.3队.h
6.3字符串和字符数组.h
6.4常用的标准字符串函数.h
6.5二维数组.h
ctype库.h
math库.h
rand伪随机数函数.h
stdlib库.h
位运算.h
几大输入的终止判断.h
字符串加法.h
字符串调用.h
字符串转数字.h
拦截导弹.h
指针.h
数据类型范围.h
数组元素二分查找.h
数组排序.h
转义字符.h
难以归类.h

4-3斐波那列.h
4-13输入正确成绩.h
4-14行数统计.h
4-15辗转相除法求最大公约数.h
4-19计算pi.h
4-20输出平行四边形.h
4-21输出连续加和.h
6-12统计字符串中小写字母个数等.h
bsearch.h
CMakeLists.txt
main.c
n重循环移位.h
qsort.h
zhn数字零.h
一些数据处理.h
一元二次方程.h
二分法开方.h
二分法解方程.h
伪随机数求积分.h
全排列组合输出.h
八皇后问题.h
冒泡排序法.h
判断浮点数是否为整数.h
判断素数.h
区间合并.h
十进制取特定位的数.h
原码反码补码.h
在成对数字中找单蹦.h
多项式相加.h
字符串倒置.h
字符串加法1.h
根据日期判断周几(公式法).h
每个数字出现的次数.h
求三个数的最大公约数与最小公倍数.h
求数列中一段连续数的最大加和.h汉诺塔.h
浮点数判断是否相等.h
组合数能否凑成某数问题(所有数最大公约数组合数输出.h
计算cosx.h
转科学计数法.h
返回数组中第三大数.h
题4-4分数相加与化简.h
题4-7熊猫序列.h
题4-11倒序输出.h
鬼谷子的钱袋.h



 一些数据处理.h
//long long dectobin( int n ){     //十进制转二进制（除法）（输出longlong）
//int convertBinaryToDecimal(long long n) //二进制转十进制
//long long mian123(long long a,int n,int x)  //替换二进制特定位的值  //a为要转化的数字，n为替换的值（0或1），x为位数
//long long mian1234(long long x,int n)  //提取二进制的特定位  //x为要转化的数字，n为位数
//void mian3(int radix,int num)  //十进制转2-36其他进制  //radix为进制  num为十进制数
//void mian132(long long x)        //十进制转二进制（打印输出）(以int为例)
//long long int sum = 0xffffffffLL;  //二进制32个1的整数
//int  data(int m)  //判断十进制位数
//unsigned int mian2(unsigned int a1,int begin,int end,int n)   //替换二进制中特定连续位置，begin和end从0位开始，n为要替换的数，a1为被替换数
//unsigned int mian4(unsigned int a1,int begin,int end)  //翻转特定位，从0位开始
//long long int main5(long long a)   //高低位交换,前16位与后16位交换
//void main7(long long a,int d[],int i)   //分离十进制数a的各位，存储在d[],调用时i=0
//void a()                            //printf输出八进制/十六进制
//void xiaoshu2(double a)          //十进制小数转二进制小数（原码）
long long dectobin( int n ){     //十进制转二进制（除法）（输出longlong）
 */