/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4499517
 Created at: Sat Jun 04 2022 20:05:53 GMT+0800 (China Standard Time)
 Problem_id: 5793	Time: 5	Memory: 1684
*/

#include <stdio.h>
int aa[2003];
int main()
{
    int n;int max=0;
    while ((scanf("%d",&n))!=EOF)
    {
        aa[n]++;
        int i;
        for ( i = n; i <2003 ; ++i) {
            if (aa[i]==2)
            {aa[i]=0;aa[i+1]++;}
            else break;
        }
        if (i>max) {max=i;}
        printf("%d\n",max);
    }
    for (int i = max+3; i>=0 ; --i) {
        if (aa[i]!=0) printf("%d ",i);
    }
}