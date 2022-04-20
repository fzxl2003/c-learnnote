/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4223936
 Created at: Wed Mar 23 2022 20:12:44 GMT+0800 (China Standard Time)
 Problem_id: 5458	Time: 26	Memory: 2144
*/

#include <stdio.h>
#include <math.h>
int a[100000]={0};

int sushu(int m)
{a[0]=2;int mm=1;
    for (int n=3;n<m;n++){
        int l=0;
        int k=(int)sqrt( (double)n );
        for (int i=2;i<=k;i++)
        {if (!(n%i))
            {l=1;break;}

        }
        if (!l) {a[mm]=n;mm++;l=0;}
    }
    return mm-1;
}

int main()
{int n;int sw=1;int mm;
    scanf("%d",&n);
    mm=sushu(n);
    for (int i=0;i<=mm;i++)
    {
        for (int ll=mm;ll>=i;ll--)
        {if (a[ll]+a[i]==n)
            { printf("%d %d",a[i],a[ll]);sw=0;break;}}
        if (sw==0) break;
    }
}