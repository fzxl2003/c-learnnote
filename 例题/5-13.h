#include <stdio.h>
int main513(m,n)
{
    if (m==0)
        return n+1;
    if (n==0)
        return main513(m-1,1);
    return main513(m-1, main513(m,n-1));
}