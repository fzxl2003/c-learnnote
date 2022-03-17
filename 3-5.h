#include <stdio.h>
#include <math.h>

    int main3_5()
    {
        double a,b,c,t,result1,result2;
        scanf("%lf%lf%lf",&a,&b,&c);
        t=b*b-4*a*c;
        if (t < 0.0)
            printf("no real roots");
        else
        {
            result1=(-b+sqrt(t))/(2*a);
            if (t==0.0)
            {

                printf("%.6f %.6f",result1,result1);
            }
            else
            {
                result2=(-b-sqrt(t))/(2*a);
                printf("%.6f %.6f",result2,result1);

            }
        }
        return 0;








    }
