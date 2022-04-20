//判断一个浮点数是否为整数可以借助round(x)函数，round(x)返回x的四舍五入到整数位的结果，返回值仍为double型。
#include <stdio.h>
#include <math.h>

//判断一个浮点数是否为整数可以使用下面的代码
int doublezhenshu(double e) {
    if (fabs(round(e) - e) < 1e-5) {
        return 1;
    }
    return 0;
}