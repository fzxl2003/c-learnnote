/*
https://accoding.buaa.edu.cn/contest-ng/index.html#/818/problems

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


替换二进制特定位的值
a &= (~(1 << x));   将a的二进制第x位替换为0
a|=(1<<x);          将a的二进制第x位替换为1

提取二进制的特定位
a=x&(1<<m);           //取出x的第m位，保存在a中（若为1，则a=2^m,否则a=0）

十进制转其他进制
void mian3(int radix,int num)
{    int arr[320] = {0},i=0;
 if (num==0 ||radix==0) {printf("0\n");return;}     //排除特殊情况0
       while(num){                              //整除取余
        arr[i] = num % radix;
        num /= radix;
        i++;
    }
    while(i--){
if (arr[i]>=10){ putchar(arr[i]-10+'A');}  //倒序输出
        else putchar(arr[i] + '0');
    }
}
十进制转二进制（直接输出）(以int为例)
for(int i=7;i>=0;i--) printf("%d",(x>>i)&1);


二进制32个1的整数
long long int sum = 0xffffffffLL;
 */