#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char a[10005], ans[10005], tem[10005];//储存余数的数组稍微开大一点
void myatoi(char a[]) {//将字符转化为数字
    int i;
    for (i = 0; a[i] != 10 && a[i] != -1; i++);//读取字符长度

    int a_len = i;//记录字符长度
    for (i = 0; i < a_len; i++) {
        a[i] -= '0';//通过减去0的ascii码来转换
    }
}

int div_cal(char a[], int scale, char ans[]) {
    int i = 0, j = 0, k = 0, res = 0, temp, begin;
    while (1) {//每一轮计算后，可以选择去除前导零，该份代码未去除
        k = 0, res = 0;
        for (i = 0; a[i] != -1; i++) {
            tem[i] = (res * 10 + a[i]) / scale;//整型相除
            res = (res * 10 + a[i]) - tem[i] * scale;//计算余数留作下一位计算
        }
        ans[j++] = res;//将最后的余数记录在ans数组中
        memcpy(a, tem, sizeof(a[0]) * (i + 5));//将tem数组复制到a数组
        memset(tem, -1, sizeof(tem[0]) * (i + 5));//tem数组初始化
        while (a[k] == 0) k++;
        if (a[k] == -1)
            break;
    }
    return j;
}

int main() {
    while (1) {//多组不定组数据输入
        int scale = 4, i = 0, j = 0, k = 0;
        memset(ans, -1, sizeof(ans)), memset(a, -1, sizeof(a)), memset(tem,
                                                                       -1, sizeof(a));//初始化为-1
        scanf("%s", a);
        i = strlen(a);
        if (a[0] == EOF) break;//读到结束符时，意味着没有更多输入数据了，直接跳出循环
        a[i] = -1;
        myatoi(a);//将字符转化为数字
        j = div_cal(a, scale, ans);
        for (i = j - 1; i >= 0; i--) {
            if (ans[i] == 0 && k == 0 && ans[i + 1] != -1)
                continue;//输出时消除前导零
            k = 1;
            printf("%c", ans[i] + '0');//打印结果

        }
        puts("");
    }
    return 0;
}