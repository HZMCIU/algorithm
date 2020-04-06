### [Milking Time](https://vjudge.net/problem/POJ-3616)

### 题意

给出$m$个任务，完成每个任务都需要一段时间，完成后需要$r$的休息时间。完成每个任务都要一个效益值，问在时间$n$内所能达到的最大效益值。

### 思路

DP。使用类似于最长递增子序列的思路。对于第$i$个任务，应该在第$j$个任务之后完成效益较高，$j<i$ 。复杂度$O(n^2)$。

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e4;
const int inf=0x3f3f3f3f;
struct node
{
    int s,t,w;
};
bool cmp(node a,node b)
{
    return a.s<=b.s;
}
node a[maxn];
int dp[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i].s,&a[i].t,&a[i].w);
    }
    sort(a,a+m,cmp);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int mx=0;
        dp[i]=a[i].w;
        for(int j=0;j<i;j++)
        {
            if(a[j].t+r<=a[i].s&&mx<dp[j])
            {
                dp[i]=dp[j]+a[i].w;
                mx=dp[j];
            }
        }
        ans=max(ans,dp[i]);
    }
//    for(int i=0;i<m;i++)
//        printf("%d %d %d\n",a[i].s,a[i].t,a[i].w);
    printf("%d\n",ans);
    return 0;
}
```

