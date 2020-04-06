### [Candies](https://vjudge.net/problem/POJ-3159)

### 题意

班主任让班长分发糖果。第i个同学认为第j个同学的糖果不能比他多c个。即，设`x[i]`为第i个同学得到的糖果的数量。$x[i]-x[j]\leq c$ 。问第1号同学和第n号同学的糖果最大差值为多少。

### 思路

题目可以翻译成一系列不等式。

$x[i]_1-x[j]_1\leq c_1\\x[i]_2-x[j]_2\leq c_2$ 

等等。

问`abs(x[1]-x[n])`的差值最大为多少。	

举例：

[博客](https://blog.csdn.net/my_sunshine26/article/details/72849441)

求$|X_3-X_0|$

$X_1-X_0\leq1\quad(1)\\X_2-X_0\leq2\quad(2)\\X_3-X_0\leq 4\quad(3)\\X_2-X_1\leq3\quad(4)\\X_3-X_2\leq 1\quad(5)$

$(3)\rightarrow$ $X_3-X_0\leq4$

$(1),(4),(5)\rightarrow X_3-X_0\leq5$

$(2),(5)\rightarrow X_3-X_0\leq3$

综上$X_3-X_0\leq3$ 。

所以最大值是3。上述过程类似于求解最短路（最大值受限于最小的c，从0走到n），可以将差分约束转化为求解最短路。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 2e5+10;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct node
{
    int n;
    int d;
    node() {}
    node(int n_, int d_): n(n_),d(d_) {}
    bool operator < (const node &a) const
    {
        return d>a.d;
    }
};
struct node2
{
    int v;
    int w;
    int next;
};
node2 edge[maxn];
int head[maxn];
int tot;
int dist[maxn];
void addedge(int u,int v,ll w)//使用数组，否则后超时。
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m;
void dijkstra()
{
    priority_queue<node> que;
    memset(dist,inf,sizeof(dist));
    dist[1]=0;
    que.push(node(1,0));
    while(!que.empty())
    {
        node t=que.top();
        que.pop();
        int u=t.n;
        int cost=t.d;
        if(dist[u]<t.d) continue;
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].w;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                que.push(node(v,dist[v]));
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++)
    {
        int u,v;
        int d;
        scanf("%d%d%d",&v,&u,&d);
        addedge(v,u,d);
    }
    dijkstra();
    printf("%d\n",dist[n]);
    return 0;
}
```



