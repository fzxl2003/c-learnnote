/*
题目介绍
有一天学弟学妹拿着电路分析的题目来问LJF，LJF一看，这不就是电容电感的复频域表示嘛！但是LJF却忘记了复数怎么计算？
我们把形如z=a+bi（a,b均为实数）的数称为复数，其中a称为实部，b称为虚部，i称为虚数单位。
忘记复数四则运算法则的同学可以点击这里
工具人小C将编写支持四则运算的复数计算器

输入格式
多组数据输入
每行为两个复数做加、减、乘、除运算，分别用+ - * /表示
输入数据的实部、虚部都不为零

输出格式
输出数据的实部或虚部如果为零，则不输出该部分（如果都为零则输出0）
输出数据若为整数，则直接输出（没有小数点）；如果包含小数，则四舍五入保留小数点后两位
输出数据的虚部若为i或-i，不能输出1i或-1i
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a1, a2, b1, b2, c1, c2;
    char fuhaoa, fuhaob, fuhao,t;
    while ((scanf("(%lf%lfi)%c(%lf%lfi)", &a1,  &a2, &fuhao, &b1,&b2) != EOF)) {
        t=getchar();
        while (t!='\n'&&t!=EOF )t=getchar();


        if (fuhao == '+') {
            c1 = a1 + b1;
            c2 = a2 + b2;
        }
        if (fuhao == '-') {
            c1 = a1 - b1;
            c2 = a2 - b2;
        }
        if (fuhao == '*') {
            c1 = a1 * b1 - a2 * b2;
            c2 = a1 * b2 + a2 * b1;
        }
        if (fuhao == '/') {
            c1 = (a1 * b1 + a2 * b2) / (b1 * b1 + b2 * b2);
            c2 = (a2 * b1 - a1 * b2) / (b1 * b1 + b2 * b2);
        }
        if (fabs(c1) < 1e-5) {
            if (fabs(c2) < 1e-5)
            {printf("0");}
            else if (fabs(c2 - 1) < 1e-5) { printf("i"); }
            else if (fabs(c2 + 1) < 1e-5) {
                printf("-i");
            } else if (fabs(round(c2) - c2) < 1e-5) {
                printf("%.0fi", c2);
            }
            else {printf("%.2fi", c2);}
        } else {
            if (fabs(round(c1) - c1) < 1e-5)
                printf("%.0f", c1);
            else printf("%.2f", c1);
            if (fabs(c2) < 1e-5) {}
            else if (fabs(c2 - 1) < 1e-5) { printf("+i"); }
            else if (fabs(c2 + 1) < 1e-5) { printf("-i"); }
            else if (fabs(round(c2) - c2) < 1e-5) { printf("%+.0fi", c2); }
            else printf("%+.2fi", c2);

        }

        printf("\n");
    }
}