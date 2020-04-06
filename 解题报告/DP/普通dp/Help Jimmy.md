### [Help Jimmy](https://vjudge.net/problem/POJ-1661)

### 题意

看中文

### 思路

老鼠垂直下落花费的时间是固定的。

所以求出再平台上移动的最少的时间即可。到一个平台上最少的水平移动时间，都是上一个垂直高度不超过MAX的所有平台到这个平台的最小值。

`dp[i][0]` ,从初始位置到第$i$个平台的最左端的花费时间的最小值

`dp[i][1]`，从初始位置到第$i$个平台的最右端的花费时间的最小值

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;
struct node
{
    int x1, x2, h;
};
node pl[maxn];
int dp[maxn][2];
bool cmp(node a, node b)
{
    return a.h >= b.h;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    int N, X, Y, MAX;
    while(t--)
    {
        memset(dp, inf, sizeof(dp));
        scanf("%d%d%d%d", &N, &X, &Y, &MAX);
        pl[0].x1 = X, pl[0].x2 = X, pl[0].h = Y;
        for(int i = 1; i <= N; i++)
            scanf("%d%d%d", &pl[i].x1, &pl[i].x2, &pl[i].h);
        sort(pl + 1, pl + 1 + N, cmp);
        dp[0][0] = abs(0);
        dp[0][1] = abs(0);
        for(int i = 0; i <= N + 1; i++)
        {
            bool l = false, r = false;//从第i个平台的左右端点往下跳，是否已经到达一个着陆点
            for(int j = i + 1; j <= N + 1; j++)//更新i平台下面的最小值
            {
                if(abs(pl[j].h - pl[i].h) > MAX)
                    break;
                if(pl[j].x1 <= pl[i].x1 && pl[i].x1 <= pl[j].x2 && !l)//左端未着陆
                {
                    l = true;
                    dp[j][0] = min(dp[j][0], dp[i][0] + abs(pl[i].x1 - pl[j].x1));
                    dp[j][1] = min(dp[j][1], dp[i][0] + abs(pl[i].x1 - pl[j].x2));
                }
                if(pl[j].x1 <= pl[i].x2 && pl[i].x2 <= pl[j].x2 && !r)//右端未着陆
                {
                    r = true;
                    dp[j][0] = min(dp[j][0], dp[i][1] + abs(pl[i].x2 - pl[j].x1));
                    dp[j][1] = min(dp[j][1], dp[i][1] + abs(pl[i].x2 - pl[j].x2));
                }
            }
        }
        int ans = min(dp[N][0], dp[N][1]);
        //找能够直接跳到地面上，并且高度相差不超过MAX的平台水平移动距离的最小值
        for(int i=0;i<=N;i++)
        {
            if(pl[i].h>MAX)
                continue;
            bool l=false,r=false;
            for(int j=i+1;j<=N;j++)
            {
                if(pl[j].x1<pl[i].x1&&pl[i].x1<pl[j].x2)
                    l=true;
                if(pl[j].x1<pl[i].x2&&pl[i].x2<pl[j].x2)
                    r=true;
            }
            if(!l)
                ans=min(ans,dp[i][0]);
            if(!r)
                ans=min(ans,dp[i][1]);
        }
        //结果加上垂直下落距离
        printf("%d\n", ans+Y);
    }
    return 0;
}
```

