### [Arbitrage](https://vjudge.net/problem/POJ-2240)

### 题意

给出两个国家的汇率，问能否经过一系列汇率的转化，然后使得美元的金额增加。

### 思路

使用类似于`Bellman-Ford`算法的DP的思想，来求解美元转化为其他货币的**最大值**。最后再来判断一下是否存在**正环**。求解美元转化其他货币的最大值和求解最短的差别就在于把加法换成乘法。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
const int maxn=1e4;
const int inf=0x3f3f3f3f;
struct
{
    int u,v;
    double cost;
}edge[maxn];

double dist[maxn];
int n;
int tot;
map<string,int> mp;
bool bellman_ford(int s)
{
    fill(dist,dist+n+1,0);
    dist[s]=1;
    for(int i=1;i<=n;i++)//把最后一次判断“正环”的操作合并
    {
        for(int j=0;j<tot;j++)
        {
            if(dist[edge[j].u]*edge[j].cost>dist[edge[j].v])
            {
                dist[edge[j].v]=dist[edge[j].u]*edge[j].cost;
            }
        }
    }
    return dist[s]>1.0;//大于等于会错
}
int main()
{
    freopen("in.txt","r",stdin);
    int Case=0;
    while(~scanf("%d",&n)&&n)
    {
        string tmp;
        int s;
        for(int i=0;i<n;i++)
        {
            cin>> tmp;
            mp[tmp]=i;
            if(tmp=="USDollar") s=i;
        }
        scanf("%d",&tot);
        string u,v;
        double cost;
        for(int i=0;i<tot;i++)
        {
            cin>>u>>cost>>v;
            int from=mp[u];
            int to=mp[v];
            edge[i].u=from;
            edge[i].v=to;
            edge[i].cost=cost;
        }
        int ret=bellman_ford(s);
        if(ret)
        {
            printf("Case %d: Yes\n",++Case);
        }
        else printf("Case %d: No\n",++Case);
    }
    return 0;
}
```

