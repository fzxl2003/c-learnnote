/*
强制类型转换
 1.语法： (<类型名>)<表达式>
 2.强制类型转换的优先级高于运算符
 3.表达式不加括号会对紧接着类型名的变量进行类型转换
    若表达式添加括号会对未转换类型的表达式计算后的值进行类型转换
    例：(double) 7/5   //得到1.4
        (double) (7/5)  //得到1.0
 4.用途1  分离浮点数的整数部分和小数部分
      int main()
   {
        int int_part;
        double x,double_part;
        x=10.56;
        int_part=(int)x;                          //获取整数部分
        double_part=x-int_part;                   //获取小数部分
        printf("%d  %f",int_part,double_part);    //打印
        return 0;
    }
 5.用途2  四舍五入
   将浮点数加上 0.5，再进行整数小数分离
 6.a=b+(int) f






 */