/*
 * https://accoding.buaa.edu.cn/contest-ng/index.html#/833/problems
 C5-2021级航类-第五次上机
A LJF算距离
B 简单的查找                   //查找第三大的数
C 宋老师的名次预测3.0
D 实矩阵乘法简单版               注意矩阵乘法公式
E 上 α 分位点                   二分法解函数
F Java今天吃什么α 分位点          注意输入问题
G 爱偷懒的球场管理员               //贪心算法,详见区间合并.h
H 方阵数局
I zhnの数字零       不会不会       //贪心算法，详见zhnの数字零.h
J 图图玩狼人杀2.0
K 虚假的签到题             看解析

 查找第三大数
 在a[n]中找到第三大数
 int max1=1<<31, max2=1<<31, max3=1<<31;
  for(i=0; i<=n; ++i)
 if(a[i] > max1){
 max3 = max2;
 max2 = max1;
 max1 = a[i];
 }
 else if(a[i] > max2){
 max3 = max2;
 max2 = a[i];
 }
 else if(a[i] > max3) max3 = a[i];
 printf("%d\n", max3);
 */