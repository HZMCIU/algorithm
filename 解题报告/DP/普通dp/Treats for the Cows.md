### [Treats for the Cows](https://vjudge.net/problem/POJ-3186)

### 题意

看翻译

### 思路

DP。

定义状态`dp[i][j]`从前面取$i$个，从后面取$j$个数的最大值。

状态转移方程，`dp[i][j]=max(dp[i-1][j]+(i+j)*a[i],dp[i][j-1]+(i+j)*a[n-(j-1)])` 。即这次取数要么取头，要么取尾。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2e3+10;
const int inf=0x3f3f3f3f;
int a[maxn];
int dp[maxn][maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;i+j<=n;j++)
        {
            if(i==0&&j==0)
                dp[i][j]=0;
            else if(i==0&&j!=0)//全部从尾部取
                dp[i][j]=max(dp[i][j],dp[i][j-1]+j*a[(n-(j-1))]);
            else if(i!=0&&j==0)//全部从头部取
                dp[i][0]=max(dp[i][0],dp[i-1][0]+i*a[(i)]);
            else
            {
                dp[i][j]=max(dp[i-1][j]+(i+j)*a[i],dp[i][j-1]+(i+j)*a[n-(j-1)]);
            }
        }
    }
    int ans=-inf;
    for(int i=0;i<=n;i++)
    {
        ans=max(ans,dp[i][n-i]);
    }
    printf("%d\n",ans);
    return 0;
}
```

