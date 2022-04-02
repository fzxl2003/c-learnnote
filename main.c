#include<stdio.h>
int lower_bound(int a[], int lo, int hi, int val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int n, m;
int a[1919810], x;
int pos;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);//从a[1]开始读入 读到a[n]
    while (m--) {
        scanf("%d", &x);
        pos = lower_bound(a, 1, n, x);//下界二分查找的下标 注意起点是1 终点是n
//如果是从a[0]读到a[n-1] 那么上面的函数就应该传入0和n-1才对
        if (a[pos] == x)
            printf("%d\n", pos);//相等:我们找到了所求解
        else printf("-1\n");//大于:要查找的值没有出现过
    }
}
