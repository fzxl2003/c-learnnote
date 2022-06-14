/*
 题目背景
内鬼又回来了！在5.20号这天 TA（也许）带上了 TA 的npy。

简单描述
在输入的 n 个数中至多有2个数出现了奇数次，其他数字都出现了偶数次，请输出出现了奇数次的数；如果所有数字都出现了偶数次，输出False Alarm.

输入
共2行。
第一个数为输入数据的总数 n。
接下来一行共有 n 个整数，每一个整数以空格隔开，代表课程内的编号或点名册上的编号。由于课程内有老师同学和教职工等，因此编号的位数并不统一。
输入时并不按照 “课程内编号——点名册" 的顺序输入（也就是说是乱序输入哒！）。

输出
输出一行整数，表示内鬼伪装成的编号，若有两个内鬼，则按从小到大的方式输出；若实际上没有内鬼的话， 输出False Alarm.。
保证内鬼最多只会有两个。

输入样例1
8
2345 34567 34567 456789 456789 2345 456789 2345
输出样例1
2345 456789
输入样例2
4
1234 2345 1234 2345
输出样例2
False Alarm.
 */


#include<stdio.h>
int array[6000005];
int main(){
    int i, n, temp = 0, count = 0, temp2 = 0, a, b;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
        temp = temp ^ array[i];
    }
    if(n % 2)
        printf("%d", temp);
    else{
        if(temp == 0)
            printf("False Alarm.");
        else{
            i = temp;
            while((i & 1) == 0){
                i >>= 1;
                count++;
            }
            for(i = 0; i < n; i++)
                if(((array[i] >> count) & 1) == 1)
                    temp2 = array[i] ^ temp2;
            a = temp2;
            b = temp ^ temp2;
            if(b < a)
                printf("%d %d", b, a);
            else
                printf("%d %d", a, b);
        }
    }
    return 0;
}
