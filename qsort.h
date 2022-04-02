#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );   //升序排列
}

int cmpfunc1 (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );   //降序排列
}

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