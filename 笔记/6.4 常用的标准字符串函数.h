/*
字符串输出函数  puts(),fputs(),printf()，sprintf() (字符串构造)
字符串输入函数 scanf(),gets(),fgets()
字符串复制 strcpy(),strncpy() 头文件<string.h>
字符串追加函数 strcat(),strncat()  头文件<string.h>
字符串比较函数 strcmp(),strncmp()
字符串检查函数 strlen()长度,strchr() strrchr() 字符是否存在, strstr() strrstr() 字符串是否含于
字符串扫描函数 sscanf()
 puts()
1.函数原型：int puts(const char s[]);
2.函数参数既可以为一个字符串常量，也可以是字符数组(数组必须是字符串，以\0结尾)
3.函数结尾输出换行符

 fputs()
1.函数声明：char *fputs(char *s,FILE *fp)
2.若FILE *fp为stdout(标准输出，屏幕),即屏幕输出
3.返回值：正常时返回写入的最后一个字符，出错返回EOF
4.结尾不输出换行符


 printf()
 见2.5

 sprintf()
1.函数原型： int sprintf(char *buffer,char *format [, argument]...)
2.功能：动态生成字符串，生成printf()所需要的格式化字符串
3.字符数组buffer用于保存函数格式化字符串（在后续printf中使用）
 format和后续变量描述输出格式的字符串，类似于printf("%d",a)中的参数
4.例：输入x，m,输出精确到小数点后m位的sin(x)的值
 int main()
 {
  int m; double x; char format[32];
  scanf("%lf%d",&x,&m);  //获取x,m
  sprintf(format,"%%.%df\n",m); //生成printf()的格式化字符串，若m=1，则"%%.%df\n"代表 “%.1f\n”  (%%代表%)
  printf(format,sin(x));
  return 0;
 }

 scanf()
 见2.5


  sscanf()    //可用于字符串转其他类型变量
1.函数原型：
 int sscanf(const char *buffer,char *format [,argument]....);
 buffer为一个特定格式的字符串，保存等待分析读入的数据
 format用于描述输入数据的数量和类型的字符串，随后为与格式化字符串相对应的参数表（必须为相关变量的地址&<变量>或数组）
2.功能：以格式化的方式从字符串中读入数据
3.例 从时间格式dd/MMM/yyyy:hh:mm:ss中提取其中的各个部分
 01/AUG/2020:12:23:24
 char buf[]="01/AUG/2020:12:23:24";
 int day,year,h,m,s;char mon[5]="";
 sscanf(buf,"%d/%3c/%d:%d:%d:%d",&day,mon,&year,&h,&m,&s);b



 gets()
1.函数原型： char *get(char s);
2.从标准输入上读入一个连续的字符序列，直至遇到换行符或结尾     scanf()  输入结束标记为空白符或换行符
 并将其保存到参数所指定的字符数组s[]中
 结尾加'\0',不加换行符
 执行错误时，返回NULL
 正确执行返回s的指针

 fgets()
1.函数原型： char *fgets(const char *s,int n,FILE *fp);
2.函数参数既可以为一个字符串常量，也可以是字符数组(数组必须是字符串，以\0结尾)
3.函数结尾不自动输出换行符
4.最多读入n-1个字符，如果提前遇到了\n，将会结束读取(\n被读入数组中)结束后末尾添'\0'
5.若FILE *fp为stdin(标准输入，键盘),即读入键盘输入
6.返回值：正常执行返回字符串首地址即s，出错时返回NULL
7.与gets()的不同点
  1.fgets()最多读入n-1个字符，第n个字符为'\0'
  2.若n足够大，且输入的数据含有换行符，则s[]中将会保存该换行符
  3.在使用fgets()时必须指明数据的来源
     例如：使用标识符stdin说明数据来自标准输入，fgets(string,N,stdin)


 strcpy()与strncpy()
1.函数原型： char *strcpy(char dest[],char src[]);
          char *strncpy(char dest[],char src[],int n);
2.功能：将src[]的字符串复制到dest[]中，并返回dest[]
   strcpy()复制src[]中的全部内容，直至遇到'\0'
   strncpy()复制src[]中前n个字符或者遇到'\0'
   若n小于等于src的字符长度时可能需要手动在末尾添'\0'
3.例：
 char s[32];
 strcpy(s,"this is a book");
 strncpy(s,"that is not his pen",10);
 puts(s);    //输出that is nobook
4.strcpy()函数等价代码
  char *strcpy(char dest[],char src[])
  {
   int i;
   for(i=0;(dest[i]=src[i])!='\0';i++);
   return dest;
  }


 strcat()和strncat()
1.函数原型：
 char *strcat(char dest[],char src[]);
 char *strncat(char dest[],char src[],int n);
2.功能：将数组src[]中的字符串复制到dest[]中已有的字符串后面（dest尾部的\0被抹去），并返回dest[]
       dest[]中必须保存有以'\0'的字符串
3.两者区别：strcat()复制src[]中的全部内容，直至遇到'\0'
         strncat()复制src[]前n个字符或者遇到'\0'
         若n小于等于src的字符长度时可能需要手动在末尾添'\0'
4.strcat()等价代码
 char *strcat(char dest[],char src[])
 {
  int i=0,j=0;
  while (dest[i]!='\0') i++;
  while ((dest[i++]=src[j++])!='\0');
 }


 strcmp()和strncmp()
1.函数原型：
 int strcmp(char s1[],char s2[]);
 int strncmp(char s1[],char s2[],int n);
2.功能：strcmp()判断两个字符串是否相同
      strncmp()判断两个字符串前n个字符是否相同
      若相同返回0，反之对当前遇到的不同的字符根据编码值比较大小，返回特定值
       （在很多编译器中，若不同字符s1的ASCII编码大于s2，则返回1，反之返回-1）
3.strcmp()等价代码
 int strcmp(char s1[],char s2[])
 {
  int i;
  for (i=0;s1[i]==s2[i];i++)
   if (s1[i]=='\0') return0;
  return ((s1[i]>s2[i])?1:-1);
 }

 strlen()
1.函数原型：int strlen(char s[]);
2.功能：返回字符串s中除结束符'\0'外的字符数量
3.与sizeof的区别：sizeof可用于所有数组或变量，返回数组或变量所占字节
                 strlen只能用于字符串数组
                char a[]="123"    sizeof(a)返回4 strlen(a)返回3
                char a[10]="123"  sizeof(a)返回10 strlen(a)返回3

 strchr()和strrchr()
1.函数原型：
  char *strchr(char *s,int c);
  char *strrchr(char *s,int c);
2.功能：若字符串s中存在字符c，strchr()和strrstr()分别返回字符c在s中第一次和最后一次出现的位置的指针。
      若字符串s中没有字符c，则返回NULL

 strstr()和strrstr()
1.函数原型：
 char *strstr(char *s,char *s1);
 char *strrstr(char *s,char *s1);
2.功能：若字符串s中存在子串s1，strchr()和strrstr()分别返回子串s1在s中第一次和最后一次出现的位置。
      若字符串s中没有子串s1，则返回NULL



 */