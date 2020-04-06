### [Tree Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)

### 题意

给出树的后序遍历和中序遍历，然后输出树的层次遍历。

### 思路

根据后序遍历和中序遍历确定树的结构。然后用队列输出树的层次遍历的结果。

构造方法是参考下面这个博客的。

https://blog.csdn.net/m0_37698652/article/details/79218014

后序遍历的最后一个节点，就是树的**根节点**。然后在中序遍历序列中确定**左右子树**。大致的方法就是找到根节点，然后确定根节点的左右子节点。可以发现，这个过程是**递归**进行的。

定义`build()`函数来构造二叉树。

```cpp
//pl,pr,子树后序遍历序列中的区间
//il,ir,子树中序遍历序列中的区间
//root，这个序列的根节点
int build(int pl, int pr, int il, int ir, node *&root)
{
    //该节点为空
    if(pl > pr)
        return 0;
    //malloc,为这个节点分配空间
    root = (node*)malloc(sizeof(node));
    root->left = root->right = nullptr;
    root->val = post[pr];
    int i;
    for(i = il; i <= ir; i++)
    {
        //在中序遍历序列中找到划分点，确定左右子树
        if(in[i] == post[pr])
            break;
    }
    //左子树遍历区间的长度和右子树遍历区间的长度
    int l = i - il, r = ir - i;
    //递归构造左子树
    build(pl, pl + l - 1, il, i - 1, root->left);
    //递归构造右子树
    build(pl + l, pr - 1, i + 1, ir, root->right);
}
```

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
const int inf = 0x3f3f3f3f;

typedef long long ll;

struct node
{
    node *left = nullptr;
    node *right = nullptr;
    int val = -1;
};
int post[maxn];
int in[maxn];
int build(int pl, int pr, int il, int ir, node *&root)
{
    if(pl > pr)
        return 0;
    root = (node*)malloc(sizeof(node));
    root->left = root->right = nullptr;
    root->val = post[pr];
    int i;
    for(i = il; i <= ir; i++)
    {
        if(in[i] == post[pr])
            break;
    }
    int l = i - il, r = ir - i;
    build(pl, pl + l - 1, il, i - 1, root->left);
    build(pl + l, pr - 1, i + 1, ir, root->right);
}
int main()
{
    freopen("in.txt", "r", stdin);
    node *root = nullptr;
    int n;
    vector<int> ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    build(0, n - 1, 0, n - 1, root);
    queue<node*> que;
    que.push(root);
    while(!que.empty())
    {
        node *t = que.front();
        que.pop();
        ans.push_back(t->val);
        if(t->left != nullptr)
            que.push(t->left);
        if(t->right != nullptr)
            que.push(t->right);
    }
    for(size_t i=0;i<ans.size();i++)
    {
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return 0;
}
```

