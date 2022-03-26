/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4232462
 Created at: Sat Mar 26 2022 10:40:19 GMT+0800 (China Standard Time)
 Problem_id: 5415	Time: 15	Memory: 1676
*/

#include <stdio.h>

void money(int n,int shuliang)
{

    //if (n==2) { printf("%d",shuliang+1);return;}
    if (n==1) { printf("%d",shuliang);return;}
    money(n/2,shuliang+1);
}


int main()
{
    int m,mnow;
    scanf("%d",&m);
    //int shuliang=1;
    money(m,1);
}