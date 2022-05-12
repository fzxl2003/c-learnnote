#include <stdio.h>
#include <stdlib.h>
#define ONEW 10000 // 宏定义，1万
typedef struct {
    long long num;
    int pos;
} Item; // 定义一个结构体Item，具有两个成员：数字num和其下标pos
int r_cmp(const void *p1, const void *p2) {
    Item *pp1 = (Item*)p1;
    Item *pp2 = (Item*)p2;
    if (pp1->num > pp2->num)
        return 1;
    else if (pp1->num < pp2->num)
        return -1;
    else
        return pp1->pos - pp2->pos; // 在num相等的情况下，按照pos    的大小进行排序
}
int main() {
    int a, c, seed, i, T;
    long long m; // m要定义为long long
    Item x[10005]; // 定义Item类型的数组变量x
    while (scanf("%d%d%lld%d", &a, &c, &m, &seed) != EOF) {
        x[0].num = seed;
        x[0].pos = 0;
        for (i = 1; i <= ONEW; i++) {
            x[i].num = (a * x[i - 1].num + c) % m; // 线性同余公式
            x[i].pos = i; // 下标i
        }
        qsort(x, ONEW + 1, sizeof(x[0]), r_cmp); // 注意数据总数        为一万加一
                T = -1;
        for (i = 0; i < ONEW; i++) {
            if (x[i].num == x[i + 1].num) {
                T = x[i + 1].pos - x[i].pos; // pos成员直接相减得                到周期T
                break;
            }
        }
        if (T == -1)
            printf("T > 10^4\n");
        else
            printf("T = %d\n", T);
    }
    return 0;
}