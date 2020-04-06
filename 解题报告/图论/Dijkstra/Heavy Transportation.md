### [Heavy Transportation](https://vjudge.net/problem/POJ-1797)

### 题意

求两个点之间**最短边**的**最大值**。

### 思路

使用类似于**Dijkstra**的贪心思想，定义`maxw[i]`从源点到点$i$的最短边的最大距离。

更新的方式为`maxw[i]=max(maxw[i],min(maxw[v],cost[v][i]))`

然后每次贪心选取最大的值即可。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
bool vis[maxn];
int maxw[maxn];
int cost[maxn][maxn];
int main(int argc, char **argv)
{
    //freopen("in.txt","r",stdin);
    int n, m;
    int cs = 0;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        memset(maxw, -inf, sizeof(maxw));
        memset(cost, -inf, sizeof(cost));
        memset(vis, 0, sizeof(vis));
        int u, v, w;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            cost[v][u] = cost[u][v] = w;
        }
        vis[1] = true;
        for(int i = 1; i <= n; i++)
            maxw[i] = cost[1][i];
        maxw[1] = 0;
        while(true)
        {
            int v = -1;
            for(int i = 1; i <= n; i++)
            {
                if(!vis[i] && (v == -1 || maxw[i] > maxw[v]))
                    v = i;
            }
            if(v == -1)
                break;
            vis[v] = true;
            for(int i = 1; i <= n; i++)
            {
                if(!vis[i])
                    maxw[i] = max(maxw[i], min(maxw[v], cost[v][i]));
            }
        }
        printf("Scenario #%d:\n", ++cs);
        printf("%d\n\n", maxw[n]);
    }
    return 0;
}
```

