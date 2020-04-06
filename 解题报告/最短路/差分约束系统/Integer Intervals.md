### [Integer Intervals](https://vjudge.net/problem/POJ-1716#author=634579757)

### 题意

给出$n$个区间，求一个点集$V$，使得每个区间内至少有两个点在点集$V$内。

### 思路

差分约束。

设`s[i]，为区间[0,i-1]在点集V中的个数` 。

区间$[a,b]$内至少有两个点在点集V中，可以转化为一下不等式$s[b+1]-s[a]\ge2$ 。

又有，对于区间中的每个点，都有在点集V内或者不在点集V中的可能。

设区间中的一点$i$，则可用不等式表达，$0\leq s[i+1]-s[i]\le1$。可以转化为大于等于不等式。

$\begin{equation}s[i+1]-s[i]\ge0 \\s[i]-s[i+1]\ge-1\end{equation}$

求出差分约束系统后，使用最短路算法求解出**最长路**即可。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct node
{
    int n;
    int d;
    node() {}
    node(int n_, int d_): n(n_), d(d_) {}
    bool operator < (const node &a) const
    {
        return d < a.d;//每次取出最大值
    }
};
struct node2
{
    int v;
    int w;
    int next;
};
node2 edge[maxn];
int head[maxn];
int tot;
int dist[maxn];
bool vis[maxn];
void addedge(int u, int v, ll w)
{
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int n, m;
void dijkstra(int s)
{
    priority_queue<node> que;
    dist[s] = 0;
    que.push(node(s, 0));
    while(!que.empty())
    {
        node t = que.top();
        que.pop();
        int u = t.n;
        int cost = t.d;
        if(dist[u]>cost) continue;
        vis[u] = true;
        for(int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
                que.push(node(v, dist[v]));
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n))
    {
        memset(dist, -inf, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        int mi = inf, ma = -inf;
        tot = 0;
        for(int i = 0; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v + 1, 2);
            mi = min(u, mi);
            ma = max(ma, v);
        }
        //s[ma+1]-s[ma]表示ma是否在区间内
        for(int i = mi; i <= ma+1; i++)
        {
            addedge(i, i + 1, 0);
            addedge(i + 1, i, -1);
        }
        dijkstra(mi);
        //dist[ma+1]表示区间[0,ma]
        printf("%d\n", dist[ma+1]);
    }
    return 0;
}
```

