
/* BC
 Author: 潘宇恒
 Result: AC	Submission_id: 4508093
 Created at: Wed Jun 08 2022 19:18:17 GMT+0800 (China Standard Time)
 Problem_id: 4421	Time: 157	Memory: 2080
*/

#include <stdio.h>
int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
int main()
{
    int c1,c2,c3;
    int money=0;
    scanf("%d%d%d",&c1,&c2,&c3);
    int shui;
    int a[100007];
    a[1]=c1;
    for (int i = 2; i <=100006 ; ++i) {
        a[i]=a[i-1]+c1;
        if (i%2==0)
        {
            int aa=a[i/2]+c2;
            a[i]=min(aa,a[i]);
        }
        if (i%3==0)
        {
            int aa=a[i/3]+c3;
            a[i]=min(aa,a[i]);
        }
    }
    while ((scanf("%d",&money))!=EOF)
    {
        printf("%d\n",a[money]);
    }

}