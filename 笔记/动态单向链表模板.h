





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

PNode insert(PNode list,int n,int vaule)   //n为插入位置（从0开始） vaule为插入数值（可换为其他变量）
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




PNode delete(PNode list,int n)   //n为删除位置（从0开始）
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
        temp=temp->next;
    }
    del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return list;
}

int intfind(PNode list, int value) {   //value为查找值 ，返回元素位置（从0开始）,未找到返回-1
    PNode t = list;
    int i = 1;

    while (t) {
        t = t->next;
        if (t->value == value) {
            return i;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

PNode pnodefind(PNode list, int value) {   //value为查找值 ，返回元素指针（从0开始）,未找到返回NULL
    PNode t = list;
    int i = 1;

    while (t) {
        t = t->next;
        if (t->value == value) {
            return t;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return NULL;
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
    //printf("%d %p\n", intfind(list,3), pnodefind(list,3));
    //printf("%d\n", pnodefind(list,3)->value);
    list=change(list,999,999);
    list=insert(list, 999,99);
    list=delete(list, 0);
    list=list_rev(list);
    print(list); //依次打印链表中的结点
    clear(list); //清空链表中的结点
    list = NULL; //将头指针赋值为NULL
    return 0;
}