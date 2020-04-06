### [Super Jumping! Jumping! Jumping!](https://vjudge.net/problem/HDU-1087)

### 题意

看翻译

### 思路

最长递增子序列。

`dp[i]` 前i个递增子序列的最大值。

`dp[i]=max(dp[i],dp[j]+a[i]),a[i]>a[j],i>j`

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
const int inf = 1<<30;
int a[maxn];
int dp[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=a[i];
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

