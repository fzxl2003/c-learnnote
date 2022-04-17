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
        if (*s=='['||*s=='(')  push(*s);
        if (*s==']'||*s==')')
        {
            if (stack_empty()==0 && pop()==((*s==']')?'[':'('))
                continue;
            else return -1;
        }

    }
    return 1;
}