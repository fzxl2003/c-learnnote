#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmp(const void* p1, const void* p2) {  //升序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}

int cmp1(const void* p1, const void* p2) {  //降序排列
    int* a = (int*)p1, * b = (int*)p2;
    if (*a > *b)return -1;
    else if (*a < *b) return 1;
    else return 0;
}
struct data{int order;}list[3];
int cmp3_order(const void* p1, const void* p2) {  //降序排列  //按结构体stu中的order元素排序
    int a = ((struct data *)p1)->order,  b = ((struct data *)p2)->order;
    if (a > b)return -1;
    else if (a < b) return 1;
    else return 0;
}
//qsort(list,3,sizeof(struct data),cmp3_order )  //按结构体stu中的order元素排序
int main()
{
    int n;

    printf("排序之前的列表：\n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }

    qsort(values, 5, sizeof(int), cmpfunc);

    printf("\n排序之后的列表：\n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }

    return(0);
}