### [Max Sum Plus Plus](https://vjudge.net/problem/HDU-1024)

### 题意

将一段序列分割成$m$段子序列，求子序列的**最大值**。

### 思路

动态规划。

定义状态`dp[i][j],将前j个数分为i组序列的最大值` 。

可以得到状态转移方程`dp[i][j]=max(dp[i][j-1]+a[j],max(dp[i-1][k])+a[j])`  。

即，第$j$个数，是单独一组，还是和第$i$组合并。

由于$m$未知，空间复杂度未知，使用**滚动数组**。

时间复杂度为$O(mn^2)$ 。对`max(dp[i-1][k])`进行优化。使用`mx[j]`数组记录前$j$个数组成$i-1$组子序列的最大数。时间复杂度为$O(n*m)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6;
const int inf=0x3f3f3f3f;
int dp[maxn];
int mx[maxn];
int a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=mx[i]=0;
        }
        //初始状态
        dp[0]=0;
        mx[0]=0;
        int _mx;//i组和的最大值
        for(int i=1;i<=m;i++)
        {
            _mx=-inf;
            for(int j=i;j<=n;j++)//循环从i开始，前i-1个数作废
            {
                dp[j]=max(dp[j-1]+a[j],mx[j-1]+a[j]);//单独一组，还是和第i组合并
                mx[j-1]=_mx;// _mx保存的是dp[i][j-1],即，前j-1个数组成i组的最大值，结合，j循环从i开始
                _mx=max(_mx,dp[j]);//更新_mx,为下一次循环更新当前mx[j]做准备
            }
        }
        printf("%d\n",_mx);
    }
    return 0;
}
```

