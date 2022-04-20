#include <stdio.h>
#define bi 32 // int型数据有32个⼆进制位
int main()
{
    int n, a[100001], t;
    char op;
    while (~scanf("%d", &n)) // 读⼊n
    {
        for (int i = 0; i < n; i++) // 读⼊数组的所有数据
        {
            scanf("%d", &a[i]);
        }
        getchar(); // 吃掉换⾏符
        scanf("%c %d", &op, &t); // 读⼊op和t
        int ds = n * bi, cnt = 0, num = 0, start, i;
        /* ds为数组a中的⼆进制位数
        * cnt记录读到的⼆进制位数，满32位就输出num
        * num存储b[i]
        * start为b的第0个⼆进制位在数组a中的位置
        * i记录⽬前处理到数组a中的第⼏个⼆进制位
        */
        start = op == 'l' ? t % ds : ds - t % ds; // start为b的第0个⼆进制位在数组a中的位置
        i = start; // 从第start个⼆进制位开始处理
        do {
            num = num << 1 | ((a[i / bi] & 1 << (bi - i % bi - 1)) == 0 ? 0 : 1);
            /* 数组a的第i个⼆进制位的所在位置为：
            * (a[i / 32] & 1 << (32 - i % 32 - 1)
            */
            cnt++;
            i = (i + 1) % ds;
            if (cnt == bi) // 找满32位就输出
            {
                printf("%d ", num);
                cnt = 0; // 重置cnt和num
                num = 0;
            }
        } while (i % ds != start);
        printf("\n");
    }

    return 0;
}