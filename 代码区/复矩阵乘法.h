/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4324104
 Created at: Sat Apr 16 2022 08:57:05 GMT+0800 (China Standard Time)
 Problem_id: 5556	Time: 6	Memory: 1732
 输入
共2N+1行。
第一行为一个正整数N，表示N阶矩阵。
接下来N行为矩阵A的每个元素，每行包含N个虚数，以空格相间隔，表示矩阵的一行。
接下来N行为矩阵B的每个元素，每行包含N个虚数，以空格相间隔，表示矩阵的一行。

输出
共N行，每行包含N个虚数，表示A×B矩阵的一行，以空格相间隔。
对于复数的输出，现进行以下约定。
输出数据的实部或虚部如果为零，则不输出该部分（如果都为零则输出0，如虚部为0且实部为正数则省略+号）。
输出数据的虚部若为1或-1，需输出i或-i，不能输出1i或-1i。

输入样例
3
1+5i 6-9i 4+7i
3+9i 9-8i 1+2i
4+4i 3+4i 3+6i
3+9i 9-8i 1+4i
4+3i 2+4i 2+6i
1+5i 6-9i 4+7i
输出样例
-22+33i 184+49i 14+83i
-21+56i 173+80i 23+74i
-51+94i 130+33i -60+91i
*/

#include <stdio.h>
#include <stdlib.h>
long long result[11][11][2]={0};
void chengfa(long long a1,long long a2,long long b1,long long b2,long long hang,long long lie)
{
    result[hang][lie][0]+=a1*b1-a2*b2;
    result[hang][lie][1]+=a1*b2+a2*b1;
}
void print(long long n)
{
    for (long long i = 1; i <=n ; ++i) {
        for (long long j = 1; j <=n ; ++j) {
            if (result[i][j][0]==0 && result[i][j][1]==0)
                printf("0");
            else if (result[i][j][0]!=0 && result[i][j][1]==0)
                printf("%lld",result[i][j][0]);
            else if (result[i][j][0]==0 && result[i][j][1]!=0)
            {
                if (result[i][j][1]==-1) printf("-i");
                else if (result[i][j][1]==1) printf("i");
                else printf("%lldi",result[i][j][1]);
            }
            else{
                printf("%lld",result[i][j][0]);
                if (result[i][j][1]==-1) printf("-i");
                else if (result[i][j][1]==1) printf("+i");
                else printf("%+lldi",result[i][j][1]);}
            printf(" ");
        }
        printf("\n");
    }
}
int main()
{
    int n;long long aa[11][11][2]={0},bb[11][11][2]={0};
    scanf("%d",&n);
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            scanf("%lld%lldi",&aa[i][j][0],&aa[i][j][1]);
        }
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            scanf("%lld%lldi",&bb[i][j][0],&bb[i][j][1]);
        }
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            for (int k = 1; k <=n ; ++k) {
                chengfa(aa[i][k][0],aa[i][k][1],bb[k][j][0],bb[k][j][1],i,j);
            }
        }
    }
    print(n);

}