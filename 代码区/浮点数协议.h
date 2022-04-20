/*
题目描述
在IEEE 754标准中，一个 32 位的二进制单精度浮点数（float类型数据）通常由如下形式来表示：

sek−1......e1e0fn−1......f1f0   (其中k=8,n=23;s,ei,fj∈{0,1})
IEEE 754标准规定，通过如下公式计算一个有效的、非无穷大的二进制浮点数对应的十进制实数值 x ：
x=(−1)s×F×2E−bias
其中，F 是一个二进制小数，E 和 bias 是十进制整数，bias=2k−1−1=127，计算 F 和 E 需要分情况讨论：

本题不涉及 ek−1......e1e0 的每一位全为 1的情况；
若 ek−1......e1e0 的每一位全为 0 ，则 F=0.fn−1......f1f0,E=1；
若 ek−1......e1e0 的每一位既不全为 1 也不全为 0 ，则 F=1.fn−1......f1f0，E为二进制数 ek−1......e1e0 转换为十进制数后得到的整数值。
给予一个float类型的数据，请你提取出它的 F 和 E（F 用二进制小数表示，E 用十进制整数表示）

输入
多组数据输入，每行一个float类型的浮点数。

数据组数不超过105行。

输出
对于每组数据输出一行：它的 F 和 E，用空格隔开
*/

#include <stdio.h>
#include <string.h>
void mian132(long long x)
{
    for(int i=sizeof(x)*4-1;i>=0;i--)
        printf("%d",(x>>i)&1);
}

int main() {
    float n;

    while ((scanf("%f",&n))!=EOF)
    {

        int da;
        memcpy(&da, &n, 4); // 将float类型变量a逐比特复制进int类型变量da
        if ((da)&(((1<<31)-1)-((1<<23)-1))){
            printf("1.");
        }
        else printf("0.");
        for(int i=22;i>=0;i--)
            printf("%d",(da>>i)&1);
        printf(" ");
        if ((da)&(((1<<31)-1)-((1<<23)-1))){
            int l=(da)&((1<<31)-1);
            l=l>>23;
            //mian132(da);printf("\n");
            //mian132(l);printf("\n");
            printf("%d\n",l);
        }
        else printf("1\n");





    }return 0;
}