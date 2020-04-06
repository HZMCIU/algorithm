### [Common Subsequence](https://vjudge.net/problem/POJ-1458)

### 题意

求两个字符串的最长公共子序列。

### 思路

最长公共子序列模板题。

定义状态`dp[i][j]`，s字符串前i个字符和t字符串前j个字符的最长公共子序列。

状态转移方程。

1. 如果`s[i]==t[j]` ,`dp[i][j]=dp[i-1][j-1]+1`，即如果s字符串的第i个字符和t字符串的第j个字符相等，那么`dp[i][j]`等于t的前i-1个字符和s的前j-1个字符的最长公公共子序列长度**加一**。
2. 如果`s[i]!=t[j]`，`dp[i][j]=max(dp[i][j-1],dp[i-1][j])` 

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[500],t[500];
int dp[500][500];
int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%s%s",s+1,t+1)==2)
    {
        int n=strlen(s+1);
        int m=strlen(t+1);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
```

