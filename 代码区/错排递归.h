#include<stdio.h>
#include<math.h>
long long sum=0;int a[22];
long long send(int n)
{
    if (n==1) return 0;
    if (n==2) return 1;
    return (n-1)*(send(n-1)+ send(n-2));
}
int  main()
{
    int n;
    while ((scanf("%d",&n))!=EOF)
    {
        sum=send(n);
        //sum--;
        printf("%lld\n",sum);
    }

}