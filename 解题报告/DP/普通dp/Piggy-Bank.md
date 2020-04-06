### [Piggy-Bank](https://vjudge.net/problem/HDU-1114#author=ChineseOJ)

### 题意

一个背包容量为$F-E$，给出$n$件物品，价值为P~i~，重量为W~i~。每件物品的数量能够取得数量不限，问这个背包最少能够装多少价值的物品。

### 思路

多重完全背包。

定义状态`dp[i][j]`，前i件物品重量不超过j的最少价值。

状态转移方程，`dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]|k>=0)`，复杂度$O(nW^2)$

**时间复杂度优化**，

`max(dp[i][j-k*w[i]]+k*v[i]|k>=0)`

`max(dp[i][j],dp[i][j-k*w[i]]+k*v[i]|k>=1)`

`max(dp[i][j],max(dp[i][(j-w[i])-k*w[i]]+k*v[i]|k>=0)+v[i])`

`max(dp[i][j],dp[i][j-w[i]]+v[i])`

**空间复杂度优化**

```cpp
for(int i=1;i<=n;i++)
{
    for(int j=w[i];j<=W;j++)
        dp[j]=max(dp[j],dp[j-w[i]]);
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dp[maxn];
int w[maxn];
int v[maxn];
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, inf, sizeof(dp));
        int n;
        int E, F;
        int W;
        scanf("%d%d", &E, &F);
        W = F - E;
        scanf("%d", &n);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for(int i = 1; i <= n; i++)
        {
            for(int j = w[i]; j <= W; j++)
            {
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        if(dp[W] != inf)
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[W]);
        else printf("This is impossible.\n");
    }
    return 0;
}
```



