## [Charm Bracelet](https://cn.vjudge.net/problem/POJ-3624)

#### 思路

水题，dp空间优化

```cpp
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[2][13000];//使用两位dp数组
int w[3500];
int v[3500];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
    }
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j>=w[i])
                dp[i&1][j]=max(dp[(i-1)&1][j-w[i]]+v[i],dp[(i-1)&1][j]);
            else 
                dp[i&1][j]=dp[(i-1)&1][j];
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",dp[i][j]);
        }
        puts("");
    }*/
    printf("%d\n",dp[(i-1)&1][m]);
    return 0;
}

```

