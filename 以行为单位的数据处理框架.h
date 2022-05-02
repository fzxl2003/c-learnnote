#include <stdio.h>
#include <ctype.h>
//处理数据说明   每一行有多个以空格相隔开的数字，该代码以行为单位读取每个数字并处理
char *get_value(char *s, double *d)
{
    while(*s != '\0' && isspace(*s))
        s++; // 跳过空格，指针指到非空格处
    if(sscanf(s, "%lf", d) != 1)
        return NULL;
    while(*s != '\0' && !isspace(*s))
        s++; // 指针移到实数后的空白位
    return s;
}
int main() {
    int i, n;
    double d, subsum;
    char buf[BUFSIZ], *p;
    for (i = 1; fgets(buf, BUFSIZ, stdin) != NULL; i++) {     //读取第i行
        subsum = 0;
        for (n = 0, p = buf; (p = get_value(p, &d)) != NULL; n++)
            subsum += d;     //对读取到的数d的操作（此处是求和）
        if (n > 0){}         //该行读取到最后一个数的最后的操作
    }
    return 0;
}