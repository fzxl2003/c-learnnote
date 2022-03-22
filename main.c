/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4189314
 Created at: Sat Mar 19 2022 10:41:40 GMT+0800 (China Standard Time)
 Problem_id: 5420	Time: 80	Memory: 1728
*/

#include <stdio.h>
#include <string.h>
void mian132(long long x)
{
    for(int i=sizeof(x)*4-1;i>=0;i--)
        printf("%d",(x>>i)&1);
}

int main() {
    float n;

    while ((scanf("%f",&n))!=EOF)
    {

        int da;
        memcpy(&da, &n, 4); // 将float类型变量a逐比特复制进int类型变量da
        if ((da)&(((1<<31)-1)-((1<<23)-1))){
            printf("1.");
        }
        else printf("0.");
        for(int i=22;i>=0;i--)
            printf("%d",(da>>i)&1);
        printf(" ");
        if ((da)&(((1<<31)-1)-((1<<23)-1))){
            int l=(da)&((1<<31)-1);
            l=l>>23;
            //mian132(da);printf("\n");
            //mian132(l);printf("\n");
            printf("%d\n",l);
        }
        else printf("1\n");





    }return 0;
}