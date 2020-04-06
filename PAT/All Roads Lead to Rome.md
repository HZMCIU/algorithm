### [All Roads Lead to Rome]()

### 题意

求出到罗马的最短路，如果存在多条最短路，那么选取开心值最大的那条路，如果存在多条开心值相同的路，那么选取平均开心值最大的那一条路。

### 思路

使用Dijkstra算法求出多条最短路径。然后使用DFS遍历这些最短路径，找出符合条件的路径。

#### 注意点：在使用前驱数组节点保存要使用set类型数据结构，因为一个节点不存在两个相同的前驱，所以要去重。否则算出的路径的数量会有重复。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e4+100;
typedef long long ll;
typedef pair<int,int> P;
map<string,int> mp;
map<int,string> demp;
int cnt;
int hap[maxn];
struct edge
{
    int to;
    int cost;
    edge(int _to,int _cost):to(_to),cost(_cost){}
    edge(){}
};
vector<edge> maze[maxn];
int dist[maxn];
set<int> pre[maxn];//前驱节点数组应该开为set，来去重
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,s));
    memset(dist,inf,sizeof(dist));
    dist[s]=0;
    while(!que.empty())
    {
        P t=que.top();
        que.pop();
        if(t.first>dist[t.second])
            continue;
        int u=t.second;
        for(edge e:maze[u])
        {
            if(dist[u]+e.cost<dist[e.to])
            {
                dist[e.to]=dist[u]+e.cost;
                que.push(P(dist[e.to],e.to));
                pre[e.to].clear();
                pre[e.to].insert(u);
            }
            else if(dist[u]+e.cost==dist[e.to])
            {
                pre[e.to].insert(u);
                que.push(P(dist[e.to],e.to));
            }
        }
    }
}
vector<int> path;
vector<int> ans_path;
int ans_tot;
double ans_ave;
int ans_cnt;
int ans_dist;
void dfs(int u)
{
    if(pre[u].size()==0)
    {
        ans_cnt++;
        int tot=0;
        double ave;
        for(int i:path)
        {
            tot+=hap[i];
        }
        ave=1.0*tot/(path.size()-1);
        if(tot>ans_tot)
        {
            ans_path=path;
            ans_tot=tot;
            ans_ave=ave;

        }
        else if(tot==ans_tot&&ave>ans_ave)
        {
            ans_path=path;
            ans_ave=ave;
        }
        return ;
    }
    for(int v:pre[u])
    {
        path.push_back(v);
        dfs(v);
        path.pop_back();
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,k;
    string name;
    cin>>n>>k>>name;
    mp[name]=0;
    demp[0]=name;
    cnt=1;
    int t;
    for(int i=1;i<n;i++)
    {
        cin>>name>>hap[i];
        mp[name]=i;
        demp[i]=name;
        if(name=="ROM")
            t=i;
    }
    string from,to;
    int d;
    for(int i=0;i<k;i++)
    {
        cin>>from>>to>>d;
        int u=mp[from],v=mp[to];
        maze[u].push_back(edge(v,d));
        maze[v].push_back(edge(u,d));
    }
    dijkstra(0);
    path.push_back(t);
    dfs(t);
    reverse(ans_path.begin(),ans_path.end());
    printf("%d %d %d %d\n",ans_cnt,dist[t],ans_tot,int(ans_ave));
    cout << demp[ans_path[0]];
    for(int i=1;i<ans_path.size();i++)
        cout << "->" << demp[ans_path[i]];
	return 0;
}
```

