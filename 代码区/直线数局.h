/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4247498
 Created at: Tue Mar 29 2022 19:47:16 GMT+0800 (China Standard Time)
 Problem_id: 5449	Time: 16	Memory: 1700
*/

#include <stdio.h>
int main()
{
    int n;int a[101]={0},loc=1,maxlox=1;long long bushu=0;int b[101]={0};
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    b[1]=1;
    if (n==1) {printf("True\n0");return 0;}
    while (1)
    {loc=loc+a[loc];
        bushu++;
        if ( loc>n ||loc<=0) { printf("False\n%d",maxlox-1);return 0;}
        if (maxlox<loc) maxlox=loc;
        if (a[loc]==0 && loc!=n){ printf("False\n%d",maxlox-1);return 0;}
        if (b[loc]==1) { printf("False\n%d",maxlox-1);return 0;}
        b[loc]=1;
        if (loc==n) { printf("True\n%lld",bushu);return 0;}


    }
    //printf("False\n%d",maxlox-1);return 0;
}