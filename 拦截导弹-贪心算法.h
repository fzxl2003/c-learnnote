/*
 洛谷题解 https://www.luogu.com.cn/problem/solution/P1020
 */


/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4323901
 Created at: Sat Apr 16 2022 08:05:42 GMT+0800 (China Standard Time)
 Problem_id: 652	Time: 2	Memory: 1668
*/

#include <stdio.h>
int upper_bound(int a[], int lo, int hi, int val) {
    if (val <= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] >= val) lo = mi + 1;
        else hi = mi;}
    return lo;
}



int main()
{
    int n;int a1[1005],hight,len1=1;
    scanf("%d",&n);
    scanf("%d",&hight);
    a1[1]=hight;

    for (int i = 2; i <=n ; ++i) {
        scanf("%d",&hight);
        if (a1[len1]>=hight) {len1++;a1[len1]=hight;}
        else{
            a1[upper_bound(a1,1,len1,hight)]=hight;
        }
    }
    printf("%d",len1);

}