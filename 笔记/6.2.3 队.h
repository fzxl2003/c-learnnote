/*
 队
1.本质:数组
2.读取顺序：先进先出，后进后出
3.队的四个操作
  队的初始化、入队、出队、检查队是否为空、检查队是否已满
  对于循环的队还有检查队的数据是否达到n-1（检查队是否已满）
             检查队尾是否达到数组下标最大值
4.队的初始化
 int queue[MAX],head=0,tail=0;
 queue[MAX]为队的储存空间，head表示队头位置，tail表示队尾位置
5.入队
 void put(int v)
 {queue[tail++]=v;}  //当数据进入队中，根据tail将数据放入队尾，然后tail加1
6.出队
 int get()
 {return queue[head++];}  //当数据出队，根据head读取队头数据，然后head加1
7.检查队是否为空
 int queue_empty()
 {return head>=tail;}  //如果队头大于等于队尾，代表队为空
8.检查队是否已满（非循环队）
 int queue_full()
 {return tail>=MAX;}

9.循环队列
 const int MAX=10;
int queue[10],head=0,tail=0;
void put(int v)
{queue[tail++]=v;tail=tail%MAX;}  //当数据进入队中，根据tail将数据放入队尾，然后tail加1
int get()
{return queue[head++];head=head%MAX;}  //当数据出队，根据head读取队头数据，然后head加1
int queue_empty()
{return head==tail;}  //如果队头大于等于队尾，代表队为空
int queue_full()
{return (((head-tail)==1)||((tail-head)==MAX-1))?1:0;}

 */