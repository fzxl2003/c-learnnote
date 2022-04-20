/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4144013
 Created at: Wed Mar 09 2022 22:34:48 GMT+0800 (China Standard Time)
 Problem_id: 5399	Time: 3	Memory: 1588
*/

#include <stdio.h>

int main()
{char a[120]={0};
    int n=0,zhengshu=0,zero=0,i;
    while ((a[n]=getchar())!=EOF)
    {
        if (a[n]=='.')
        { zhengshu=n;n--;}
        if (a[n]=='\n')
        { n--;}
        n++;
    }
    if (zhengshu==0)
    {
        if (n==1){ printf("%ce0",a[0]);return 0;}
        else{
            printf("%c",a[0]);
            if (a[1]!='0'){ printf(".");}
            for (i=1;i<n;i++)
            {
                if (a[i]=='0'){break;}
                printf("%c",a[i]);
            }
            printf("e%d",n-1);
            return 0;
        }}
    if (zhengshu==1 &&a[0]=='0'){
        for (i=0;i<n;i++)
        {
            if (a[i]!='0')
            { zero=(-1)*i;break;}

        }
        printf("%c",a[i]);
        if (i!=n-1) printf(".") ;

        for (i=i+1;i<n;i++)
        {
            printf("%c",a[i]);
        }
        printf("e%d",zero);}
    else {

        printf("%c.",a[0]);
        for (i=1;i<n;i++)
        {
            printf("%c",a[i]);
        }
        printf("e%d",zhengshu-1);
    }
    return 0;

}