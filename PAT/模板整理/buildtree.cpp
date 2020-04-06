#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;

struct node
{
    node *lchild;
    node *rchild;
    int val;
    node():lchild(nullptr),rchild(nullptr),val(0){}
};
int post[maxn];
int in[maxn];
/**
根据后序序列和先序序列来建树
数组下标从i到ir，一共有(ir-i)+1个元素
*/
void build(node *&root,int pl,int pr,int il,int ir)
{
    if(pl>pr)
        return ;
    if(pl==pr)
    {
        root=new node;
        root->val=post[pr];
        return ;
    }
    int i;
    for(i=il;i<=ir;i++)
        if(post[pr]==in[i])
        break;
    root=new node;
    root->val=post[pr];
    build(root->lchild,pl,pl+(i-il)-1,il,i-1);
    build(root->rchild,pr-(ir-i),pr-1,i+1,ir);
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    node *root=nullptr;
    build(root,0,n-1,0,n-1);
    queue<node*> que;
    vector<int> ans;
    que.push(root);
    while(!que.empty())
    {
        node *t=que.front();
        que.pop();
        ans.push_back(t->val);
        if(t->lchild)
            que.push(t->lchild);
        if(t->rchild)
            que.push(t->rchild);
    }
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    return 0;
}
