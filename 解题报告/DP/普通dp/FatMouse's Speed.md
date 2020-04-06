### [FatMouse's Speed](https://vjudge.net/problem/HDU-1160#author=prayerhgq)

### 题意

求老鼠体重严格递增，但是速度严格递减的最长序列。输出序列号。

### 思路

最长递增子序列。$O(n^2)$解法。首先对体重排序，然后求速度的最长递增子序列即可。使用DP结构体保存路径。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct node
{
    int w,s,id;
};
node a[maxn];
struct
{
    int l,pre;
}dp[maxn];//前i个节点的最长递增序列的长度和前驱节点。
int n;
int main(int argc, char **argv)
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d",&a[n].w,&a[n].s))
    {
        a[n].id=n+1;
        n++;
    }
    sort(a,a+n,[](node a,node b)->bool{return a.w<=b.w;});
    int mx=0,in;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i].l=1;
        for(int j=0;j<i;j++)
        {
            if(a[i].w>a[j].w&&a[j].s>a[i].s)
            {
                if(dp[j].l+1>dp[i].l)
                {
                    dp[i].l=dp[j].l+1;
                    dp[i].pre=j;
                }
            }
        }
        if(dp[i].l>mx)
        {
            mx=dp[i].l;
            in=i;
        }
    }
    printf("%d\n",mx);
    stack<int> S;
    int cur=in;
    while(cur!=-1)
    {
        S.push(a[cur].id);
        cur=dp[cur].pre;
    }
    while(!S.empty())
    {
        printf("%d\n",S.top());
        S.pop();
    }
    return 0;
}
```

