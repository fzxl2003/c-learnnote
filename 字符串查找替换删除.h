/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4395390
 Created at: Thu Apr 28 2022 10:51:37 GMT+0800 (China Standard Time)
 Problem_id: 5649	Time: 2	Memory: 1724
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int find(char text[],char str[],long long result[])  //text原始文本  //str查找内容 result存储所有查到的位置   //返回找到的次数
{
    char *ss=text;
    int zhaodao=0;int i=0;
    int textlen= strlen(text);
    int strlenl= strlen(str);
    while (ss-text<textlen)
    {
        char *aa=strstr(ss,str);
        if (aa!=NULL)
        {
            result[i]=aa-text+1;
            i++;
            //printf("%d ",aa-text+1);
            zhaodao=1;
            ss=aa+1;
        }
        else break;

    }
    if (zhaodao==0) { return 0;}
    //printf("\n");
    return i;
}

void replace(char text[],char str[],char restr[],char result[])  //将text中的所有特定字符串str替换为restr   //可选直接保存到text，也可保存到result
{
    result[0]=0;result[1]=0;
    char *ss=text;
    int zhaodao=0;
    int textlen= strlen(text);
    int strlenl= strlen(str);
    char linshi[1009];
    char *begin=text;
    while (ss-text<textlen)
    {
        char *aa=strstr(ss,str);

        if (aa!=NULL)
        {
            *aa=0;
            sprintf(linshi,"%s%s",begin,restr);
            strcat(result,linshi);
            begin=aa+strlenl;
            ss=aa+strlenl;
        }
        else break;
    }
    strcat(result,begin);
    //printf("%s",result);
    strcpy(text,result);   //可选
    //printf("\n");
}
void delete(char text[],char str[],char result[])  //将text中的所有特定字符串str删除   //可选直接保存到text，也可保存到result
{
    result[0]=0;result[1]=0;

    char *ss=text;
    int zhaodao=0;
    int textlen= strlen(text);
    int strlenl= strlen(str);
    char linshi[1009];
    char *begin=text;
    while (ss-text<textlen)
    {
        char *aa=strstr(ss,str);

        if (aa!=NULL)
        {
            *aa=0;
            sprintf(linshi,"%s",begin);
            strcat(result,linshi);
            begin=aa+strlenl;
            ss=aa+strlenl;
        }
        else break;

    }
    strcat(result,begin);
    strcpy(text,result);  //可选
    //printf("%s",text);
    //printf("\n");
}





int main()   //文本编辑器操作 1为查找 2为替换 3为删除
{
    char text[1009],str[1009],restr[1009];
    int ord;gets(text);char result[1009];long long result1[213];
    while ((scanf("%d",&ord))!=EOF)
    {  getchar();
        if (ord==1)
        {
            gets(str);
            int i=find(text,str,result1);
            for (int j = 0; j < i; ++j) {
                printf("%d ",result1[j]);
            }
            if (i==0) { printf("NOT EXIST");}
            printf("\n");
        }
        if (ord==2)
        {
            result[0]=0;result[1]=0;
            gets(str);
            gets(restr);
            replace(text,str,restr,result);
            printf("%s\n",text);
        }
        if (ord==3)
        {
            result[0]=0;result[1]=0;
            gets(str);
            delete(text,str,result);
            printf("%s\n",text);


        }
    }
}