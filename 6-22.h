#include <stdio.h>
int main622(int year,int month,int day)
{
    int monday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i,daysum=0,a=0;
    a= ((((year%100)!=0) && (year%4)==0)||(((year%100)==0)&&(year%400)==0));
    if ((((month!=2)&&(day<1 || day>monday[month]))||((month==2)&&(day<1||(day>28+a))))||(month<1 || month>12)) return 0;
    for (i=1;i<month;i++)
    {daysum+=monday[i];}
    daysum+=day;
    daysum+=a;
    return daysum;



}