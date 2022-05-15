

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct djaksljdsakl{
    char name[32];
    struct djaksljdsakl* left;
    struct djaksljdsakl* right;
}inf,*pinf;
pinf rightdelete(pinf list,int n)   //从list向右出发，删除第n个，返回下一个的指针
{
    for (int i = 0; i < n; ++i) {
        list=list->right;
    }
    list->left->right=list->right;
    list->right->left=list->left;
    pinf rr=list->right;
    //printf("%s\n",list->name);
    free(list);

    return rr;
}

pinf leftdelete(pinf list,int n)    //从list向左出发，删除第n个，返回下一个的指针
{
    for (int i = 0; i < n; ++i) {
        list=list->left;
    }
    list->left->right=list->right;
    list->right->left=list->left;
    pinf rr=list->left;
    printf("%s\n",list->name);
    free(list);
    return rr;
}

pinf rightdingwei(pinf list,int n)   //从list向右出发，返回第n个指针
{
    for (int i = 0; i < n; ++i) {
        list=list->right;
    }
    //printf("%s\n",list->name);
    return list;
}


pinf rightprint(pinf list,int n)   //从list向右出发，打印前n个元素，返回第n个指针
{
    for (int i = 0; i < n; ++i) {
        printf("%s ",list->name);
        list=list->right;
    }
    return list;
}

pinf vaulerightfind(pinf list,int n,char *vaule)   //从list向右出发,找到第一个元素为vaule的元素的指针，并返回 //n用来限制循环次数，避免死循环，也可用来限制查找范围
{                                                     //在n的范围内未找到，返回起点的地址
    pinf list1=list;
    for (int i = 0; i < n; ++i) {
        if (strcmp(vaule,list->name)==0)
        {
            return list;
        }
        list=list->right;
    }
    return list1;
}

pinf vauleleftfind(pinf list,int n,char *vaule)   //从list向左出发,找到第一个元素为vaule的元素的指针，并返回 //n用来限制循环次数，避免死循环，也可用来限制查找范围
{                                                     //在n的范围内未找到，返回起点的地址
    pinf list1=list;
    for (int i = 0; i < n; ++i) {
        if (strcmp(vaule,list->name)==0)
        {
            return list;
        }
        list=list->left;
    }
    return list1;
}
pinf leftprint(pinf list,int n)   //从list向左出发，打印前n个元素，返回第n个指针
{
    for (int i = 0; i < n; ++i) {
        printf("%s ",list->name);
        list=list->left;
    }
    return list;
}


pinf leftdingwei(pinf list,int n)      //从list向左出发，返回第n个指针
{
    for (int i = 0; i < n; ++i) {
        list=list->left;
    }
    printf("%s\n",list->name);
    return list;
}

pinf rightcreate(int n)     //向右建立双向循环链表，返回第一个值的地址
{
    pinf q = (pinf) malloc(sizeof(inf));
    q->left=NULL;
    pinf begin=q;
    for (int i = 0; i <n-1 ; ++i) {
        scanf("%s",q->name);
        pinf p=(pinf) malloc(sizeof (inf));
        q->right=p;
        p->left=q;
        q=p;
    }
    scanf("%s",q->name);
    q->right=begin;
    begin->left=q;
    return begin;
}
int main()
{
    //inf stu[10004];
    int now;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    pinf begin=rightcreate(n);
    begin= leftdingwei(begin,m-1);
    for (int i = 1; i <=n-1 ; ++i) {
        begin= leftdelete(begin,k-1);
        leftprint(begin,n-i);
        printf("\n");
        rightprint(begin,n-i);
        printf("\n");
    }
    printf("%s",begin->name);

}