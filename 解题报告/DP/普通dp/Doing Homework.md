### [Doing Homework](https://vjudge.net/problem/HDU-1074#author=634579757)

### 题意

看翻译

### 思路

状态压缩DP。

定义状态`dp[s]`。完成`s`中各个任务的最小扣分。

策略：取$s$状态中的第$i$位$1$，将这个任务做为s状态中的**最后一个任务**，通过这样的操作的扣分是否比原来的扣分小。

状态转移方程：`dp[s]=min(dp[s^(1<<i)]+k,dp[s])` ,k为完成第i个任务所造成的罚时。

由于需要保存前驱，所以实现时DP数组使用结构体实现。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
const int inf = 1<<30;
struct node
{
    string sub;
    int cost, dead;
} a[50];
struct
{
    int now;
    int pre;
    int time;
    int score;
} dp[1 << 15];
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].sub >> a[i].dead >> a[i].cost;
        }
        int S = 1 << n;
        for(int s = 1; s < S; s++)
        {
            dp[s].score = inf;
            for(int i = n-1; i >=0; i--)//输入的字母是按照字典序输入的。从最后一个开始，因为整个状态S中的各个任务已经确定，尽可能将字典序大的任务放在最后面。
            {
                int te = 1 << i;
                if(te & s)
                {
                    int past = s - te;
                    int st = dp[past].time + a[i].cost - a[i].dead;
                    if(st < 0) st = 0;
                    if(st + dp[past].score < dp[s].score)
                    {
                        dp[s].now = i;
                        dp[s].time = dp[past].time + a[i].cost;
                        dp[s].pre = past;
                        dp[s].score = st + dp[past].score;
                    }
                }
            }
        }
        int cur = (1 << n) - 1;
        stack<int> path;
        while(cur)
        {
            path.push(dp[cur].now);
            cur = dp[cur].pre;
        }
        printf("%d\n", dp[(1 << n) - 1].score);
        while(!path.empty())
        {
            cout << a[path.top()].sub << endl;
            path.pop();
        }
    }
    return 0;
}
```

