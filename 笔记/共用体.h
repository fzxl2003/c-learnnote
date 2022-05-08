/*http://c.biancheng.net/cpp/html/2932.html
 共用体（灵活更改变量的类型）
 结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；
 而共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员。
  结构体占用的内存大于等于所有成员占用的内存的总和（成员之间可能会存在缝隙），
  共用体占用的内存等于最长的成员占用的内存。
  共用体使用了内存覆盖技术，同一时刻只能保存一个成员的值，如果对新的成员赋值，就会把原来成员的值覆盖掉。

一.定义、赋值、使用 (除了关键词不同以外，其他与结构体基本相同)
   1.共用体定义：union 共用体名{
                   成员列表
                    }共用体变量名;
        例
        union data{
              int n;
             char ch;
             double f;} a,b,c,d;
     定义结构体时如果不再定义新的变量，也可以将共用体的名字省略：
    2.共用体变量的定义
           union data a, b, c;
           或按一1.那样定义共用体时定义共用体变量
    3.使用：与结构体使用方法相同，但效果不同，不同点见上
 二.共用体应用场景
 共用体的应用
共用体在一般的编程中应用较少，在单片机中应用较多。
 对于 PC 机，经常使用到的一个实例是： 现有一张关于学生信息和教师信息的表格。
 学生信息包括姓名、编号、性别、职业、分数，教师的信息包括姓名、编号、性别、职业、教学科目。
 请看下面的表格：
Name            Num      Sex     Profession      Score / Course
HanXiaoXiao     501      f        s              89.5
YanWeiMin       1011     m       t               math
LiuZhenTao      109      f          t            English
ZhaoFeiYan      982      m          s            95.0

f 和 m 分别表示女性和男性，s 表示学生，t 表示教师。可以看出，学生和教师所包含的数据是不同的。现在要求把这些信息放在同一个表格中，并设计程序输入人员信息然后输出。
如果把每个人的信息都看作一个结构体变量的话，那么教师和学生的前 4 个成员变量是一样的，第 5 个成员变量可能是 score 或者 course。当第 4 个成员变量的值是 s 的时候，第 5 个成员变量就是 score；当第 4 个成员变量的值是 t 的时候，第 5 个成员变量就是 course。

#include <stdio.h>
#include <stdlib.h>
#define TOTAL 4  //人员总数
struct{
    char name[20];
    int num;
    char sex;
    char profession;
    union{
        float score;
        char course[20];
    } sc;
} bodys[TOTAL];
int main(){
    int i;
    //输入人员信息
    for(i=0; i<TOTAL; i++){
        printf("Input info: ");
        scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));
        if(bodys[i].profession == 's'){  //如果是学生
            scanf("%f", &bodys[i].sc.score);
        }else{  //如果是老师
            scanf("%s", bodys[i].sc.course);
        }
        fflush(stdin);
    }
    //输出人员信息
    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    for(i=0; i<TOTAL; i++){
        if(bodys[i].profession == 's'){  //如果是学生
            printf("%s\t%d\t%c\t%c\t\t%f\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.score);
        }else{  //如果是老师
            printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course);
        }
    }
    return 0;
}
运行结果：
Input info: HanXiaoXiao 501 f s 89.5↙
Input info: YanWeiMin 1011 m t math↙
Input info: LiuZhenTao 109 f t English↙
Input info: ZhaoFeiYan 982 m s 95.0↙

Name            Num     Sex     Profession      Score / Course
HanXiaoXiao     501     f       s               89.500000
YanWeiMin       1011    m       t               math
LiuZhenTao      109     f       t               English
ZhaoFeiYan      982     m       s               95.000000
 */