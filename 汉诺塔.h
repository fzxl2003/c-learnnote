/*汉诺塔是一个经典的递归问题，
现在有一个三柱汉诺塔，这三个柱子各有标记（一个大写英文字母）。
在左边的柱上有n个圆盘，从上到下，每个圆盘依次被编号为：1,2,3,...,n。
 请你输出将该柱上的盘子全部搬动到最右边的柱子的最快方法。
搬动过程中规则如下：
一次只能搬动一片圆盘
编号大的圆盘不能出现在编号小的圆盘上面.
*/
/*汉诺塔解决思路
  解题思路：
1、把A柱子上的前N-1个盘子借助C柱子，全部移动到B柱子上（过程暂不考虑），再把第N个盘子由A柱子移动到C柱子上。
那么剩下要移动的盘子在B柱子上了。
2.把B柱子上的前N-2个盘子借助C柱子，全部移动到A柱子上（过程暂不考虑），再把第N-1个盘子由B柱子移动到C柱子上。
*/

#include <stdio.h>
void print(int n ,char x,char y)
{
    printf("move %d from %c to %c\n",n,x,y);
}
void hannuota(int n,char x,char y,char z)
{
    if (n==1) print(1,x,z);
    else {
        hannuota(n-1,x,z,y);
        print(n,x,z);
        hannuota(n-1,y,x,z);
    }
}


int main()
{
    int n;
    char x,y,z;
    scanf("%d %c %c %c",&n,&x,&y,&z);
    hannuota(n,x,y,z);
}