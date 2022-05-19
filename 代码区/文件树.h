/*
 https://accoding.buaa.edu.cn/contest-ng/index.html#/855/problems
tree是一个常用的命令行工具，该命令用于以树状图列出文件夹的内容。执行tree指令，它会列出指定文件夹下的所有文件，包括子文件夹里的文件。
假定现在有这样一个文件夹：该文件夹内所有可以访问到的文件都是文件夹，且这些文件夹的名称互不相同。
现在请你输出对 该文件夹 或 该文件夹内可访问到的某个文件夹 使用tree命令后的结果，规则如下：
1、若文件夹a中包含文件夹b, c, d，且文件夹b, c, d中不包含任何文件，则对文件夹a使用tree命令后应该按如下样式输出：（注意：从上到下根据文件夹名按字典序升序输出）
a
|-- b
|-- c
`-- d
2、若文件夹b中又包含文件夹e, f，且文件夹e, f中不包含任何文件，则需要在b下方也按照文件夹a的样式输出。注意，若b不是父文件夹a的最后一个子文件夹，则a下方的|符号不能中断。效果如下：
a
|-- b
|   |-- e
|   `-- f
|-- c
`-- d
输入
第一行一个整数t，代表接下来有t行输入；
接下来有t行：每一行是两个由一个空格分隔的字符串A和B，A在前，B在后，代表文件夹B是文件夹A的子文件夹，保证A和B不相同；
接下来多组数据输入，每行数据是一个字符串，代表一个文件夹的名字，保证该文件夹名在前t行中出现过。
保证文件夹的总个数小于1024；文件夹名是 长度小于等于32 且 只包含非空白符的可见字符的 字符串。
输出
首先输出对根文件夹使用tree命令后的输出。（根文件夹即最外层的文件夹）
接下来对于每组数据，输出对这个文件夹使用tree命令后的输出。

输入样例
13
Exercise E2
C_Programming PPT&Notes
code data
C_Programming Exercise
PPT&Notes Lesson2
Competition C1
C_Programming Competition
PPT&Notes Lesson1
Competition C2
E1 code
PPT&Notes Lesson3
Exercise E1
code test
E1
Exercise
code
E2
输出样例
C_Programming
|-- Competition
|   |-- C1
|   `-- C2
|-- Exercise
|   |-- E1
|   |   `-- code
|   |       |-- data
|   |       `-- test
|   `-- E2
`-- PPT&Notes
    |-- Lesson1
    |-- Lesson2
    `-- Lesson3
E1
`-- code
    |-- data
    `-- test
Exercise
|-- E1
|   `-- code
|       |-- data
|       `-- test
`-- E2
code
|-- data
`-- test
E2
样例说明
文件夹C_Programming是最外层文件夹，也就是样例中的所有除了C_Programming之外的文件夹都可以在文件夹C_Programming中访问到。也称C_Programming为根文件夹。
因此首先输出对C_Programming文件夹使用tree命令的结果。之后根据多组数据输入，依次输出对文件夹E1, Exercise, code, E2使用tree命令后的结果。

 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct jdksal{
    struct jdksal* zimulu[1024];
    struct jdksal* root;
    int n;
    char name[33];
}node,*pnode;
pnode rroot[1024];
pnode chazhao(pnode rrroot,char name[])
{
    if (strcmp(rrroot->name,name)==0)
    {
        return rrroot;
    }
    else
    {
        if (rrroot->n==0) return NULL;
        else {
            for (int i = 0; i < rrroot->n; ++i) {
                pnode re=chazhao(rrroot->zimulu[i],name);
                if ((re)!=NULL)
                {
                    return re;
                }
            }
        }
    }
    return NULL;
}
int rrootfind(char name[],int rootn)
{
    for (int i = 0; i < rootn; ++i) {
        if (rroot[i]!=NULL&&strcmp(rroot[i]->name,name)==0)
        {return i;}
    }
    return -1;
}
int cmp(const void *p1, const void *p2)    //按照guess降序，group升序，name字典升序排列
{
    const node *a1=*(node **)p1;
    const node *a2=*(node **)p2;
    return strcmp(a1->name,a2->name);

}
void paixu(pnode root)
{
    if (root->n!=0) {
        qsort(root->zimulu, root->n, sizeof(node*), cmp);
    }
    for (int i = 0; i < root->n; ++i) {
        paixu(root->zimulu[i]);
    }
}
int jingxidu[100];
void print(pnode root,int shendu,int n)
{
    for (int i = 1; i < shendu-1; ++i) {
        if (jingxidu[i]==0)
            printf("|   ");
        else printf("    ");
    }
    if (shendu-1!=0)
    {
        if (n==0)
            printf("`-- ");
        else printf("|-- ");
    }
    printf("%s",root->name);
    printf("\n");
    for (int i = 0; i < root->n-1; ++i) {
        if (n==0) jingxidu[shendu-1]=1;
        print(root->zimulu[i],shendu+1,1);
        jingxidu[shendu-1]=0;
    }
    if (n==0) jingxidu[shendu-1]=1;
    if (root->n>0) print(root->zimulu[root->n-1],shendu+1,0);
    jingxidu[shendu-1]=0;
}
int main()
{
    int t;int rootn=0;char rootname[33],ziname[33];
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%s%s",rootname,ziname);
        if (i==12)
        {int aa=1;}
        if (strcmp(rootname,"E1")==0)
        {int aa=0;}
        int find=0;
        for (int j = 0; j < rootn; ++j) {
            pnode now;
            if (rroot[j]!=NULL){
                if ((now= chazhao(rroot[j],rootname))!=NULL)
                {

                    int das;
                    if ((das=rrootfind(ziname,rootn))==-1)
                    {
                        pnode q = (pnode) malloc(sizeof(node));//新建一个结点

                        q->n=0;strcpy(q->name,ziname);
                        q->root=now;
                        now->zimulu[now->n]=q;
                        now->n++;

                    }
                    else
                    {
                        rroot[das]->root=now;
                        now->zimulu[now->n]=rroot[das];
                        rroot[das]=NULL;now->n++;
                    }
                    find=1;
                    break;
                }}
        }
        if (find==0)
        {
            int das;
            if ((das=rrootfind(ziname,rootn))==-1)
            {
                pnode p = (pnode) malloc(sizeof(node));//新建一个结点
                p->n=0;strcpy(p->name,ziname);
                pnode q = (pnode) malloc(sizeof(node));//新建一个结点
                q->n=0;strcpy(q->name,rootname);
                q->root=NULL;p->root=q;
                q->n=1;q->zimulu[0]=p;
                rroot[rootn]=q;rootn++;

            }
            else
            {
                pnode q = (pnode) malloc(sizeof(node));//新建一个结点
                q->n=0;strcpy(q->name,rootname);
                q->root=NULL;
                q->n=1;q->zimulu[0]= rroot[das];
                rroot[das]->root=q;
                rroot[das]=NULL;rroot[rootn]=q;rootn++;
            }






        }

    }
    pnode realroot=NULL;
    for (int i = 0; i < rootn; ++i) {
        if (rroot[i]!=NULL)
        {
            realroot=rroot[i];
        }
    }
    paixu(realroot);
    //printf("\n");
    print(realroot,1,0);
    char nownow[35];
    while (scanf("%s",nownow)!=EOF)
    {
        pnode newroot=chazhao(realroot,nownow);
        if (newroot!=NULL)
        {
            print(newroot,1,0);
        }
    }
    return 0;


}
