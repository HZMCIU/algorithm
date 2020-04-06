### [Is It a Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856)

### 题意

给出先序遍历序列，问这个序列是否为二叉查找树（或其镜像）的先序遍历序列。如果是，输出后序遍历序列

### 思路

根据给出的序列，按照二叉树节点插入的规则建树。然后对建好的树，进行先序遍历，如果两个序列一致，那么该序列就是二叉查找树的现需遍历序列。

二叉查找树实现插入操作的时候，如果一个节点比当前节点的值大，那么插入到右子树，反之插入左子树

**先跟遍历**的序列，结合二叉搜索树的性质，那么就能够唯一确定出二叉搜索树的形状。对这个二叉搜索树进行先序遍历，比较和题目中给出的序列是否一致。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int arr[maxn];
int cnt;
int n;
struct node
{
    node *left=nullptr;
    node *right=nullptr;
    int val;
};
int insert(node *&root,int val,int op)
{
    if(root==nullptr)
    {
        root=(node*)malloc(sizeof(node));
        root->left=root->right=nullptr;
        root->val=val;
        return 0;
    }
    if(op==0)
    {
        if(val>=root->val)
            return insert(root->right,val,op);
        else
            return insert(root->left,val,op);
    }
    else if(op==1)
    {
        if(val<root->val)
            return insert(root->right,val,op);
        else
            return insert(root->left,val,op);
    }
}
vector<int> ans;
vector<int> p;
int post(node *&root)
{
    if(root->left!=nullptr)
        post(root->left);
    if(root->right!=nullptr)
        post(root->right);
    ans.push_back(root->val);
    return 0;
}
int pre(node *&root)
{
    p.push_back(root->val);
    if(root->left!=nullptr)
        pre(root->left);
    if(root->right!=nullptr)
        pre(root->right);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    node *root=nullptr;
    int op=arr[0]<arr[1];
    for(int i=0;i<n;i++)
        insert(root,arr[i],op);
    pre(root);
    int f=1;
    for(int i=0;i<n;i++)
        if(arr[i]!=p[i])
        f=0;
    if(f)
    {
        puts("YES");
        post(root);
        printf("%d",ans[0]);
        for(int i=1;i<n;i++)
            printf(" %d",ans[i]);
    }
    else
    {
        puts("NO");
    }
	return 0;
}
```

