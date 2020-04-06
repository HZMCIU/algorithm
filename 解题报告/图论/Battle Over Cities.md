### [Battle Over Cities](https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840)

### 题意

一个城市和其他城市有高速公路相连。如果一个城市被攻陷，那么这个城市和其他城市所连接的道路就会被破坏。问如果一个城市被破坏，那么最少需要修建几条公路才能使得剩下城市相连通。

### 思路

在线求连通图。如果一张图中存在有$n$个联通分量，那么至少需要$n-1$条边才能使得整张图联通。所以解法就是求删去一个点后的图的联通分量。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;
int maze[maxn][maxn];
bool vis[maxn];
int n,m,k;
int dfs(int u)
{
    vis[u]=true;
    for(int v=1;v<=n;v++)
    {
        if(maze[u][v]==1&&vis[v]==0)
            dfs(v);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        maze[u][v]=1;
        maze[v][u]=1;
    }
    for(int i=0;i<k;i++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&u);
        vis[u]=true;
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        printf("%d\n",cnt-1);
    }
    return 0;
}
```

