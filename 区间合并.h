




//方法一：排序法，数据量相对较小，但每个数据较大（达到 量级），适合使用排序。
//方法二：散列表法，适用于数据量大，但数据较小



/*    方法一
 将所给的区间全部合并，并且返回一个不重叠的时间段数组t，t恰好覆盖所有的区间
 输入格式
  n+1行。
第一行n表示一共有n个区间
接下来n行，每行两个整数，分别表示区间i的开始点si和结束点ei。

输出格式
若干行。
每行两个整数，分别表示数组t的第i个区间的起点和终点。
数组t包含若干个不重叠的区间段，并且满足这些时间段的并集恰好覆盖所有的区间。
按照时间段开始时间点的升序输出结果
。
 */


/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4319846
 Created at: Thu Apr 14 2022 19:49:51 GMT+0800 (China Standard Time)
 Problem_id: 5496	Time: 8	Memory: 1700
*/

#include <stdio.h>
int main() {
    int n;long long a[1003][2]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }
    long long temp,aa=0;
    for (int i = 0; i < n-1; ++i) {    //冒泡排序将所有区间起点升序排列
        aa=0;
        for (int j = 0; j < n-1-i; ++j) {
            if (a[j][0]>a[j+1][0])
            {temp=a[j+1][0];

                a[j+1][0]=a[j][0];
                a[j][0]=temp;
                temp=a[j+1][1];
                aa=1;
                a[j+1][1]=a[j][1];
                a[j][1]=temp;
            }
        }
        if (aa==0) break;
    }
    int now=1;
    for (int i = 1; i < n; ++i) { //当前一个区间的结束点大于后一个区间的开始点 同时后一个区间的结束点大于该区间的结束点时发生合并
        if (a[now-1][1]>=a[i][0])
        {if (a[now-1][1]<a[i][1])a[now-1][1]=a[i][1];}
        else {        //出现分离时会重新开一个区间
            a[now][0]=a[i][0];
            a[now][1]=a[i][1];
            now++;
        }
    }
    for (int i = 0; i < now; ++i) {
        printf("%lld %lld\n",a[i][0],a[i][1]);
    }

}









/*
 给出 n 个浮点数闭区间进行区间合并，将这些区间合并为不相交的闭区间。

输入格式
第一行，一个正整数 n，表示区间个数。
接下来 n 行，每行包含两个以空格分隔的浮点数 min、max，表示红包区间 [min, max]，每个浮点数有且仅有两位小数。

输出格式
输出若干行，表示合并后的区间，每行包含两个以空格分隔的浮点数 left、right，表示区间 [left, right]，各区间按升序排列输出。
 */





#include <stdio.h>
#include <math.h>

#define MAX_N (1024*1024)
int range[MAX_N];
void print_zone()
{
    int i, n;
    for(i=0;i<MAX_N;i++){
        if(range[i]==0)
            continue;
        printf("%.2f ", 1.0*i/100);
        for(n=range[i];i<=n;i++)
            if(range[i] >n)
                n = range[i];i--;
        printf("%.2f\n", 1.0*i/100); }
}



int main(){
    int a, b;double aa,bb;
    scanf("%d",&a);
    while(scanf("%lf%lf",&aa,&bb)== 2){
        a=(int)round(aa*100);
        b= (int)round(bb*100);
        if(b>range[a])
            range[a]=b;     //aa为左端点，b为右端点
    }
    print_zone();
    return 0;
}



