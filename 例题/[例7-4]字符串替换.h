#include <string.h>
#include <stdio.h>
void abc(char *str,char *ori,char *now)   //str为需要修改的字符串 ，ori为需要被修改的内容 ，now为将要更改的内容
{

    //char str[10000]={0};

    char *p= strstr(str,ori);
    if (p==NULL)
    {

    }
    *p='\0';
    sprintf(str,"%s%s%s",str,now,p+ strlen(ori));

}
int main()
{
    char str[10000]={0};
    while ((scanf("%s",str))!=EOF)
    {
        abc(str,"_xy_","_ab_");
        printf("%s",str);
    }
}