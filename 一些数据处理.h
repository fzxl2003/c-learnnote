#include <stdio.h>
#include <math.h>
//long long dectobin( int n ){     //十进制转二进制（除法）（输出longlong）
//int convertBinaryToDecimal(long long n) //二进制转十进制
//long long mian123(long long a,int n,int x)  //替换二进制特定位的值  //a为要转化的数字，n为替换的值（0或1），x为位数
//long long mian1234(long long x,int n)  //提取二进制的特定位  //x为要转化的数字，n为位数
//void mian3(int radix,int num)  //十进制转2-36其他进制  //radix为进制  num为十进制数
//void mian132(long long x)        //十进制转二进制（打印输出）(以int为例)
//long long int sum = 0xffffffffLL;  //二进制32个1的整数
//int  data(int m)  //判断十进制位数
//unsigned int mian2(unsigned int a1,int begin,int end,int n)   //替换二进制中特定连续位置，begin和end从0位开始，n为要替换的数，a1为被替换数
//unsigned int mian4(unsigned int a1,int begin,int end)  //翻转特定位，从0位开始
//long long int main5(long long a)   //高低位交换,前16位与后16位交换
//void main7(long long a,int d[],int i)   //分离十进制数a的各位，存储在d[],调用时i=0
//void a()                            //printf输出八进制/十六进制
long long dectobin( int n ){     //十进制转二进制（除法）（输出longlong）
    long long k=1,i,temp;
    long long result=0;
    temp = n;
    while(temp){
        i = temp%2;
        result = k * i + result;
        k = k*10;
        temp = temp/2;
    }
    return result;
}

int convertBinaryToDecimal(long long n) //二进制转十进制
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}



long long mian123(long long a,int n,int x)  //替换二进制特定位的值  //a为要转化的数字，n为替换的值（0或1），x为位数
{
    if (n==1)
        a &= (~(1 << x));   //将a的二进制第x位替换为0
    else  a|=(1<<x);        //将a的二进制第x位替换为1
    return a;
}

long long mian1234(long long x,int n)  //提取二进制的特定位  //x为要转化的数字，n为位数
{
    return x&(1<<n);           //取出x的第m位，保存在a中（若为1，则a=2^m,否则a=0）

}





void mian3(int radix,int num)  //十进制转其他进制  //radix为进制  num为十进制数
{    int arr[320] = {0},i=0;
    if (num==0 ||radix==0) {printf("0\n");return;}     //排除特殊情况0
    while(num){                              //整除取余
        arr[i] = num % radix;
        num /= radix;
        i++;
    }
    while(i--){
        if (arr[i]>=10){ putchar(arr[i]-10+'A');}  //倒序输出
        else putchar(arr[i] + '0');
    }
}
void mian132(long long x)        //十进制转二进制（打印输出）(以int为例)
{
    for(int i=sizeof(x)*4-1;i>=0;i--)
    printf("%d",(x>>i)&1);
}



long long int sum = 0xffffffffLL;  //二进制32个1的整数

int  data(int m)  //判断十进制位数
{
    int n;
    if(m==0)  return 0;
    n=data(m/10)+1;
    return n;
}

unsigned int mian2(unsigned int a1,int begin,int end,int n)   //替换二进制中特定连续位置，begin和end从0位开始，n为要替换的数，a1为被替换数
{
    a1&=~(((1<<(end-begin+1))-1)<<begin);
    a1|=(n<<begin);
    return a1;
}

unsigned int mian4(unsigned int a1,int begin,int end)  //翻转特定位，从0位开始
{
    a1^=(((1<<(end-begin+1))-1)<<begin);
    return a1;
}

long long int main5(long long a)   //高低位交换,前16位与后16位交换
{
    a=((a&65535)<<16)+((a&4294901760)>>16);

    return a;
}
void main7(long long a,int d[],int i)   //分离十进制数a的各位，存储在d[],调用时i=0
{
    if (a){
        int e=a/10;
        d[i]=a-e*10;
        main7(e,d,i+1);}
}
int main32(long long n)    //分离十进制数a的各位，存储在d[],调用时i=0
{int a[100];int i;
    for (i=0;n>0;i++)
    {
        a[i]=n-(n/10)*10;
        n/=10;
    }
    while (i--)
    { printf("%d",a[i]);}


    // b[0]=n/100;  //分离四位数前两位
    //b[1]=n%100;  //分离四位数后两位
}
void a() {                           //printf输出八进制/十六进制
    printf("0%o\n", 10);    //printf输出八进制
    printf("0x%x\n", 10);  //printf输出十六进制

}