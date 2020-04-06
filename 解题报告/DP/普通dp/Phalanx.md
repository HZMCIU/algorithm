### [Phalanx](https://vjudge.net/problem/HDU-2859)

### 题意

给出一个字符矩阵，求出最大的**斜对角线对称子矩阵**。

### 思路

DP

`dp[i][j]` 以`(i,j)`为右上角的对称子矩阵的最大长度。

策略：

如果`dp[i][j]`大于等于`dp[i+1][j-1]+1`，即比左下角的子矩阵大，那么`dp[i][j]=dp[i+1][j-1]+1`。

如果小于`dp[i+1][j-1]+1` ，那么`dp[i][j]=pat,即匹配的数量`(缩小矩阵)

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;
char mat[maxn][maxn];
int a[maxn];
int dp[maxn][maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%s",mat[i]+1);
        int ans=1;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==n||j==1) dp[i][j]=1;
                int x=i,y=j;
                while(x<=n&&j>=1&&mat[x][j]==mat[i][y])
                {
                    x++;
                    y--;
                }
                int pat=x-i;
                if(dp[i+1][j-1]+1<=pat) dp[i][j]=dp[i+1][j-1]+1;
                else dp[i][j]=pat;
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

