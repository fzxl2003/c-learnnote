/*
 原理：https://www.cnblogs.com/coshaho/p/9741298.html
 蒙特卡洛求定积分（二）：期望法


 */
//例 以求λ(t)=e^(−(t+0.5)^2),0≤t≤1.5  在（0,t）上的积分为例
/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4268159
 Created at: Sat Apr 02 2022 14:14:09 GMT+0800 (China Standard Time)
 Problem_id: 5486	Time: 337	Memory: 2520
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double t,x,y,sum=0;int nn=1000000;
    scanf("%lf", &t);
    srand((int)time(0));
    for (int i = 0; i <nn; ++i) {
        x=rand()%10000;
        x=x/10000*t;  //生成0-1.5的随机数x
        sum+= (pow(2.718281828459,-1*(x+0.5)*(x+0.5)))/nn;    //计算x对应的y的值并平均加和，当随机数足够多时，得到的即为函数面积
    }

    printf("%f", pow(2.718281828459,-1*sum*t));


}