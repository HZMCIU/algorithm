### [Invitation Cards](https://vjudge.net/problem/POJ-1511)

### 题意

求从1到[2-n]各个点的最短距离以及[2-n]各个点到1的最短距离之和。

### 思路

建两张互补的图。使用Dijkstra算法加上堆优化。

存图使用链式向前星，用vector存图会超时。

会爆`int`

水题。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int n;
    ll d;
    node() {}
    node(int n_, int d_): n(n_),d(d_) {}
    bool operator < (const node &a) const
    {
        return d>a.d;
    }
};
struct node2
{
    int v;
    ll w;
    int next;
};
node2 edge1[maxn];
node2 edge2[maxn];
int head1[maxn];
int head2[maxn];
int tot1;
int tot2;
ll dist[maxn];
void addedge(int u,int v,ll w)
{
    edge1[tot1].v=v;
    edge1[tot1].w=w;
    edge1[tot1].next=head1[u];
    head1[u]=tot1;
    tot1++;
    edge2[tot2].v=u;
    edge2[tot2].w=w;
    edge2[tot2].next=head2[v];
    head2[v]=tot2;
    tot2++;
}
int n,m;
ll dijkstra(int w)
{
    priority_queue<node> que;
    memset(dist,inf,sizeof(dist));
    dist[1]=0;
    que.push(node(1,0));
    while(!que.empty())
    {
        node t=que.top();
        que.pop();
        int u=t.n;
        if(w==1)
        {
            for(int i=head1[u];~i;i=edge1[i].next)
            {
                int v=edge1[i].v;
                ll w=edge1[i].w;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    que.push(node(v,dist[v]));
                }
            }
        }
        else if(w==2)
        {
            for(int i=head2[u];~i;i=edge2[i].next)
            {
                int v=edge2[i].v;
                ll w=edge2[i].w;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    que.push(node(v,dist[v]));
                }
            }
        }
    }
    ll ret=0;
    for(int i=1;i<=n;i++)
        ret+=dist[i];
//    for(int i=1;i<=n;i++)
//        printf("%I64d ",dist[i]);
//    puts("");
    return ret;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        tot1=tot2=0;
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        ll ans=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            ll d;
            scanf("%d%d%I64d",&u,&v,&d);
            addedge(u,v,d);
        }
        ans+=dijkstra(1);
        ans+=dijkstra(2);
        printf("%I64d\n",ans);
    }
    return 0;
}
```

