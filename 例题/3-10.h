#include <stdio.h>
//【例 3-10】成绩信息
//从键盘上读入一个表示五级评分制成绩的整数，输出如下与成绩相对应的成绩描述
//0-absent ; 1-fail; 2-poor; 3-average ; 4-excellento 对其他整数，输出illegal score
int main310()
{
    int score;
    scanf("%d",&score);
    switch (score) {
        case 0: printf("absent");break;
        case 1: printf("fail");break;
        case 2: printf("poor");break;
        case 3: printf("average");break;
        case 4: printf("good");break;
        case 5: printf("excellent");break;
        default:printf("what fuck are you writing?");break;
    }
    return 0;

}