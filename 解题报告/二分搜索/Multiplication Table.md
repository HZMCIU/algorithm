## [Multiplication Table](https://cn.vjudge.net/problem/CodeForces-448D)

#### 思路

二分答案，检查表中比待检查值**mid** 要小的值是否大于k个。如果大于k的话，那么搜索区间向左移动，否则向右移动

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int check(ll mid)
{
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        sum+=min(m,mid/i);//统计有多少个元素的值比mid要小
    }
    return sum>=k;
}
ll bsearch()
{
    ll l=0,r=250000000000,mid;
    ll ans;
    while(l<=r)
    {
        mid=(r-l)/2+l;
        if(check(mid))
        {
            //printf("%I64d\n",mid);
            ans=mid;
            r=mid-1;
        }
        else l=mid+1; 
    }
    return ans;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    ll res=bsearch();
    printf("%I64d\n",res);
    return 0;
}

```

