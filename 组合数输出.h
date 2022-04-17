#include <stdio.h>

void dfs(int ans[],int step, int now,int totalStep,int n) {
    int i;
    if (step == totalStep) {
        for (i = 0; i < totalStep; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (i = now; i <= n; i++) {
        ans[step] = i;
        dfs(ans,step + 1, i + 1,totalStep,n);
    }
}
int main() {
    int n, m,ans[10];
    // 18选6，这⾥的n和m可以⾃⾏改动
    n = 18;
    m = 6;


    dfs(ans,0, 1,m,n);

    return 0;
}