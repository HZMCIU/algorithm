### [Silver Cow Party](https://vjudge.net/problem/POJ-3268#author=0)

### 题意

给出一张图，**单向边**，问从点$1-N$到点$X$的最短距离，加上点$X$到点$1-N$的最短距离的**最大值**。

### 思路

两次**Dijkstra**。第一次，点$X$到点$1-N$，典型的单源最短路。第二次，点$1-N$到点$X$，由于给出的是单向边，而且各个点的目的地都是$X$，所以类似于**逆向**的Dijkstra。构造一张反向边的图，然后用Dijkstra。然后求出两次距离之和的最大值即可。

```cpp
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int maxn = 1e3 + 1;
const int inf = 0x3f3f3f3f;
int cost1[maxn][maxn];
int cost2[maxn][maxn];
int dist1[maxn];
int dist2[maxn];
bool vis[maxn];
int N,M,X;
int dijkstra(int cost[maxn][maxn],int dist[maxn])
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;i++)
	{
		dist[i]=cost[X][i];
	}
	dist[X]=0;
	vis[X]=true;
	while(true)
	{
		int v=-1;
		for(int i=1;i<=N;i++)
		{
            if(!vis[i]&&(v==-1||dist[v]>dist[i]))
				v=i;
		}
		if(v==-1) break;
		vis[v]=true;
        for(int i=1;i<=N;i++)
		{
			if(!vis[i])
                dist[i]=min(dist[i],dist[v]+cost[v][i]);
		}
	}
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&M,&X);
    int u,v,w;
    memset(cost1,inf,sizeof(cost1));
    memset(cost2,inf,sizeof(cost2));
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		cost1[u][v]=w;
		cost2[v][u]=w;
	}
	memset(dist1,inf,sizeof(dist1));
    dijkstra(cost1,dist1);
    memset(dist2,inf,sizeof(dist2));
    dijkstra(cost2,dist2);
    int ans=0;
    for(int i=1;i<=N;i++)
	{
		ans=max(ans,dist1[i]+dist2[i]);
	}
	printf("%d\n",ans);
	return 0;
}
```

