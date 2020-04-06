https://www.cnblogs.com/gaochundong/p/union_find_detect_cycle_in_an_undirected_graph.html

### [Deepest Root](https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856)

### 题意

求出树的直径的端点。

### 思路

首先，使用并查集来判断图的连通分量的个数。

第一次，DFS，找到最远点，这些**所有的最远点**都是树的直径的端点，（一个方向的端点）

从最远点中任意选取一个出来，DFS，算出到达的最远点。这些点是树的直径的另外一个端点。

使用SET进行去重，最后排序输出。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int rnk[maxn];
int par[maxn];
bool vis[maxn];
int mx_dp=0;//max deep
void init()
{
    for(int i=0;i<maxn;i++)
        par[i]=i,rnk[i]=0;
}

int find(int x)
{
    if(x==par[x])
        return x;
    else return par[x]=find(par[x]);
}

int unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return 0;
    else
    {
        if(rnk[x]>rnk[y])
        {
            par[y]=x;
        }
        else
        {
            par[x]=y;
            if(rnk[x]==rnk[y])
                rnk[y]++;
        }
    }
}
set<int> ans;
vector<int> tree[maxn];
int dfs(int u,int k)
{
    vis[u]=1;
    rnk[u]=k;
    for(int i:tree[u])
    {
        if(!vis[i])
            dfs(i,k+1);
    }
    mx_dp=max(mx_dp,k);
}
int dfs2(int u,int k)
{
    vis[u]=1;
    if(k==mx_dp)
    {
        ans.insert(u);
    }
    for(int i:tree[u])
        if(!vis[i])
            dfs2(i,k+1);
}
int main()
{
    freopen("in.txt", "r", stdin);
    init();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unite(u,v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(par[i]==i)
            sum++;
    }
    if(sum!=1)
    {
        printf("Error: %d components",sum);
    }
    else
    {
        memset(vis,0,sizeof(vis));
        dfs(1,1);
        for(int i=1;i<=n;i++)
        if(rnk[i]==mx_dp)
        {
            ans.insert(i);
        }
        int s=*ans.begin();
        memset(vis,0,sizeof(vis));
        dfs(s,1);//更新最大直径，方便下面dfs2添加直径的另外一个端点
        memset(vis,0,sizeof(vis));
        dfs2(s,1);
        vector<int> out;
        for(int i:ans)
            out.push_back(i);
        sort(out.begin(),out.end());
        for(int i:out)
            printf("%d\n",i);
    }
    return 0;
}
```



