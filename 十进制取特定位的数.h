#include <stdio.h>
int m213(int a,int n)   //a为原数，n为位数，返回第n位的数字
{int aa=1;
    for (int i = 0; i < n; ++i) {
        aa*=10;
    }
    return (a%aa)/(aa/10);
}

