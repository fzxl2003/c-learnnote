#include <stdio.h>
//【例 3-10-1】成绩信息
//从键盘上读入一个表示五级评分制成线的整数，输出如下与成绩相
//对应的成绩描述：0分和1分时输出 fail，2分至5分时输出pass，其他得分时给出 illeeal score.
int main3101()
{
    int score;
    scanf("%d",&score);
    switch (score) {
        case 0: case 1: printf("fail");break;
        case 2: case 3: case 4:case 5: printf("pass");break;
        default:printf("what fuck are you writing?");break;    }
    return 0;


}