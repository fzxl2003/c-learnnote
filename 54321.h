/*
 https://accoding.buaa.edu.cn/contest-ng/index.html#/819/problems
 输入
一行，一个十进制正整数a
输出
一行，两个十进制正整数b,c,十进制正整数b的二进制码恰为十进制正整数a的5421码，
 c为十进制正整数a与b的二进制码不同位的个数
 */


#include <stdio.h>
int main()
{
    unsigned long long a, b = 0ull;     //注意数据类型
    scanf("%llu", &a);
    unsigned long long tem = a; //提前保存好a的副本
    int count = 0;
    while (a > 0)
    {
        unsigned long long num = a % 10ull; //取出a的⼗进制每⼀位
        if (num < 5)
        {
            b |= (num << (4ull * count)); //对于0-4,bcd码与⼆进制码相同，直接左移位或即可
        }
        else
        {
            b |= ((num + 3ull) << (4ull * count)); //对于5-9,需要在⼆进制码基础上加3
        }
        a /= 10ull;
        count++;
    }
    unsigned long long k = tem ^ b; //异或运算求解不同位的个数
    int c = 0;
    for (int i = 0; i < 64; i++)
    {
        if ((1ull << i) & k)
        { //若该位为1，说明该位⼆进制码不同
            c++;
        }
    }
    printf("%llu %d", b, c);
    return 0;
}
