### [Wormholes](https://vjudge.net/problem/POJ-3259#author=0)

### 题意

判断负环

### 思路

Bellman-Ford算法判断负环

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int maxn = 4e4 + 1;
const int inf = 0x3f3f3f3f;
int F,N,M,W;
int tot=0;
struct edge
{
	int from;
	int to;
	int cost;
	edge(){}
	edge(int _from,int _to,int _cost):from(_from),to(_to),cost(_cost){}
} way[maxn];
int dist[maxn];
bool bellman_ford()
{
    memset(dist,inf,sizeof(dist));
    dist[1]=0;
    for(int i=1;i<=N-1;i++)
	{
		bool f=true;
		for(int j=0;j<tot;j++)
		{
			int from=way[j].from,to=way[j].to,cost=way[j].cost;
            if(dist[to]>dist[from]+cost)
			{
				dist[to]=dist[from]+cost;
			}
		}
	}
	for(int j=0;j<tot;j++)
	{
		int from=way[j].from,to=way[j].to,cost=way[j].cost;
		if(dist[to]>dist[from]+cost)
			return false;
	}
	return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d",&F);
    while(F--)
	{
		tot=0;
        scanf("%d%d%d",&N,&M,&W);
        int u,v,w;
        for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
            way[tot].from=u;
            way[tot].to=v;
            way[tot++].cost=w;
            way[tot].from=v;
            way[tot].to=u;
            way[tot++].cost=w;
		}
		for(int i=0;i<W;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			way[tot].from=u;
			way[tot].to=v;
			way[tot++].cost=-w;
		}
		if(!bellman_ford())
			puts("YES");
		else
			puts("NO");
	}
    return 0;
}
```

