###[Extended Traffic](https://cn.vjudge.net/problem/LightOJ-1074)

### 题意

一张图上有$n$个节点，每个节点上有一个值，连接每条边的是**单向边**。假设出发节点是u,终止节点是v,则连接$(u,v)$的边的权值为$(w(v)-w(u))^3$ 。（$w(i)$,表示第i个节点上的值）求从起始节点1到目标节点的最短距离。如果目标不可达，距离小于3，那么输出`?`，否则输出最短距离。

### 思路

由于边的权值为$(w(v)-w(u))^3$，可能存在负数，即，有可能存在**负环**。 使用SPFA+DFS来判断负环。

1. SPFA算法的主要改进在于，在Bellman-Ford算法上增加了一个**FIFO队列**，使用类似于广度有限搜索的思想来进行松弛操作。如果一个点入队超过了n次，那么久存在负环。
2. 使用DFS来进行优化，如果一个点是负环上的一个点，那么这个点往后的所有路径都会被影响，所有**直接**DFS来标记会被影响的节点，因为DFS是直接走向下一个节点的。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
    int v;
    int w;
    int next;
    node(){}
    node(int v_,int w_):v(v_),w(w_){}
};
int head[maxn];
int dist[maxn];
node edge[maxn];
int cnt[maxn];
bool vis[maxn];
int cir[maxn];
int wei[maxn];
int tot;
int n,m;
void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u)
{
    cir[u]=true;
    for(int i=head[u];~i;i=edge[i].next)
    {
        if(!cir[edge[i].v])
            dfs(edge[i].v);
    }
}
void spfa(int s)
{
    queue<int> que;
    memset(dist,inf,sizeof(dist));
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(cir,0,sizeof(cir));
    que.push(s);
    vis[s]=true;
    dist[s]=0;
    cnt[s]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        if(cir[u]) continue;
        for(int i=head[u];~i;i=edge[i].next)
        {
            if(dist[edge[i].v]>dist[u]+edge[i].w)
            {
                dist[edge[i].v]=dist[u]+edge[i].w;
                if(!vis[edge[i].v])
                {
                    que.push(edge[i].v);
                    cnt[edge[i].v]+=1;
                    if(cnt[edge[i].v]>n)
                        dfs(edge[i].v);
                }
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&wei[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d",&u,&v);
            addedge(u,v,(wei[v]-wei[u])*(wei[v]-wei[u])*(wei[v]-wei[u]));
        }
        spfa(1);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++iCase);
        for(int i=0;i<q;i++)
        {
            int des;
            scanf("%d",&des);
            if(dist[des]==inf||cir[des]||dist[des]<3)
                puts("?");
            else
                printf("%d\n",dist[des]);
        }
    }
    return 0;
}
```

