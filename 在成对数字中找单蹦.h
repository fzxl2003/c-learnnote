/*
 对于偶数次出现的两个数 运⽤异或运算的交换律和结合律,两者相互抵消
对于仅有⼀个数字 出现奇数次，其他数均出现偶数次的数列 运⽤异或运算的交换律和结合律
可得只出现奇数次的数字。
若输⼊的数全部出现了偶数次，则输⼊的数据个数将会是偶数；
若输⼊的个数中有个数出现了奇数次，其他数字都出现了偶数次，将输⼊数据全部进⾏异或运算，则最后的运算结果就会是唯⼀出现
奇数次的数字。
 */

#include<stdio.h>
int main(){
    int input;
    int m, i, temp = 0;
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d", &input);
        temp = temp ^ input;
    }
    if(m % 2)//等效于if(m % 2 == 1),即当 m 为奇数时为真
        printf("%d", temp);
    else
        printf("False Alarm.\n");
    return 0;
}
