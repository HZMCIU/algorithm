### [Complete Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232)

### 题意

考察完全二叉树的概念，数据结构还是要好好复习呀

### 思路

层序遍历

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e3+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,string> P;
struct node
{
    int lchild=-1;
    int rchild=-1;
    node():lchild(-1),rchild(-1){}
};
node tree[maxn];
int par[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    char a[5],b[5];
    scanf("%d",&n);
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++)
    {
        scanf("%s %s",a,b);
        if(a[0]!='-')
        {
            sscanf(a,"%d",&tree[i].lchild);
            par[tree[i].lchild]=i;
        }
        if(b[0]!='-')
        {
            sscanf(b,"%d",&tree[i].rchild);
            par[tree[i].rchild]=i;
        }
    }
    int root=0;
    while(par[root]!=-1)
        root=par[root];
    queue<int> que;
    que.push(root);
    int cnt=1;
    int last;
    vector<int> seq;
    seq.push_back(root);
    while(!que.empty())
    {
        int t=que.front();
        que.pop();
        if(tree[t].lchild!=-1)
        {
            que.push(tree[t].lchild),cnt++;
            seq.push_back(tree[t].lchild);
        }
        else break;
        if(tree[t].rchild!=-1)
        {
            que.push(tree[t].rchild),cnt++;
            seq.push_back(tree[t].rchild);
        }
        else break;
    }
    if(cnt<n)
        printf("NO %d\n",root);
    else
        printf("YES %d\n",seq[seq.size()-1]);
    return 0;
}
```

