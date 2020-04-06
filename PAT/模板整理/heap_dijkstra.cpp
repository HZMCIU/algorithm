#include <algorithm>
const int maxn;
int dist[maxn];
struct edge {
    int to;
    int cost;
}
typedef pair<int,int> P;
vector<edge> G[maxn];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P>> que;
    memset(dist,inf,sizeof(dist));
    dist[s]=0;
    que.push_back(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(dist[v]<p.first)
        {
            continue;
        }
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            
        }
    }
}