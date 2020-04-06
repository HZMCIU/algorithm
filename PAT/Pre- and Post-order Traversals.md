### [Pre- and Post-order Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504)

### 题意

根据后序和先序序列来建树，并判断这个二叉树是否唯一。

### 思路

如果二叉树不唯一的话，那么**必然存在一个节点只有左孩子或者只有右孩子。**

先序遍历的序列大致是这样的模式：**根 左子树（左根，左左子树） 右子树（右根，右右子树）**

后序遍历的序列呈现模式：**左子树（左左子树 左根） 右子树（右右子树 右根） 根** 

所以可以根据先序遍历中的**左子树的根**，来将后序遍历序列划分为左子树和右子树。然后使用坐标划分的方法来建立二叉树。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
typedef pair<int,int> P;
typedef long long ll;

int pre[maxn];
int post[maxn];
int n;
struct node
{
    node *lchild;
    node *rchild;
    int val;
    node():lchild(nullptr),rchild(nullptr),val(-1){}
};
bool vis[maxn];
int k;
void build(node *&root,int l1,int r1,int l2,int r2)
{
    if(l1>r1)
        return ;
    root=new node;
    if(l1==r1)
    {
        root->val=pre[l1];
        return ;
    }
    int i;
    for(i=l2;i<=r2;i++)
    {
        if(post[i]==pre[l1+1])
            break;
    }
    root->val=pre[l1];
    build(root->lchild,l1+1,l1+(i-l2)+1,l2,i);
    build(root->rchild,r1-(r2-i)+2,r1,i+1,r2-1);
}
vector<int> ans;
int inorder(node *root)
{
    if(root->lchild)
        inorder(root->lchild);
    ans.push_back(root->val);
    if(root->rchild)
        inorder(root->rchild);
}
bool uni=true;
void check(node *root)
{
    if(!root->lchild&&!root->rchild)
        return ;
    if(!(root->lchild&&root->rchild))
        uni=false;
    if(root->lchild)
        check(root->lchild);
    if(root->rchild)
        check(root->rchild);
}
//如果使用二叉树建树的话，那么就使用划分序列的坐标来递归建树，这是通用的方法
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    node *root=nullptr;
    vis[n-1]=true;
    build(root,0,n-1,0,n-1);
    inorder(root);
    check(root);
    if(uni)
        puts("Yes");
    else
        puts("No");
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    puts("");
    return 0;
}
```

