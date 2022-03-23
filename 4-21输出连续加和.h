#include <stdio.h>
int main1234(){
    int n, sum = 0; int abc = 0; int l;
    scanf("%d", &n );
    for (int i = 1; i <= n/2; i++)
    {for (int j = i; sum < n; j++)
        {sum += j;
            if (sum == n)
            {abc++; sum = 0;
                printf("%d = ", n );
                for (l = i; sum+l < n; l++ )
                { printf("%d+", l); sum += l; }
                printf("%d\n", l);
            }



        }
        sum = 0;
    }
    printf("case:%d", abc);
}