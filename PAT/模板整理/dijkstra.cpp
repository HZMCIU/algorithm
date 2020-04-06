const int maxn;
int dist[maxn];
int vis[maxn];
int cost[maxn][maxn];


int dijkstra(int s)
{
    memset(dist,inf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[s]=0;
    vis[s]=1;
    for(int i=0;i<n;i++)
        dist[i]=min(dist[i],cost[s][i]);
    while(true)
    {
        int v=-1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0&&(v==-1||dist[i]<dist[v]))
            {
                v=i;
            }
        }
        if(v==-1)
            break;
        vis[v]=1;
        for(int i=0;i<n;i++)
        {
            dist[i]=min(dist[i],dist[v]+cost[v][i]);
        }
    }
}