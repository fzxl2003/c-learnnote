/*
 输入
一个括号串。
输出
若括号串可正常使用，输出AC，不成功输出CE。
 输入样例1
([{}])[]{}
输出样例1
AC
输入样例2
([)]
输出样例2
CE
 */
#include <stdio.h>

int stack[300],s_top=0;
void push(int v)
{stack[s_top++]=v;}   //根据栈顶标记的指示，将数据放入栈顶单元，然后将栈顶标记变量加一

int pop()
{return stack[--s_top];}   //将栈顶标记变量减1，再将所指的数据读出

int stack_empty()
{return s_top==0;}  //判断s_top是否为0

int main615(char* a)
{
    char* s;
    for (s=a;*s!='\0';s++)
    {
        if (*s==' ') continue;
        if (*s=='['||*s=='('||*s=='{')  push(*s);
        if (*s==']'||*s==')'||*s=='}')
        {
            if (stack_empty()==0)
            {
                int aaa=pop();
                if ((*s==']'&&aaa=='[')||(*s=='}'&&aaa=='{')||(*s==')'&&aaa=='('))
                    continue;
                else return -1;
            }
            else return -1;
        }

    }
    if (stack_empty()==0) return -1;
    return 1;
}
char aa[999999999];
int main()
{

    gets(aa);
    int m=main615(aa);
    if (m==1) printf("AC");
    else printf("CE");
}