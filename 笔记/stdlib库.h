/*1	double atof(const char *str)
把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
2	int atoi(const char *str)
把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
3	long int atol(const char *str)
把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
4	double strtod(const char *str, char **endptr)
把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
5	long int strtol(const char *str, char **endptr, int base)
把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
6	unsigned long int strtoul(const char *str, char **endptr, int base)
把参数 str 所指向的字符串转换为一个无符号长整数（类型为 unsigned long int 型）。
7	void *calloc(size_t nitems, size_t size)
分配所需的内存空间，并返回一个指向它的指针。
8	void free(void *ptr)
释放之前调用 calloc、malloc 或 realloc 所分配的内存空间。
9	void *malloc(size_t size)
分配所需的内存空间，并返回一个指向它的指针。
10	void *realloc(void *ptr, size_t size)
尝试重新调整之前调用 malloc 或 calloc 所分配的 ptr 所指向的内存块的大小。
11	void abort(void)
使一个异常程序终止。
12	int atexit(void (*func)(void))
当程序正常终止时，调用指定的函数 func。
13	void exit(int status)
使程序正常终止。
14	char *getenv(const char *name)
搜索 name 所指向的环境字符串，并返回相关的值给字符串。
15	int system(const char *string)
由 string 指定的命令传给要被命令处理器执行的主机环境。
16	void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
执行二分查找。
17	void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
数组排序。
18	int abs(int x)
返回 x 的绝对值。
19	div_t div(int numer, int denom)
分子除以分母。
20	long int labs(long int x)
返回 x 的绝对值。
21	ldiv_t ldiv(long int numer, long int denom)
分子除以分母。
22	int rand(void)
返回一个范围在 0 到 RAND_MAX 之间的伪随机数。
23	void srand(unsigned int seed)
该函数播种由函数 rand 使用的随机数发生器。
24	int mblen(const char *str, size_t n)
返回参数 str 所指向的多字节字符的长度。
25	size_t mbstowcs(schar_t *pwcs, const char *str, size_t n)
把参数 str 所指向的多字节字符的字符串转换为参数 pwcs 所指向的数组。
26	int mbtowc(whcar_t *pwc, const char *str, size_t n)
检查参数 str 所指向的多字节字符。
27	size_t wcstombs(char *str, const wchar_t *pwcs, size_t n)
把数组 pwcs 中存储的编码转换为多字节字符，并把它们存储在字符串 str 中。
28	int wctomb(char *str, wchar_t wchar)
检查对应于参数 wchar 所给出的多字节字符的编码。

 */