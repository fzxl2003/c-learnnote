/*
 输入格式
第一行两个整数 N,M  (1≤N,M≤100)，分别代表 f(x) 和 g(x) 的项数。
第二行 2×N 个整数，第 2×i−1 和 2×i 个整数分别代表 f(x) 中第 i 项的系数 ai 和指数 si，ai 和 si 在 int 范围内，且 ai≠0 。
第三行 2×M 个整数，第 2×j−1 和 2×j 个整数分别代表 g(x) 中第 j 项的系数 bj 和指数 tj，bj 和 tj 在 int 范围内，且 bj≠0 。
保证多项式 f(x) 和 g(x) 中的项按指数严格降序给定。

输出格式
输出一行，包含偶数个整数，第 2×k−1 和 2×k 个整数分别代表 f(x)×g(x) 中第 k 项的系数和指数，并以指数严格降序输出，不输出系数为0的项，保证输出结果在long long范围内。

样例输入
3 3
3 2 2 1 1 0
4 2 3 1 2 0
样例输出
12 4 17 3 16 2 7 1 2 0
样例解释
根据题意可知
f(x)=3×x2+2×x+1 g(x)=4×x2+3×x+2
因而
f(x)×g(x)=12×x4+17×x3+16×x2+7×x+2
即输出 12 4 17 3 16 2 7 1 2 0。
 */
#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    long long value;
    long long cishu;
    struct Node *next;
} Node,*PNode;    //创建结构体_Node ,将其命名为Node，他的指针命名为PNode

void print(PNode list){//依次打印链表中的结点
    PNode p;
    p = list;
    while(p!=NULL){ //打印出链表中的全部结点
        if (p->value!=0)
        {printf("%lld %lld ", p->value,p->cishu); }                          //输出区域，可根据结构体内容进行输出
        p = p->next;
    }
}


PNode insert(PNode list,int n,long long vaule,long long cishu)   //n为插入位置（从0开始） vaule为插入数值（可换为其他变量）
{
    PNode temp=list;
    PNode temp2=temp;

    for (int i = 1; i < n; ++i) {
        if (temp==NULL)
        {break;}
        temp2=temp;
        temp=temp->next;
    }
    PNode c=(PNode)malloc(sizeof(Node));
    c->value=vaule;
    c->cishu=cishu;
    if (n==0)
    {
        c->next=list;
        list=c;
        return list;
    }
    if (temp!=NULL)
    {c->next=temp->next;
        temp->next=c;}
    else
    {
        c->next=NULL;
        temp2->next=c;
    }

    return list;
}







PNode pnodefind(PNode list, long long value) {   //value为查找值 ，返回元素指针（从0开始）,未找到返回NULL
    PNode t = list;
    int i = 1;

    while (t) {
        t = t->next;
        if (t==NULL) break;
        if (t->cishu == value) {
            return t;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return NULL;
}
int intfindda(PNode list, long long value) {   //value为查找值 ，返回元素位置（从0开始）,未找到返回-1
    PNode t = list;
    int i = 0;

    while (t) {

        //if (t==NULL) {if }break;
        if (t->cishu < value) {
            return i;
        }
        t = t->next;
        i++;
    }
    //程序执行至此处，表示查找失败
    return i;
}



PNode list_rev(PNode head)                //链表倒换
{
    PNode p;
    if(head==NULL || head->next == NULL)
        return head;
    p=list_rev(head->next );
    head->next->next = head;
    head->next = NULL;
    return p;
}
int main(){
    PNode list = NULL,p;
    int n;int m;
    int a[202];int b[202];
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= 2*n; i+=2) {
        scanf("%d%d",&a[i],&a[i+1]);
    }
    for (int i = 1; i <= 2*m; i+=2) {
        scanf("%d%d",&b[i],&b[i+1]);
    }
    for (int i = 1; i <=2*n ; i+=2) {
        for (int j = 1; j <= 2*m; j+=2) {
            long long xishu=(long long )a[i]*b[j];
            long long cishu=(long long )a[i+1]+b[j+1];
            PNode aa=pnodefind(list,cishu);
            if (aa==NULL)
            {
                int bb= intfindda(list,cishu);
                list=insert(list, bb,xishu,cishu);
                //print(list);
                //printf("\n");
            }
            else
            {
                aa->value+=xishu;
            }
        }
    }
    print(list);

    return 0;
}