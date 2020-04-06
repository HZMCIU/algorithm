##[Arpa's weak amphitheater and Mehrdad's valuable Hoses](https://cn.vjudge.net/problem/CodeForces-742D)

#### 思路

首先确定那些人在同一个小组，显然并查集做，然后把同一个根节点上的存在一个容器中。

按上面的要求对于每个容器中的人要么全部都取，要么只取一个，要么不取。 做01背包处理即

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

const int maxn=100000;
int par[maxn];
int rnk[maxn];

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;rnk[i]=0;
	}
}
int find(int x)
{
	if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(rnk[x]<rnk[y]) par[x]=y;
	else
	{
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

int b[maxn];
int w[maxn];
vector<int> g[maxn];
int dp[maxn];

int main()
{
	int n,m,weight;
	scanf("%d%d%d",&n,&m,&weight);
	init(n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int p,q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		unite(p,q);
	}
	int t;
	for(int i=0;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++)
	{
		t=find(i);
		g[t].push_back(i);
	}
	for(int i=0;i<=n;i++)
	{
		if(find(i)!=i) continue;
		int sumw=0,sumb=0;
		for(int k=0;k<g[i].size();k++)
		{
			sumb+=b[g[i][k]];
			sumw+=w[g[i][k]];
		}
		for(int k=weight;k>=0;k--)
		{
			for(int j=0;j<g[i].size();j++)
			{
				if(k>=w[g[i][j]]) dp[k]=max(dp[k],dp[k-w[g[i][j]]]+b[g[i][j]]);
			}
			if(k>=sumw) dp[k]=max(dp[k],dp[k-sumw]+sumb);
		}

	}
	printf("%d\n",dp[weight]);
    return 0;
}

```

