/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4287410
 Created at: Fri Apr 08 2022 23:05:04 GMT+0800 (China Standard Time)
 Problem_id: 5538	Time: 16	Memory: 1736
 https://accoding.buaa.edu.cn/contest-ng/index.html#/832/problems
*/

#include <stdio.h>


int main() {
    long long a[11]={0},n,m;
    scanf("%lld%lld", &n, &m);
    if (n==0) a[0]++;
    for (long long i = n; i <= m; i++) {
        long long j = i;
        while (j > 0) {
            a[j % 10]++;
            j /= 10;
        }
    }
    for (long long i = 0; i <= 9; i++) {
        printf("%lld ", a[i]);
    }

}