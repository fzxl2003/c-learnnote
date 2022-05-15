#include <stdio.h>
int main43()
{
    int n,a=1,b=1;
    scanf("%d",&n);
    for (int i=3;i<=n;i++)
    {
        b=a+b;
        a=b-a;

    }
    printf("%d",b);
}




//进阶版
#include <stdio.h>
#define int long long
const int modd=1e9+7;
int n;
/*这里定义矩阵类型的结构体*/
typedef struct{
    int a[5][5];
}jv;
jv p,ans;
/*
我定义了一个 jv类型的函数，他返回的类型，就是我上面定义的结构体
这个函数就是传入两个矩阵，返回他们的乘积，中间的计算就是矩阵乘法
为什么是2*2，因为我的快速幂是用来计算我构造的那个2*2的矩阵幂次的
*/
jv cheng(jv xx,jv yy){
    int sum;
    jv an;
    for(int i=1;i<=2;i++){
        for(int w=1;w<=2;w++){
            sum=0;
            for(int j=1;j<=2;j++){
                sum=(sum+xx.a[i][j]*yy.a[j][w]%modd)%modd;
            }
            an.a[i][w]=sum%modd;
        }
    }
    return an;
}
/*
魔法少女的快速幂（矩阵版）
*/
jv pow(int x){
    jv temp=p;
    jv base=p;
    x--;
    while(x){
        if(x&1) temp=cheng(temp,base);
        base=cheng(base,base);
        x>>=1;
    }
    return temp;
}
/*因为我懒，把int定义成Long long了，所以这里不能写int main了*/
signed main(){
    scanf("%lld",&n);
    if(n<=2) printf("1");
    else{
        ans.a[1][1]=1;
        ans.a[1][2]=1;
        p.a[1][1]=1;
        p.a[1][2]=1;
        p.a[2][1]=1;
        p.a[2][2]=0;
        jv tt=pow(n-2);
        ans=cheng(ans,pow(n-2));
        //矩阵快速幂加速递推⼤概不在我们考试范围内，但可以当作⼀个有意思的idea欣赏⼀下，嘿嘿嘿
        int kk=(ans.a[1][1]%modd+modd)%modd;
        printf("%lld",kk);
    }
    return 0;
}