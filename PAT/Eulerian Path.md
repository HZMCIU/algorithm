### [ Eulerian Path](https://pintia.cn/problem-sets/994805342720868352/problems/994805349851185152)

### 题意

统计度数，判断是不是欧拉图。

### 坑点

首先使用深搜判断这个图是否是连通图，如果不是连通图那么就不是欧拉图了。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int degree[maxn];
int vis[maxn];
vector<int> maze[maxn];
int n,m;
int dfs(int u)
{
    vis[u]=true;
    for(int v:maze[u])
        if(!vis[v])
        dfs(v);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        degree[u]++;
        degree[v]++;
        maze[u].push_back(v);
        maze[v].push_back(u);
    }
    vector<int> even;
    vector<int> odd;
    for(int i=1;i<=n;i++)
    {
        if(degree[i]%2==0)
            even.push_back(i);
        else
            odd.push_back(i);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    for(int i=1;i<=n;i++)
        printf("%d%c",degree[i],i==n?'\n':' ');
    if(cnt!=1)
        puts("Non-Eulerian");
    else if(even.size()==n)
        puts("Eulerian");
    else if(odd.size()==2)
        puts("Semi-Eulerian");
    else
        puts("Non-Eulerian");
    return 0;
}
```

