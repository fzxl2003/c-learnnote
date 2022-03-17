#include <stdio.h>
int main512(m,n)
{

    if (m<n||m<1||n<1)
        return 0;
    if (m==n)
        return 1;
    if (n==1)
        return m;
    return main512(m-1,n)+ main512(m-1,n-1);
}