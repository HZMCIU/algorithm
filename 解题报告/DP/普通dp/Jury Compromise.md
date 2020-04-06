### [Jury Compromise](https://vjudge.net/problem/POJ-1015)

https://blog.csdn.net/lyy289065406/article/details/6671105

### 题意

有$n$个候补陪审员，每个陪审员有两个分数，$d_i$,$p_i$，从着$n$个候补陪审员中选出$m$个陪审员使得$|Sum(d_i)-Sum(p_i)|$ 最小。如果有两个最小$|Sum(d_i)-Sum(p_i)|$相同，那么取$|Sum(d_i)+Sum(p_i)|$最大的。输出陪审员的序号，以及对应的分数之和以及之差。

### 思路

动态规划。

1. 首先求出每个候补陪审员的两个分数的差值以及相加和，$v_i=p_i-d_i,sum_i=p_i+d_i$。
2. 定义状态`dp[i][j]`，选取$i$个陪审员，两分数差值为$j$，的最大分数和。
3. 策略：如果`dp[i-1][j-v[k]]!=-1`，即前面的状态存在。且k在前$i-1$个陪审员中未被选中，`dp[i][j]<dp[i-1][j-v[k]]+s[i]` ，选取$k$的分数之和比不选$k$的分数之和大，那么更新`dp[i][j]`。
4. 使用`path[i][j]`来选第$i$个陪审员时，陪审员的序号。

### 总结

这次的DP要求解的最值是$|Sum(d_i)-Sum(p_i)|$的最小值，但是这道题目DP状态的定义并不是和$|Sum(d_i)-Sum(p_i)|$有关。定义的DP是$|Sum(d_i)+Sum(p_i)|$然后枚举所有的状态从最后的状态中挑出符合题意的答案。

由于DP过程中会出现负数，所以使用了一个**偏移量**`fixed`来校正。

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 8e2 + 10;
int dp[30][maxn];
int path[30][maxn];
int v[maxn];
int s[maxn];
int n, m;

bool select(int i, int j, int k)//判断前i-1个陪审员中是否包含k
{
    while(path[i][j] != k && i > 0)//路径回溯
    {
        j -= v[path[i][j]];
        i--;
    }
    return i == 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int T=1;
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0)
            break;
        int d, p;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &d, &p);
            v[i] = p-d;
            s[i] = d + p;
        }
        memset(dp, -1, sizeof(dp));
        memset(path, 0, sizeof(path));
        int fixed = 20*m;
        dp[0][fixed] = 0;//初始状态为0
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j <= 2 * fixed; j++)
            {
                if(dp[i - 1][j] >= 0)
                {
                    for(int k = 1; k <= n; k++)
                    {
                        if(dp[i - 1][j] + s[k] >= dp[i][j + v[k]])
                        {
                            if(select(i - 1, j, k))
                            {
                                dp[i][j + v[k]] = dp[i - 1][j] + s[k];
                                path[i][j + v[k]] = k;
                            }
                        }
                    }
                }
            }
        }
        int i;
        for(i = 0; i <= fixed; i++)//从中间向两边找
        {
            if(dp[m][fixed - i] >= 0 || dp[m][fixed + i] >= 0)
                break;
        }
        int div=dp[m][fixed-i]>dp[m][fixed+i]?(fixed-i):(fixed+i);
        int P=(dp[m][div]-div+fixed)/2;
        int D=(dp[m][div]+div-fixed)/2;
        vector<int> pa;
        while(m>0)
        {
            pa.push_back(path[m][div]);
            div-=v[path[m][div]];
            m--;
        }
        sort(pa.begin(),pa.end());
        printf("Jury #%d\n",T++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",P,D);
        for(int i=0;i<pa.size();i++)
            printf(" %d",pa[i]);
        puts("");
        puts("");
    }
    return 0;
}
```

