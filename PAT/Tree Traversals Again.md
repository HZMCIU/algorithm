### [Tree Traversals Again](https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024)

### 题意

使用堆栈模拟可以得出树的中序遍历序列。给出堆栈的一系列操作，问如何根据这些操作序列，得出确定的二叉树以及给出相应的后序遍历序列。

### 思路

给出中序和先序遍历序列，或者给出中序和后序遍历序列，然后唯一确定二叉树这样类型的题目再PAT中屡见不鲜。

模拟题目中给出的堆栈操作，可以得出树的中序遍历序列。压栈操作的顺序就是先序的。所以就能够得到中序和先序两个序列，那么就可以唯一确定一个二叉树了。

#### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
typedef long long ll;

struct node
{
    node *left=nullptr;
    node *right=nullptr;
    int val;
    node():left(nullptr),right(nullptr),val(-1){}
};
stack<int> stk;
vector<int> pre;
vector<int> in;
//lp,rp,先序序列中的左右游标
//li,ri,中序序列中的左右游标
void build(node *&root,int lp,int rp,int li,int ri)
{
    if(lp>rp)
        return;
    int i;
    for(i=li;i<=ri;i++)
    {
        if(in[i]==pre[lp])
            break;
    }
    root=new node;
    root->val=pre[lp];
    int llen=i-li,rlen=ri-i;
    build(root->left,lp+1,lp+llen,li,i-1);
    build(root->right,lp+llen+1,rp,i+1,ri);
}
vector<int> ans;
void post(node *&root)
{
    if(root->left!=nullptr)
        post(root->left);
    if(root->right!=nullptr)
        post(root->right);
    ans.push_back(root->val);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        char cmd[10];
        scanf("%s",cmd);
        if(strcmp(cmd,"Push")==0)
        {
            int t;
            scanf("%d",&t);
            stk.push(t);
            pre.push_back(t);
        }
        else
        {
            in.push_back(stk.top());
            stk.pop();
        }
    }
    node *root=nullptr;
    build(root,0,pre.size()-1,0,pre.size()-1);
    post(root);
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
	return 0;
}
```

