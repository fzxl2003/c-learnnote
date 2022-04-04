/*
 rand函数
 1.库：stdio.h  附带函数的库time.h stdlib.h
 2.函数声明：int rand(void)
 3.作用：返回一个范围在 0 到 RAND_MAX 之间的伪随机数。
          RAND_MAX 是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 32767。
 4.生成给定范围的正随机数(生成0-10000的随机数)
    srand((int)time(0));
    x=rand()%10000;

 */