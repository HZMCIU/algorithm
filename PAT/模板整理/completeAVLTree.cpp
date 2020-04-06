#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,string> P;

#define HEIGHT(ROOT) ((ROOT==nullptr)?0:(((node*)ROOT)->height))
struct node
{
    node *lchild;
    node *rchild;
    int val;
    int height;
    node():height(0),val(0),lchild(nullptr),rchild(nullptr){}
};
node *left_left_rotation(node *root)
{
    node *tmproot=root->lchild;
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
    tmproot->height=max(HEIGHT(tmproot->rchild),HEIGHT(tmproot->lchild))+1;
    return tmproot;
}
node *left_right_rotation(node *root)
{
    root->lchild=right_right_rotation(root->lchild);
    return left_left_rotation(root);
}
node *right_left_rotation(node *root)
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
    }
    else if(val<=root->val)
    {
        root->lchild=avltree_insert(root->lchild,val);
        if(HEIGHT(root->lchild)-HEIGHT(root->rchild)==2)
        {
            if(val>root->lchild->val)
                root=left_right_rotation(root);
            else
                root=left_left_rotation(root);
        }
    }
    else
    {
        root->rchild=avltree_insert(root->rchild,val);
        if(HEIGHT(root->rchild)-HEIGHT(root->lchild)==2)
        {
            if(val>root->rchild->val)
                root=right_right_rotation(root);
            else
                root=right_left_rotation(root);
        }
    }
    root->height=max(HEIGHT(root->lchild),HEIGHT(root->rchild))+1;
    return root;
}
int avltree_minimum(node *root)
{
    while(root->lchild!=nullptr)
        root=root->lchild;
    return root->val;
}
int avltree_maximum(node *root)
{
    while(root->rchild!=nullptr)
        root=root->rchild;
    return root->val;
}
node *avltree_delete(node *root,int val)
{
    if(val<root->val)
    {
        root->lchild=avltree_delete(root->lchild,val);
        if(HEIGHT(root->rchild)-HEIGHT(root->lchild)==2)
        {
            node *child=root->rchild;
            if(HEIGHT(child->rchild)>HEIGHT(child->lchild))
                root=right_right_rotation(root);
            else
                root=right_left_rotation(root);
        }
    }
    else if(val>root->val)
    {
        root->rchild=avltree_delete(root->rchild,val);
        if(HEIGHT(root->lchild)-HEIGHT(root->rchild)==2)
        {
            node *child=root->lchild;
            if(HEIGHT(child->lchild)>HEIGHT(child->rchild))
                root=left_left_rotation(root);
            else
                root=left_right_rotation(root);
        }
    }
    else
    {
        if((root->lchild)&&(root->rchild))
        {
            if(HEIGHT(root->lchild)>HEIGHT(root->rchild))
            {
                int mx=avltree_maximum(root->lchild);
                root->val=mx;
                root->lchild=avltree_delete(root->lchild,mx);
            }
            else
            {
                int mi=avltree_minimum(root->rchild);
                root->val=mi;
                root->rchild=avltree_delete(root->rchild,mi);
            }
        }
        else
        {
            node *tmp=root;
            root=root->lchild?root->lchild:root->rchild;
            delete tmp;
        }
    }
    return root;
}
