/*
输入
输入共 n+1 行；
第一行一个整数 n 表示有一共有n个待求解的方程。
接下来 n 行，每行三个整数，分别表示第 i个方程的参数 ai、bi、ci


输出
输出共 n 行
第 i 行表示输入的第i个方程的求解结果：
如果此方程不是一元二次方程，输出这个一元一次方程的解（输入保证此方程一定有解），结果保留到小数点后6位。
如果方程有实数解，输出一行两个浮点数，以一个空格分隔，表示方程的两个根，结果保留到小数点后6位；值大的在前，值小的在后，如果是重根，输出两个一样的数。
如果方程没有实数解，输出两个复数解 p+qi 和 p−qi，以一个空格分开，其中q>0。p 和 q 保留到小数点后6位（如果p是0也要输出）。
*/



#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, t, result1, result2;
    int n;
    scanf("%d",&n);
    while (n--){
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a==0) {printf("%.6f\n",-1.0*c/b);continue;}


        t = b * b - 4 * a * c;
        if (t < 0.0)
        {t=-1*t;
            double p=-1.0*b/2/a;
            t=sqrt(t)/2/a;
            if (a<0) t=-1*t;
            printf("%.6f+%.6fi %.6f-%.6fi\n",p,t,p,t);}

        else {
            result1 = (-b + sqrt(t)) / (2 * a);
            if (t == 0.0) {
                printf("%.6f %.6f\n", result1, result1);
            } else {
                result2 = (-b - sqrt(t)) / (2 * a);
                if (result2 > result1) {
                    printf("%.6f %.6f\n", result2, result1);
                } else
                    printf("%.6f %.6f\n", result1, result2);

            }
        }






    }
    return 0;








}