#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dhsadsa{
    int group;
    char name[30];
    int guess;
}inf;
int cmp(const void *p1, const void *p2)    //按照guess降序，group升序，name字典升序排列
{
    const inf *a1=(inf *)p1;
    const inf *a2=(inf *)p2;
    if (a1->guess<a2->guess)
        return 1;
    else if (a1->guess>a2->guess)
        return -1;
    else
    {
        if (a1->group<a2->group)
            return -1;
        else if (a1->group>a2->group)
            return 1;
        else
            return strcmp(a1->name,a2->name);
    }
}
inf a[100005];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s", &a[i].group, a[i].name); //读入数据，注意a[i].name前面没有&
        int sum = 0, tmp;
        for (int j = 1; j <= 50; j++)
        {
            scanf("%d", &tmp);
            sum += (tmp == j); //计算猜对的人数
        }
        a[i].guess = sum;
    }
    qsort(a, n, sizeof(a[0]), cmp); //快速排序
    for (int i = 0; i < n; i++)
        printf("%s %d %d\n", a[i].name, a[i].group, a[i].guess);
//输出

    return 0;
}
