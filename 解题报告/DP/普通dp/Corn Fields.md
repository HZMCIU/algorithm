### [Corn Fields](https://vjudge.net/problem/POJ-3254#author=342705814)

### 题意

一块$n\times m$ 的田，$1$ 表示可以种植，$1$表示可以种植。每两株植物不能相邻，上下左右都不行。问有几种种植方案。

### 思路

状态压缩DP。可以用二进制位来表示每一行各个位置是否种植。

定义状态`dp[i][j],表示前i行状态为j的方案数一共有多少`

状态转移方程`dp[i][state]=dp[i][state]+d[i-1][pre_state]`

`state&(state<<1)` 检查是否存在左右相邻的植株。

`state&pre_state` 检查是否存在上下相邻的植株。

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod=1e8;
int dp[15][1<<15];
bool is[15][15];
int n,m;
bool check(int x,int status)
{
    if(status&(status<<1)) return false;//左右相邻
    for(int i=1;i<=m;i++)
    {
        if(!is[x][i])
        {
            if( ((1<<(m-i))&status) !=0 ) return false;//在为0的地方种植
        }
    }
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            scanf("%d",&is[i][j]);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                if(check(i,j))
                {
                    for(int k=0;k<(1<<m);k++)
                    {
                        if(!(k&j)) dp[i][j]+=dp[i-1][k];//如果上下不相邻
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<(1<<m);j++)
            ans=(ans+dp[n][j])%mod;
        printf("%d\n",ans);
    }
    return 0;
}
```

