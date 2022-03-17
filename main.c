#include <stdio.h>
void mian132(long long x)        //十进制转二进制（打印输出）(以int为例)
{
    //printf("%d",sizeof(x)*4-1);
    for(int i=sizeof(x)*4-1;i>=0;i--)
        printf("%d",(x>>i)&1);   //（打印输出）

}
int main()
{long long x=432789;
    mian132(x);



}

