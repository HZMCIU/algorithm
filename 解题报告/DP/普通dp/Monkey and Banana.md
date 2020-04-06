### [Monkey and Banana](https://vjudge.net/problem/HDU-1069#author=prayerhgq)

### 题意

给出$n$个长方体，问如何使得长方体叠成的高度最高。其中要满足，每个长方体的$w,l$**严格大于**下面长方体的$w,l$。

### 思路

经典动态规划，最长上升子序列。

首先对每个长方体枚举出**六种状态**，然后对每个长方体的长进行排序。如此，我们可以得到长度递减的序列。因为没有枚举出六种状态，所以一直wa。

接下来只要对宽度进行dp，找出高度最大下降子序列。

定义状态`dp[i],前i个石头能够排列出最大的高度`，

状态转移方程`dp[i]=max(dp[i],dp[j]+a[j].h)`

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int inf=0x3f3f3f3f;
struct node
{
    int l,w,h;
};
node b[maxn];
int dp[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    int x,y,z;
    int tot;
    int cs=0;
    while(~scanf("%d",&n),n)
    {
        tot=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            b[tot].l=z;
            b[tot].w=y;
            b[tot++].h=x;
            b[tot].l=y;
            b[tot].w=z;
            b[tot++].h=x;

            b[tot].l=x;
            b[tot].w=z;
            b[tot++].h=y;
            b[tot].l=z;
            b[tot].w=x;
            b[tot++].h=y;

            b[tot].l=y;
            b[tot].w=x;
            b[tot++].h=z;
            b[tot].l=x;
            b[tot].w=y;
            b[tot++].h=z;
        }
        sort(b,b+tot,[](node a,node b)->bool{if(a.l==b.l) return a.w>b.w;else return a.l>b.l;});
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<tot;i++)
        {
            dp[i]=b[i].h;
            for(int j=0;j<i;j++)
            {
                if(b[j].w>b[i].w&&b[j].l>b[i].l)
                {
                    dp[i]=max(dp[i],dp[j]+b[i].h);
                }
            }
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++cs,ans);
    }
    return 0;
}
```



