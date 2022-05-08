/*

结构体 struct
 功能：结构体（Struct）来存放一组不同类型的数据
 结构体是一种自定义的数据类型，是创建变量的模板，不占用内存空间；结构体变量才包含了实实在在的数据，需要内存空间来存储。
一.结构体的定义、赋值与使用
 1.定义
     struct 结构体名{
        结构体所包含的变量或数组
       };

  struct stu{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在学习小组
    float score;  //成绩
    };
 2.结构体变量
 用结构体定义的变量
 定义方式：
   法一  struct stu stu1, stu2;  //定义了stu1，stu2两个类型为stu结构体的变量
   法二  定义结构体时定义结构体变量
       例
           struct stu{
              char *name;  //姓名
              int num;  //学号
              int age;  //年龄
              char group;  //所在学习小组
              float score;  //成绩
                   } stu1, stu2;  //定义了stu1，stu2两个类型为stu结构体的变量
   如果只需要 stu1、stu2 两个变量，后面不需要再使用结构体名定义其他变量，那么在定义时也可以不给出结构体名（stu可直接省略）
  3.结构体变量的调用
    1.调用方式：结构体变量名.成员名  如stu1.num  stu2.score
    2.赋值：
        初始化赋值  例struct{
                        char *name;  //姓名
                        int num;  //学号
                         int age;  //年龄
                         char group;  //所在小组
                        float score;  //成绩
                        } stu1, stu2 = { "Tom", 12, 18, 'A', 136.5 };
        非初始化赋值   stu1.name = "Tom";       //只能逐个赋值
二.结构体数组（结构体变量为数组的情况）
 1.变量的定义：struct stu{
                       char *name;  //姓名
                          int num;  //学号
                         int age;  //年龄
                         char group;  //所在小组
                          float score;  //成绩
                        }class[5];
 2.初始化赋值：
        struct stu{
              char *name;  //姓名
                int num;  //学号
              int age;  //年龄
              char group;  //所在小组
                float score;  //成绩
        }class[5] = {
                      {"Li ping", 5, 18, 'C', 145.0},
                      {"Zhang ping", 4, 19, 'A', 130.5},
                        {"He fang", 1, 18, 'A', 148.5},
                        {"Cheng ling", 2, 17, 'F', 139.0},
                      {"Wang ming", 3, 17, 'B', 144.5}
                                                        };
 3.结构体数组的使用：class[4].score


 三.结构体指针（指向结构体变量的指针）
 1.定义方式与赋值：struct 结构体名 *变量名=&结构体变量;
   例：
        struct stu{
              char *name;  //姓名
                int num;  //学号
               int age;  //年龄
                char group;  //所在小组
             float score;  //成绩
                    } stu1 = { "Tom", 12, 18, 'A', 136.5 };
                struct stu *pstu = &stu1;  //结构体指针
  注意：1.结构体变量名和数组名不同，数组名在表达式中会被转换为数组指针，而结构体变量名不会，无论在任何表达式中它表示的都是整个集合本身，要想取得结构体变量的地址，必须在前面加&
 2.结构体指针的使用
  (*pointer).memberName或pointer->memberName
   注意：1.  .的优先级高于*，(*pointer)两边的括号不能少。如果去掉括号写作*pointer.memberName，那么就等效于*(pointer.memberName)，这样意义就完全不对了。
        2.  ->是一个新的运算符，习惯称它为“箭头”，有了它，可以通过结构体指针直接取得结构体成员；这也是->在C语言中的唯一用途。
 3.结构体指针常作为函数参数
 结构体变量名代表的是整个集合本身，作为函数参数时传递的整个集合，也就是所有成员，而不是像数组一样被编译器转换成一个指针。如果结构体成员较多，尤其是成员为数组时，传送的时间和空间开销会很大，影响程序的运行效率。
 所以最好的办法就是使用结构体指针，这时由实参传向形参的只是一个地址，非常快速。
   函数定义方式  void average(struct stu *ps, int len)

 四.位域（自定义变量所占的二进制位数）
 1.声明方式：在定义结构体时
   struct bs{
    unsigned int m;
    int n: 4;    //:后面的数字用来限定成员变量占用的位数(几个0/1)
    unsigned char ch: 6;
   }
   注意：位域的宽度不能超过它所依附的数据类型的长度。
        成员变量都是有类型的，这个类型限制了成员变量的最大长度，:后面的数字不能超过这个长度。
        比如 int n: 4;   :后不能超过32
 2.使用：与正常的结构体变量使用方式相同，但会受限于它所定义的长度

 */