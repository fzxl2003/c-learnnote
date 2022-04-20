/*
 题目描述
zhn在疯狂星期四中花光了自己所有的钱（QTAQ），于是他和yh决定去通过探险来获得更多的Money，现在有这样一道带有密码的门挡在了他们面前。
门上有一串由′0′−′9′组成的、长度为n的字符串，并且有一个数字k，门的密码是：你在这串数字中添加k个 ′+′ 号（添加后表达式合法），然后所有拆分所得的所有合法表达式之和。（具体看输入样例）由于这个数字很大，你只需要输出他对109+7取模的答案即可。
众所周知，yh是数学爷爷，他很快就解决了这道题，你们能帮帮zhn这个baka来解决一下这个问题吗？

输入
第一行包含两个整数，n和k (0≤k<n≤105)
第二行包含一个由n个数字组成的字符串。

输出
输出对109+7取模的答案
 */

/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4273677
 Created at: Mon Apr 04 2022 08:27:05 GMT+0800 (China Standard Time)
 Problem_id: 5485	Time: 173	Memory: 4912
*/

#include <stdio.h>


#define ll long long

int mod = 1000000007;


long long fac[100005],inv[100005],jia[100005],a[100005];
char s[100005];
int n,k;
ll result,mm;
ll mod_pow(ll x,ll n){
    x%=mod;
    ll res = 1;
    while(n>0){
        if(n&1) res = res*x%mod;
        x = x*x%mod;
        n>>=1;
    }
    return res;
}
void init(){
    inv[0]=1;fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i] = (fac[i-1]*i)%mod;
        inv[i] = mod_pow(fac[i],mod-2)%mod;
    }
}
ll C(ll n,ll m){
    if(n<0||m<0) return 0;
    if(m>n) return 0;
    return (((fac[n]*inv[m])%mod)*inv[n-m])%mod;
}
int main()
{
    scanf("%d%d",&n,&k);
    init();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        a[i] = s[i]-'0';
    mm = 1;
    for(int i=n-1;i>=1;i--){
        jia[i] = (jia[i+1]+mm*C(i-1,k-1))%mod;
        mm = (mm*10)%mod;
    }
    mm = 1;
    for(int i=n;i>=k+1;i--){
        jia[i] = (jia[i]+C(i-1,k)*mm)%mod;
        mm = (mm*10)%mod;
    }
    result = 0;
    for(int i=1;i<=n;i++)
        result = (result+jia[i]*a[i])%mod;
    printf("%lld\n",result);
}