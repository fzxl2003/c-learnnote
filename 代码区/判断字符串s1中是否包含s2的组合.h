/*
 题目描述
LJF的舍友早已母胎solo整整21年，要是再不脱单就会变成魔法少女，所以他希望LJF帮他进行匹配，匹配规则如下：
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，输出65472 ；否则，返回 Single Forever! 。
换句话说，s1 的排列之一是 s2 的 子串 。
s1的排列即对s1里的元素进行重新排序。

输入
第一行为字符串s1。
第二行为字符串s2。
s1和s2的长度均不超过105，且仅包含小写字母。

输出
一行。
判断 s2 是否包含 s1 的排列。如果是，输出65472 ；否则，返回 Single Forever! 。

输入样例
acb
abcabc
输出样例
65472
 */
/*
 Author: 潘宇恒
 Result: AC	Submission_id: 4404308
 Created at: Mon May 02 2022 18:10:41 GMT+0800 (China Standard Time)
 Problem_id: 5729	Time: 8	Memory: 1624
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void s1t(char s1[],int sum[],int n)
{
    for (int i = 0; i < n; ++i) {
        sum[s1[i]-'a']++;
    }
}

int main() {
    char s1[100003];char s2[100003];
    int s1tezheng[26]={0};
    int s2tezheng[26]={0};
    gets(s1);gets(s2);
    int len1= strlen(s1);
    int len2= strlen(s2);
    s1t(s1,s1tezheng, len1);
    s1t(s2,s2tezheng,len1);
    int sw=1;
    for (int j = 0; j < 26; ++j) {
        if (s1tezheng[j]!=s2tezheng[j])
        {sw=0;break;}
    }
    if (sw==1) {printf("65472");return 0;}
    for (int i = len1; i <len2 ; ++i) {
        s2tezheng[s2[i-len1]-'a']--;
        s2tezheng[s2[i]-'a']++;
        sw=1;
        for (int j = 0; j < 26; ++j) {
            if (s1tezheng[j]!=s2tezheng[j])
            {sw=0;break;}
        }
        if (sw==1) {printf("65472");return 0;}
    }
    printf("Single Forever!");
}