### [The Shortest Path in Nya Graph](https://cn.vjudge.net/problem/HDU-4725)

###题意

有n个点，每个点属于一个平台。平台x和平台x+1可以直接相连，长度为c。**在同一个平台上的点，不能通过平台直接相连** 。此外，这n个点还有m条边相连。问从1到n的最短距离

### 思路

一个平台上可能有多个点。将一个层看成一个点，那么在这个层上的点就和这点抽象为点的层相连，连接的边的权值为0。但是这样的方法的是**错误**的。**因为这样一个平台上的的点就可以通过双向边实现连接权值为0的连接，例如实际上点2和点3是不能直接相连的，但是如果采用这个方法，他们就可通过点7来实现连接，这显然不符合题意**![方法一](E:\ACM\解题报告\ShortestPath\Bellman Ford\SPFA\方法1.png)

![方法2](E:\ACM\解题报告\ShortestPath\Bellman Ford\SPFA\方法2.png)

将每个层分解为两个点，分别用来表示出度和入度。出边从N+2*i-1出来，入边从N+2\*i进入，为了表示层x和层x+

1可以互相连接，点N+2*i和点N+2\*(i+1)-1相连，点N+2\*(i+1)和点N+2\*i-1相连。**这样既能够把层分解为点，同时也能够保证一个层中的点不会相互连接**

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
    int v;
    int w;
    int next;
    node(){}
    node(int v_,int w_):v(v_),w(w_){}
};
struct enode
{
    int v;
    int cost;
    bool operator < (const enode &a) const
    {
        return cost>=a.cost;
    }
    enode(){}
    enode(int v_,int cost_):v(v_),cost(cost_){}
};
int head[maxn];
int dist[maxn];
int tmp[maxn];
node edge[maxn];
bool vis[maxn];
int tot;
int n,m,c;
void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dijkstra(int s)
{
    memset(dist,inf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[s]=0;
    priority_queue<enode> que;
    que.push(enode(s,0));
    while(!que.empty())
    {
        enode t=que.top();
        que.pop();
        if(vis[t.v]) continue;
        vis[t.v]=true;
        for(int i=head[t.v];~i;i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].w;
            if(dist[v]>dist[t.v]+w)
            {
                dist[v]=w+dist[t.v];
                que.push(enode(v,dist[v]));
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            addedge(n+2*t-1,i,0);
            addedge(i,n+2*t,0);
        }
        for(int i=1;i<n;i++)
        {
            addedge(n+2*i,n+2*(i+1)-1,c);
            addedge(n+2*(i+1),n+2*i-1,c);
        }
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dijkstra(1);
//        for(int i=1;i<=2*n;i++)
//            printf("%d ",dist[i]);
//        puts("");
        if(dist[n]!=inf)
            printf("Case #%d: %d\n",++iCase,dist[n]);
        else
            printf("Case #%d: %d\n",++iCase,-1);
    }
    return 0;
}
```

