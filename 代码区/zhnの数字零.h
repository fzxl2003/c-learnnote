/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4319648
 Created at: Thu Apr 14 2022 18:09:03 GMT+0800 (China Standard Time)
 Problem_id: 5542	Time: 64	Memory: 23076
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long dp[205][205*65];
long long max(long long a,long long b)
{    return (a>b)?a:b;}
long long min(long long a,long long b)
{    return (a<b)?a:b;}
int main()
{
    int n,k,a2[203]={0},a5[203]={0};long long ll;
    scanf("%d%d",&n,&k);
    for (int j = 1; j <=n ; ++j)
    {
        scanf("%lld",&ll);
        int i;
        for (i = 0; ll%2==0 ; ++i) {
            ll/=2;
        }
        a2[j]=i;
        for (i = 0; ll%5==0 ; ++i) {
            ll/=5;
        }
        a5[j]=i;
    }
    memset(dp,-1,sizeof (dp));
    dp[0][0]=0;
    long long sum=0;
    for (int i = 1; i <=n ; ++i) {
        sum+=a5[i];
        for (long long j = min(n,k); j >=1 ; --j) {
            for (long long l = sum; l>=a5[i] ; l--) {
                dp[j][l]= max(dp[j][l],dp[j-1][l-a5[i]]+a2[i]);
            }
        }
    }
    long long ans=0;
    for (int i = 0; i <=sum ; ++i) {
        ans= max(ans,min(1ll*i,dp[k][i]));
    }
    printf("%lld",ans);


}