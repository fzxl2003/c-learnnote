#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int upper_bound(int a[], int lo, int hi, int val) {
    if (val <= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] >= val) lo = mi + 1;
        else hi = mi;}
    return lo;}
int main()
{int a[5]={5,4,3,2,1};
    int lo=0,hi=4,val=0;
    printf("%d", upper_bound(a,lo,hi,val));
}