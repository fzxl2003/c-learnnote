/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4188227
 Created at: Sat Mar 19 2022 09:17:05 GMT+0800 (China Standard Time)
 Problem_id: 5386	Time: 3	Memory: 1688
*/

#include <stdio.h>

int main(){
    unsigned int m,n;
    while ((scanf("%d",&m))!=EOF)
    {

        m=m^(m<<1);
        m=m^(m<<2);
        m=m^(m<<4);
        m=m^(m<<8);
        m=m^(m<<16);
        printf("%u\n",m);


    }


}