#include <stdio.h>
#include <math.h>

int main() {
    double d1, d2;
    double EPS = 1e-9;
    printf("%d",pow(10,3));
    scanf("%lf%lf", &d1, &d2);
    if (fabs(d1 - d2) < EPS) // 判断两个浮点数是否相等
        printf("Equal\n"); //特殊地，判断一个浮点数是不是0 if (fabs(d1) < EPS)
    printf("Equal to 0");
}