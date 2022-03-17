/*
 栈
1.本质：数组
2.数据存取数据：先进后出
3.栈的四种操作
   栈的初始化、进栈（压栈）、出栈（弹栈）、检查栈是否为空
4.栈的初始化
  定义 int stack[MAX],s_top=0;
  stack[MAX]为栈的储存空间，s_top为栈顶指针（初始化为0）
5.进栈（压栈）
 void push(int v)
 {stack[s_top++]=v;}   //根据栈顶标记的指示，将数据放入栈顶单元，然后将栈顶标记变量加一
6.出栈（弹栈）
 int pop()
 {return stack[--s_top];}   //将栈顶标记变量减1，再将所指的数据读出
7.检查栈是否为空
 int stack_empty()
 {return s_top==0;}  //判断s_top是否为0
8.例6-15




 */