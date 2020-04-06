###[Intervals](https://vjudge.net/problem/POJ-1201#author=634579757)

### 题意

和[Integer Intervals](https://vjudge.net/problem/POJ-1716#author=634579757) 类似

### 思路

差分约束。Dijkstra堆优化。

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <float.h>
#include <queue>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
struct node2
{
    int v;
    int w;
    int next;
};
struct node
{
    int n;
    int d;
    node(int n_,int d_):n(n_),d(d_){}
    node(){}
    bool operator <(const node &a) const
    {
        return d>a.d;
    }
};
int head[maxn];
node2 edge[maxn];
int tot;
int dist[maxn];
int n;
void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dijkstra(int s)
{
    memset(dist,-inf,sizeof(dist));
    dist[s]=0;
    priority_queue<node> que;
    que.push(node(s,0));
    while(!que.empty())
    {
        node t=que.top();
        que.pop();
        if(dist[t.n]>t.d) continue;
        int u=t.n;
        for(int i=head[t.n];~i;i=edge[i].next)
        {
            int v,w;
            v=edge[i].v;
            w=edge[i].w;
            if(dist[v]<dist[u]+w)
            {
                dist[v]=dist[u]+w;
                que.push(node(v,dist[v]));
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    memset(head,-1,sizeof(head));
    int n;
    scanf("%d",&n);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b+1,c);
        mx=max(mx,a);
        mx=max(mx,b);
    }
    for(int i=0;i<=mx;i++)
    {
        addedge(i,i+1,0);
        addedge(i+1,i,-1);
    }
    dijkstra(0);
    printf("%d\n",dist[mx+1]);
    return 0;
}
```

