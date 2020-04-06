### [Constructing Roads](https://vjudge.net/problem/POJ-2421)

### 题意

给出一张邻接矩阵。然后再给出q个条件，表示q个点之间的距离为0。求最小生成树。

### 思路

稠密图，适合Prim算法

Prime算法描述

1. 定义两个集合，已经取出的点U，未取出的点V
2. 取出距离已经取出的点最近的点v，将距离加到答案中
3. 更新V，U；并且更新V距离各个点U的最小值

类似Dijkstra

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
int cost[maxn][maxn];
int dist[maxn];
bool vis[maxn];
int main()
{
    freopen("in.txt", "r", stdin);
    memset(dist,inf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    memset(cost,inf,sizeof(cost));

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cost[a][b]=0;
        cost[b][a]=0;
    }
    for(int i=1;i<=n;i++)
        dist[i]=min(dist[i],cost[1][i]);
    vis[1]=true;
    int ans=0;
    while(true)
    {
        int v=-1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&(v==-1||dist[v]>dist[i]))
                v=i;
        }
        if(v==-1)
            break;
        vis[v]=true;
        ans+=dist[v];
        for(int i=1;i<=n;i++)
            dist[i]=min(dist[i],cost[v][i]);
    }
    printf("%d\n",ans);
    return 0;
}

```

