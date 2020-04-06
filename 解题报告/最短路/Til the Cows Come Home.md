### [Til the Cows Come Home](https://cn.vjudge.net/problem/POJ-2387)

### 题意

求最短路径，注意**重边**。

### 思路

**dijkstra算法**未进行堆优化。

```cpp
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 2000;
const int inf = 0x3f3f3f3f;
struct node
{
    int to;
    int w;
    node(int _to, int _w): to(_to), w(_w) {}
};
int dist[maxn];
bool vis[maxn];
int mp[maxn][maxn];
int N, T;
int dijkstra(int s)
{
    fill(dist, dist + N, inf);
    fill(vis, vis + N, 0);
    for(int i = 1; i <= N; i++)
        dist[i] = inf;
    dist[s] = 0;
    vis[s] = true;
    for(int i = 1; i <= N; i++)
        dist[i] = mp[s][i];
    while(true)
    {
        int v = -1;
        int min_d = inf;
        for(int i = 1; i <= N; i++)
        {
            if(!vis[i] && (v == -1 || dist[i] < dist[v]))
            {
                v = i;
                min_d = dist[i];
            }
        }
        if(v == -1) break;
        vis[v] = true;
        for(int i = 1; i <= N; i++)
        {
            dist[i] = min(dist[i], dist[v] + mp[v][i]);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d", &T, &N))
    {
        memset(mp, inf, sizeof(mp));
        int u, v, w;
        for(int i = 0; i < T; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            if(mp[u][v]!=-1)
                mp[u][v]=min(mp[u][v],w);
            else mp[u][v] = w;
            if(mp[v][u]!=-1)
                mp[v][u]=min(mp[v][u],w);
            else mp[v][u] = w;
        }
        dijkstra(1);
        printf("%d\n", dist[N]);
    }
    return 0;
}
```

