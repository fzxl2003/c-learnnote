/*
 Author: 潘宇恒
 Result: REG	Submission_id: 4402135
 Created at: Sun May 01 2022 22:26:38 GMT+0800 (China Standard Time)
 Problem_id: 5719	Time: 142	Memory: 2140
*/

/*
 Author: 潘宇恒
 Result: REG	Submission_id: 4396960
 Created at: Sat Apr 30 2022 11:13:35 GMT+0800 (China Standard Time)
 Problem_id: 5719	Time: 144	Memory: 2140
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double xiangliang[12][15]={0};
int cmp(const void* p1, const void* p2) {  //升序排列
    double* a = (double*)p1, * b = (double*)p2;
    if (a[12] > b[12])return -1;
    else if (a[12] < b[12]) return 1;
    else return 0;
}
int cmp2(const void* p1, const void* p2) {  //升序排列
    double* a = (double*)p1, * b = (double*)p2;
    if (a[13] > b[13])return -1;
    else if (a[13] < b[13]) return 1;
    else return 0;
}
int cmp3(const void* p1, const void* p2) {  //降序排列
    double* a = (double*)p1, * b = (double*)p2;
    if (a[14] < b[14])return -1;
    else if (a[14] > b[14]) return 1;
    else return 0;
}
void paixu(double a[][15],int n)
{int begin,end,panduan=0;
    qsort(a,n,sizeof (a[0]),cmp);
    for (int i = 0; i < n; ++i) {
        if (a[i][12]==a[i+1][12])
        {
            if (panduan==0)
            {panduan=1;begin=i;}
        }
        else {
            if (panduan==1)
            {panduan=0;end=i;
                qsort(a+begin,i-begin+1,sizeof (a[0]),cmp2);

            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13])
        {
            if (panduan==0)
            {panduan=1;begin=i;}
        }
        else {
            if (panduan==1)
            {panduan=0;end=i;
                qsort(a+begin,i-begin+1,sizeof (a[0]),cmp2);

            }
        }
    }
}

int main()
{

    int n;double beita[14][14]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf",&xiangliang[i][j]);

        }
        xiangliang[i][14]=i;
    }
    for (int i = 0; i < n; ++i) {
        int sum0=0;
        //double changdu2=0;
        for (int j = 0; j < n; ++j) {
            xiangliang[i][13]+=xiangliang[i][j]*xiangliang[i][j];
            if (xiangliang[i][j]==0)
            {
                sum0++;
            }
        }
        xiangliang[i][12]=sum0;
    }
    paixu(xiangliang,n);
    for (int i = 0; i < n; ++i) {
        for (int m = 0; m < n; ++m) {
            beita[i][m]=xiangliang[i][m];
        }
        for (int j = i-1; j >=0 ; --j) {
            double fenmu=0;double fenzi=0;
            for (int k = 0; k < n; ++k) {
                fenzi+=xiangliang[i][k]*beita[j][k];
                fenmu+=beita[j][k]*beita[j][k];
            }
            for (int m = 0; m < n; ++m) {
                beita[i][m]-=beita[j][m]*fenzi/fenmu;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        double changdu1=0;
        for (int j = 0; j < n; ++j) {
            changdu1+=beita[i][j]*beita[i][j];
        }
        changdu1= sqrt(changdu1);
        for (int j = 0; j < n; ++j) {
            printf("%.4f ",beita[i][j]/changdu1);
        }
        printf("\n");
    }

}