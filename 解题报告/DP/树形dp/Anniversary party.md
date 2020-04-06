## [Anniversary party](https://cn.vjudge.net/problem/HDU-1520)  

[题解1](http://blog.csdn.net/angon823/article/details/52216086)

[题解2](https://www.cnblogs.com/kuangbin/archive/2012/08/28/2659716.html)

data:2018/1/21

```cpp
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=7000;
vector<int> graph[maxn];
int dp[maxn][2];
int happy[maxn];
int father[maxn];

void dfs(int root)
{
    int len=graph[root].size();
    for(int i=0;i<len;i++)
    {
        dfs(graph[root][i]);
    }
    for(int i=0;i<len;i++)
    {
        dp[root][1]+=dp[graph[root][i]][0];
        dp[root][0]+=max(dp[graph[root][i]][0],dp[graph[root][i]][1]);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&happy[i]);
            dp[i][1]=happy[i];
            father[i]=-1;
            graph[i].clear();
        }
        int a,b;
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a==0&&b==0) break;
            graph[b].push_back(a);
            father[a]=b;
        }
        int i=1;
        while(father[i]!=-1) i=father[i];
        //printf("%d\n",i);
        dfs(i);
        printf("%d\n",max(dp[i][1],dp[i][0]));
    }
    return 0;
}

```

