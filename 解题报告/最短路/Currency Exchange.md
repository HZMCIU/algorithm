### [Currency Exchange](https://vjudge.net/problem/POJ-1860)

### 题意

一个站点可以货币$A$兑换成货币$B$。$RAB,CAB$分别为将$A$兑换为$B$的汇率和佣金。问是否可以经过一系列兑换，使得本金的数量增加。

### 思路

题目类似于**Bellman-Ford**算法求解最短路径时判定图中是否存在**负环**。题目中是否可以**增加本金**和负环相类似。路径采用类似于Bellman-Ford类似的松弛方法。

[博客](https://blog.csdn.net/LYHVOYAGE/article/details/19281013)

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int maxn = 1e3 + 1;
const int inf = 0x3f3f3f3f;
int N, M, S;
double V;
struct edge
{
    int a, b;
    double rate, cost;
    edge(int _a, int _b, double _rate, double _cost): a(_a), b(_b), rate(_rate), cost(_cost) {}
    edge() {}
} p[maxn];
int tot = 0;
double dist[maxn];
bool bellman_ford()
{
    memset(dist, 0, sizeof(dist));
    dist[S] = V;
    for(int i = 1; i <= N - 1; i++)
    {
        bool f = false;
        for(int j = 0; j < tot; j++)
        {
            int a = p[j].a, b = p[j].b;
            double r = p[j].rate, c = p[j].cost;
            if(dist[b] < (dist[a] - c)*r)
            {
                dist[b] = (dist[a] - c) * r;
                f = true;
            }
        }
        if(!f) break;
    }
    for(int i = 0; i < tot; i++)
    {
        int a = p[i].a, b = p[i].b;
        double r = p[i].rate, c = p[i].cost;
        if(dist[b] < (dist[a] - c)*r)
            return false;
    }
    return true;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d%d%d%lf", &N, &M, &S, &V))
    {
        for(int i = 0; i < M; i++)
        {
            int a, b;
            double rab, cab, rba, cba;
            scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
            p[tot].a = a;
            p[tot].b = b;
            p[tot].rate = rab;
            p[tot++].cost = cab;
            p[tot].a = b;
            p[tot].b = a;
            p[tot].rate = rba;
            p[tot++].cost = cba;
        }
        if(!bellman_ford())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
```

