## [Layout ](https://vjudge.net/problem/17082/origin)

### 题意

有$N$头牛，每头牛按照编号顺序排列，给出$ML$条关系，每条有三个整数分别为$u,v,w$，表示$v$和$u$的距离不能超过$w$。此外还有$MD$条关系，每条关系有三个整数$u,v,w$表示$u$和$v$的距离不小于$w$。

求解牛$1$和牛$n$的最大距离为多少？如果牛可以任意排列，就输出-2；如果不存在这种排列那么就输出-1。

### 思路

题目中给出的关系可以转化为一系列不等式。

$v-u\leq w$

$v-u\ge w$ $\rightarrow$  $u-w\leq-w$

然后使用最短路算法求解**差分约束**方程的解。

由于记错了SPFA算法，一直WA。**SPFA中如果一个点入队列超过N次那么，就存在负环。**

不存在排列对应于存在负环；可以任意排列，说明约束条件无解，即差分约束方程无解，不存在最短路。

```cpp
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1e3+100;
const int inf=0x3f3f3f3f;
int dist[maxn];
bool vis[maxn];
int cnt[maxn];
int cost[maxn][maxn];
int n,ml,md;
int spfa(int s)
{
    memset(dist,inf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<int> que;
    que.push(s);
    vis[s]=true;
    dist[s]=0;
    cnt[s]+=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=1;i<=n;i++)
        {
            if(cost[u][i]!=inf&&dist[u]+cost[u][i]<dist[i]&&i!=u)
            {
                dist[i]=dist[u]+cost[u][i];
                if(vis[i]==false)
                {
                    que.push(i);
                    vis[i]=true;
                    cnt[i]+=1;
                    if(cnt[i]>n) return -1;
                }
            }
        }
    }
    if(dist[n]==inf)
        return -2;
    else return dist[n];
}
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d%d",&n,&ml,&md))
    {
        memset(cost,inf,sizeof(cost));
        for(int i=0;i<ml;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            cost[u][v]=c;
        }
        for(int i=0;i<md;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            cost[v][u]=-c;
        }
        int ans=spfa(1);
        printf("%d\n",ans);
    }
    return 0;
}
```

