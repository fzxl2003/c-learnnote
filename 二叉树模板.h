

#include<stdio.h>
#include <malloc.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
    struct TreeNode * parent;
}TreeNode,*pTreeNode;

void pre_order(TreeNode * Node)//前序遍历递归算法
{
    if(Node == NULL)
        return;
    printf("%d ", Node->data);//显示节点数据，可以更改为其他操作。在前面
    pre_order(Node->left);
    pre_order(Node->right);
}
void middle_order(TreeNode *Node)//中序遍历递归算法
{
    if(Node == NULL)
        return;
    middle_order(Node->left);
    printf("%d ", Node->data);//在中间
    middle_order(Node->right);
}
void post_order(TreeNode *Node)//后序遍历递归算法
{
    if(Node == NULL)
        return;
    post_order(Node->left);
    post_order(Node->right);
    printf("%d ", Node->data);//在最后
}
pTreeNode cengxucreat(int n)     //层序建立二叉树
{pTreeNode duilie[2000];
    int s=0,e=0;
    int pow=1;
    pTreeNode q = (TreeNode*) malloc(sizeof(TreeNode));
    duilie[0]=q;
    q->parent=0;
    //q->right=NULL;q->left=NULL;
    for (int i = 1; i <=n ; ++i) {
        //int begin=0;
        int ee=e;//pTreeNode left=NULL;
        for ( ; s <=ee ; ++s) {
            pTreeNode a = (TreeNode*) malloc(sizeof(TreeNode));
            pTreeNode b = (TreeNode*) malloc(sizeof(TreeNode));
            scanf("%d",&duilie[s]->data);
            if (i==n){duilie[s]->left=NULL;
                duilie[s]->right=NULL;}
            else{
                duilie[s]->left=a;
                duilie[s]->right=b;}
            a->parent=duilie[s];
            b->parent=duilie[s];

            duilie[e+1]=a;
            duilie[e+2]=b;
            e+=2;
        }
    }
    return q;

}
int main(){
    pTreeNode q=cengxucreat(2);
    pre_order(q);
    printf("\n");
    middle_order(q);
    printf("\n");
    post_order(q);



    return 0;
}