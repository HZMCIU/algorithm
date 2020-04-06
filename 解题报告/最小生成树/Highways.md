### [Highways](https://vjudge.net/problem/POJ-1751)

### 题意

给出n个点，求最小生成树的路径。已经连接了一些点。

### 思路

使用prim算法的时候，选取的点的原则是取出距离已经选取点的集合U最近的点。选取出点的序列不代表路径。

使用`pre[i]`表示生成树中点i的前一个点是`pre[i]`。数组在更新距离的时候更新。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
double cost[maxn][maxn];
struct
{
    int x, y;
} pos[maxn];
struct
{
    int u, v;
} con[maxn];
struct
{
    int u, v;
} edge[maxn];
bool vis[maxn];
int pre[maxn];
double dist[maxn];
int main()
{
   // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &pos[i].x, &pos[i].y);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cost[i][j] = sqrt((pos[i].x - pos[j].x) * (pos[i].x - pos[j].x) + (pos[i].y - pos[j].y) * (pos[i].y - pos[j].y));
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        cost[x][y] = cost[y][x] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[0][i];
        pre[i]=0;
    }
    vis[0] = true;
    int cnt = 0;
    while(true)
    {
        int v = -1;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && (v == -1 || dist[v] > dist[i]))
                v = i;
        }
        if(v == -1)
            break;
        vis[v] = true;
        if(dist[v] != 0)
        {
            edge[cnt].u = pre[v];
            edge[cnt].v = v;
            cnt++;
        }
        for(int i = 0; i < n; i++)
        {
            if(dist[i]>cost[v][i])
            {
                pre[i]=v;
                dist[i]=cost[v][i];
            }
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        printf("%d %d\n", edge[i].u + 1, edge[i].v + 1);
    }
    return 0;
}
```

