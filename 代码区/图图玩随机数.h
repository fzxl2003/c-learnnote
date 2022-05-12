/*
 https://accoding.buaa.edu.cn/problem/5562/index

 */

/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4431733
 Created at: Thu May 12 2022 09:53:57 GMT+0800 (China Standard Time)
 Problem_id: 5562	Time: 193	Memory: 1964
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define tt 10000
typedef struct yuewqi{
    long long num;
    int xiabiao;
}nn;



int cmp(const void *p1,const void *p2){
    nn *pp1=(nn*)p1;nn *pp2=(nn*)p2;
    if (pp1->num>pp2->num) return 1;
    else if (pp1->num<pp2->num) return -1;
    else return pp1->xiabiao-pp2->xiabiao;
}



int main()
{
    nn shuju[10005];
    int a,c,x,i,t;long long m;
    while (scanf("%d%d%lld%d",&a,&c,&m,&x)!=EOF)
    {
        shuju[0].num=x;shuju[0].xiabiao=0;
        for ( i = 1; i <= tt; ++i) {
            //x=(a*x+c)%m;
            //shuju[i].num=x;
            shuju[i].num=(a*shuju[i-1].num+c)%m;
            shuju[i].xiabiao=i;
        }
        qsort(shuju,tt+1,sizeof (shuju[0]),cmp);
        t=-1;
        for ( i = 0; i <tt; i++) {
            if (shuju[i].num==shuju[i+1].num)
            {
                t=shuju[i+1].xiabiao-shuju[i].xiabiao;
                break;
            }
        }
        if (t==-1) printf("T > 10^4\n");
        else printf("T = %d\n",t);
        //memset(shuju,0,sizeof (shuju));
    }



}