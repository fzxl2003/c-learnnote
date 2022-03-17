/*
常用的头文件
C89标准库头文件
assert.h 运行时的断言检查
ctype.h 字符类型和映射
errno.h 错误信息及处理
float.h  对浮点数的限制
limits.h 编译系统实现时的限制
locale.h 建立与修改本地环境
math.h 数学函数库&&&
setjmp.h 非局部跳转
signal.h 事件信号处理
stdarg.h 变长参数表处理
stddef.h 公用的宏和类型
stdio.h 数据输入/输出&&&
stalib.h 不属于其他类别的常用函数
string.h 字符串处理
time.h 日期和时间


stdio.h头文件 数据输入/输出
1.函数及功能说明
int getchar ();
 返回从标准输入文件中读入的一个字符   当读到文件尾部时返回 EOF
int putchar (int c);
 向标准输出文件中写入一个字符  函数出错时返回 EOF
char *gets (char *buf):
 从标准输入文件中读入一行字符并将其保存于buf 所指向的存储区中
 当读到文件尾部或函数出错时返回NULL,否则返回存储区 buf
char *fgets(char *buf,int n, FILE *fp);
 从指定文件中读入一行不超过n-1个字符的字符串，将其保存于buf所指向的存储区中
 当读到文件尾部或函数出错时返回NULL,否则返回存储区 buf
int puts (const char*string);
 向标准输出文件中写入一行字符并将字符末尾的结束符'\0'替换为换行符'\n'
 函数出错时返回 EOF
int scanf (const char*format [, argument]... );
 根据fozmat 中的格式规定从标准输入文件中读入数据，并保存到由argument 指定的存储单元中
 当读到文件尾部或函数出错时返回 EOF 否则返回读入数据的个数
int printf(const char*format [, argument]... );
 根据format中的格式规定将指定数据写入标准输出文件中
 返回输出的字符数，函数出错时返回负值

2.const char*format
 * 表示这些参数都是指针类型
 const 为类型限定符 ，说明相应的变量或参数是只读的。
3.printf()与scanf()详见2.5
4.putchar()
   1.格式为putchar(c)
     其中c可以是被单引号（英文状态下）引起来的一个字符，可以是介于0~127之间的一个十进制整型数（包含0和127），也可以是事先用char定义好的一个字符型变量。
          1、当c为一个被单引号（英文状态下）引起来的字符时，输出该字符（注：该字符也可为转义字符）。
          2、当c为一个介于0~127（包括0及127）之间的十进制整型数时，它会被视为对应字符的ASCII代码，输出该ASCII代码对应的字符。
          3、当c为一个事先用char定义好的字符型变量时，输出该变量所指向的字符。



ctype.h 字符类型和映射
1.函数及功能说明
int isalnum (int c) 是否是字母或数字
int isprint (int c) 是否是可打印字符(0x20~0x7e)
int isalpha (int c) 是否是字母 (a~z，A~Z)
int ispunct (int c) 是否是符号（可打印但非字母数字）
int iscntrl (int c) 是否是控制符(0x00~0x1f, 0x7f)
int isdigit (int c) 是否是数字 (0~9）
int isgraph (int c) 是否是可打印字符（空格除外）
int islower (int c) 是否是小写字母 (a~z)
int isspace (int c) 是否是空白符(0x09,0xOd,0x20)
int isupper (int c) 是否是大写字母 (A~Z)
int isxdigit (int c) 是否是十六进制数字(0~9. a~f. A~F)
当字符符合所指定的类型时，函数返回真值1，否则返回假值 0
2.判断函数之间的关系表5-6 p99
3.大小写转换
int toupper (int c) ; 当参数c是小写字母时，toupper返回其对应的大写字母
int tolower (int c);  当参数c是大写字母时，tolower返回其对应的小写字母。
 当参数c是其他类型的字符时，这两个函数不对其进行任何转换，直按将参数原样返回。



string.h字符串处理函数
char *strcat (char*dst,char *src);             将src追加到ast 后
char *strncat (char*dst,char*src,size_t n);    将src 中前n个字符追加到dst后
char *strcpy (char*dst,char *src);             将src 复制到dst 中
char *strncpy (char*dst,char *src,size_t n);   将src中前n个字符复制到dst 中
size_t strlen(char *str);                      返回字符串str 的长度
int strcmp(char*s1,char* s2);                  比较字符串 s1 和s2
int strncmp(char*s1,char* s2, size_t n);       比较字符串 s1 和s2的前n个字符
char *strchr(char*str,int c);                  在str中查找c首次出现的位置
char *strrchr (char*str,int c);                在str 中查找c最后一次出现的位置
char *strstr (char*str,char *s1);              在str中查找 s1首次出现的位置


stdlib.h 不属于其他类别的常用函数
int abs (int n);                                                     n的绝对值
double atof (char *s);                                               将s转换为double 类型的数
int atoi (char *s);                                                  将s转换为 int 类型的数
void *bsearch (void*key,void*base,size_t num,size_t,width, int (*f) (void key*e1,void *e2 ))  以二分查找方式在排序数组 base 中查找元素
int rand();                                                          生成伪随机数
void srand (unsigned int s);                                         设置随机数种子
void exit (int status);                                              终止程序执行
void qsort(void*base,size_t,wiadh,int（*f)(void *e1, void *e2 ));    以快速排序方式对数组base 进行排序



 math.h 数学函数库
double sqrt (double x):                      x的平方根
double sin (double x);                       正弦函数，x以弧度为单位
double cos (double x);                       余弦函数，x以弧度为单位
double tan (double x);                       正切函数，x以弧度为单位
double atan (double x);                      反正切函数，返回值以孤度为单位
double atan2 (double y,double x);            反正切函数，返回值以弧度为单位，根据x和y的符号确定象限
double asin (double x);                      反正弦函数，返回值以弧度为单位
double acos (double x);                      反余弦函数，返回值以弧度为单位
double log (double x);                       x的自然对数
double log10 (double x);                     x的常用对数
double exp (double x);                       指数函数 e^x
double fabs (double x)x);                    x的绝对值
























 */