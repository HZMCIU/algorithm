### [Hie with the Pie](https://vjudge.net/problem/POJ-3311#author=342705814)

### 思路

https://blog.csdn.net/qust1508060414/article/details/52005520

定义状态`dp[s][i]` 经过一系列城市，且`i`是最后到达的城市的最短距离。

状态转移方程`dp[s][i]=max(dp[s^(1<<(i-1))][j]+path[j][i],dp[s][i])`

即，通过第$j$个城市，是否比原来的路径要短。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1<<15][20];
int path[20][20];
const int inf=0x3f3f3f3f;
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                scanf("%d",&path[i][j]);
            }
        }
        //先用Floyd算法预处理出每个城市之间的最短路径
        for(int k=0;k<=n;k++)
        {
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                    path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
            }
        }
        int m=1<<(n+1);
        dp[0][0]=0;
        for(int s=0;s<m;s++)
        {
            for(int i=0;i<=n;i++)
            {
                if(s&(1<<(i)))//如果有经过第i个城市
                {
                    for(int j=0;j<=n;j++)
                    {
                        if(s&(1<<(j)))//经过j到达i是否比原来的路径要短
                        //异或，将第i位清零，其余位保持不变
                        dp[s][i]=min(dp[s][i],dp[s^(1<<(i))][j]+path[j][i]);
                    }
                }
            }
        }
        int ans=inf;
        for(int i=0;i<=n;i++)
        {
            ans=min(ans,dp[(1<<(n+1))-1][i]+path[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

