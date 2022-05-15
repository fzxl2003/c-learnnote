//链表的创建与初始化
#include <stdio.h>
#include <malloc.h>
typedef struct _Node{
    int value;
    struct _Node *next;
} Node,*PNode;    //创建结构体_Node ,将其命名为Node，他的指针命名为PNode


PNode create(int n){               //创建n个结点的链表,并初始化
    PNode list=NULL;//链表头指针，指向第一个结点
    PNode p, q; //p指向链表的最后一个结点，q为当前新建的结点
    int i;
    for(i = 0; i<n; i++){
        q = (PNode) malloc(sizeof(Node));//新建一个结点
        scanf("%d", &q->value);                          //初始化区域，可根据结构体的内容进行调整
        q->next = NULL;
        if(list == NULL) {//链表为空
            list =  q;//第一个和最后一个结点均为新结点
            p =q;
        }else{
            p->next = q; //当前结点链接到链表
            p = q;  //最后一个结点往后移一个，或：p=q;
        }
    }
    return list; //返回链表的头指针
}
void print(PNode list){//依次打印链表中的结点
    PNode p;
    p = list;
    while(p!=NULL){ //打印出链表中的全部结点
        printf("%d ", p->value);                           //输出区域，可根据结构体内容进行输出
        p = p->next;
    }
}
void clear(PNode list){//清空链表
    PNode p=list;
    while(p!=NULL){
        list = list->next;
        free(p);
        p = list;
    }
}

PNode ninsert(PNode list,int n,int vaule)   //n为插入位置（从0开始） vaule为插入数值（可换为其他变量）
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



PNode pinsert(PNode list,PNode yuansu,int vaule,int sw)   //在list中插入一个元素 vaule为插入数值（可换为其他变量）//返回新建元素的指针,未找到返回NULL //慎用list=pinsert()
{                                                       //sw=1时在yuansu后插入，sw=0时在yuansu前插入
    if (sw==1){
        PNode c=(PNode)malloc(sizeof(Node));
        c->next=yuansu->next;
        yuansu->next=c;
        c->value=vaule;
        return c;}
    if (sw==0)
    {
        if (list==yuansu)
        {
            PNode c=(PNode)malloc(sizeof(Node));
            c->next=list;
            c->value=vaule;
            return c;
        }
        PNode temp=list;
        while (list!=NULL)
        {
            if (list==yuansu)
            {
                PNode c=(PNode)malloc(sizeof(Node));
                temp->next=c;
                c->next=list;
                c->value=vaule;
                return c;
            }
            temp=list;
            list=list->next;
        }
    }
    return NULL;
}
PNode vauleinsert(PNode list,int findvaule,int vaule,int sw)   //在查找到的findvaule后插入元素，数值为vaule（可换为其他变量）//返回链表的头指针
{                                                            //sw=1时在findvaule后插入，sw=0时在findvaule前插入
    PNode list1=list;
    if (sw==1){
        PNode t = list;

        while (t) {
            if (t->value == findvaule) {
                PNode c=(PNode)malloc(sizeof(Node));
                c->next=t->next;
                t->next=c;
                c->value=vaule;
                return list;
            }
            t = t->next;
        }
        //程序执行至此处，表示查找失败
        return list;}
    if (sw==0)
    {
        if (list->value==findvaule)
        {
            PNode c=(PNode)malloc(sizeof(Node));
            c->next=list;
            c->value=vaule;
            return c;
        }
        PNode temp=list;

        while (list!=NULL)
        {
            if (list->value==findvaule)
            {
                PNode c=(PNode)malloc(sizeof(Node));
                temp->next=c;
                c->next=list;
                c->value=vaule;
                return list1;
            }
            temp=list;
            list=list->next;
        }
    }
    return list1;
}



PNode ndelete(PNode list,int n)   //n为删除位置（从0开始） 返回新的list的头地址
{
    PNode temp=list;
    PNode del=NULL;
    if (n==0)
    {
        del=list;
        list=list->next;
        free(del);
        return list;
    }
    for (int i = 1; i < n; ++i) {
        if (temp->next==NULL) return list;
        if (temp->next->next==NULL) break;
        temp=temp->next;

    }
    del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return list;
}


PNode pdelete(PNode list,PNode pp)   //list为链表头位置，pp为删除链表的元素的地址，程序报错说明地址在链表中不存在 返回新的list的头地址
{
    if (list==pp)
    {
        PNode new=list->next;
        free(list);
        return new;
    }
    else
    {
        PNode temp;PNode list1=list;
        while (1) {
            temp=list1;
            list1 = list1->next;
            if (list1 == pp) {
                temp->next = pp->next;
                free(pp);
                break;
            }
        }
    }
    return list;
}
PNode vauledelete(PNode list, int value) {   //value为查找值 ，返回新链表头地址
    PNode t = list;
    PNode temp;
    while (t) {
        if (t->value == value) {
            if (t==list) {PNode new=list->next;
                free(list);
                return new;}
            else
            {
                temp->next=t->next;
                free(t);
                return list;
            }

        }
        temp=t;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return list;
}



int vaulefindn(PNode list, int value) {   //value为查找值 ，返回元素位置（从0开始）,未找到返回-1
    PNode t = list;
    int i = 0;

    while (t) {
        if (t->value == value) {
            return i;
        }
        i++;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

PNode vaulefindp(PNode list, int value) {   //value为查找值 ，返回元素指针（从0开始）,未找到返回NULL
    PNode t = list;
    int i = 0;
    while (t) {
        if (t->value == value) {
            return t;
        }
        i++;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return NULL;
}

PNode nfindp(PNode list,int n)      //根据n（从0开始）找链表元素指针，若n超过元素个数，返回最后一个元素地址，函数出错返回NULL   返回指针
{
    PNode temp;
    if (n==0) return list;
    temp=list;
    for (int i = 1; i <=n ; ++i) {
        list=list->next;
        if (list!=NULL)
        {
            temp=list;
        }
        else return temp;
    }
    return list;
}

PNode change(PNode list, int n,int value) {   //value为查找值,n为要更改的位置（从0开始）,value为更改值
    PNode t = list;
    int i = 1;
    PNode  temp = list;
    temp = temp->next;
    for (i = 0; i <n; i++) {
        temp = temp->next;
        if (temp==NULL) return list;
    }
    temp->value=value;
    return list;
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
    int n;
    scanf("%d", &n);//读入n表示，表示结点的个数
    list = create(n);//创建n个结点的链表
    //list= ninsert(list,3,99);
    //list= ninsert(list,0,99);
    //list= ninsert(list,9999,99);
    //list=pinsert(list,NULL,567,0);
    //list= vauleinsert(list,99,999,1);
    //list= ndelete(list,4);
    //list= vauledelete(list,1) ;
    printf("%p\n", nfindp(list,4)->value);
    printf("%p\n", nfindp(list,3)->value);
    printf("%p\n", nfindp(list,2)->value);
    print(list); //依次打印链表中的结点
    clear(list); //清空链表中的结点
    list = NULL; //将头指针赋值为NULL
    return 0;
}