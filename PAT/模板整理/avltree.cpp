#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
///如果这个指针是空的，那么高度就是0
#define HEIGHT(ROOT) (((node*)ROOT==nullptr)?0:(((node*)ROOT)->height))
struct node
{
    int val;
    node *lchild;
    node *rchild;
    int height;
    node():val(0),height(0),lchild(nullptr),rchild(nullptr){}
};
node *left_left_rotation(node *root)
{
    node *tmproot=root->lchild;
    ///各个节点之间的关系更新遵循从上到下的原则
    root->lchild=tmproot->rchild;
    tmproot->rchild=root;
    root->height=max(HEIGHT(root->lchild),HEIGHT(root->rchild))+1;
    tmproot->height=max(HEIGHT(tmproot->lchild),HEIGHT(tmproot->rchild))+1;
    return tmproot;
}
node *right_right_rotation(node *root)
{
    node *tmproot=root->rchild;
    root->rchild=tmproot->lchild;
    tmproot->lchild=root;
    root->height=max(HEIGHT(root->lchild),HEIGHT(root->rchild))+1;
    tmproot->height=max(HEIGHT(tmproot->lchild),HEIGHT(tmproot->rchild))+1;
    return tmproot;
}
node *left_right_rotation(node *root)
{
    root->lchild=right_right_rotation(root->lchild);
    return left_left_rotation(root);
}
node *right_left_rotaion(node *root)
{
    root->rchild=left_left_rotation(root->rchild);
    return right_right_rotation(root);
}
node *avltree_insert(node *root,int val)
{
    if(root==nullptr)
    {
        root=new node;
        root->val=val;
        ///在这里不返回，到底部的时候要重新计算当前节点的高度
//        return root;
    }
    else if(root->val>val)
    {
        ///左子树要重新赋值
        root->lchild=avltree_insert(root->lchild,val);
        if(HEIGHT(root->lchild)-HEIGHT(root->rchild)==2)
        {
            if(val<=root->lchild->val)
            {
                root=left_left_rotation(root);
            }
            else
            {
                root=left_right_rotation(root);
            }
        }
    }
    else if(root->val<val)
    {
        root->rchild=avltree_insert(root->rchild,val);
        if(HEIGHT(root->rchild)-HEIGHT(root->lchild)==2)
        {
            if(root->rchild->val<val)
                root=right_right_rotation(root);
            else
                root=right_left_rotaion(root);
        }
    }
    ///重新计算节点的高度
    root->height=max(HEIGHT(root->lchild),HEIGHT(root->rchild))+1;
    return root;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    int t;
    node *root=nullptr;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        root=avltree_insert(root,t);
    }
    printf("%d\n",root->val);
    return 0;
}
