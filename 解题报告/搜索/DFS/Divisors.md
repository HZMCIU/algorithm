## [Divisors](https://cn.vjudge.net/problem/CodeForces-448E)

##  

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
ll t=0;
ll cnt=0;
int dfs(ll x,ll k)
{
    if(cnt>=1e5)//题目要求只要输出1e5个数字就可以了
    {
        return 0;
    }
    if(x==1||k==0)
    {
        cnt++;
        printf("%I64d ",x);
        return 0;
    }
    for(ll i=0;i<t&&a[i]<=x;i++)
    {
        if(x%a[i]==0) dfs(a[i],k-1);
    }
    return 0;
}
int main()
{
    ll k,n;
    scanf("%I64d%I64d",&n,&k);
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a[t++]=i;
            if(n/i!=i) a[t++]=n/i;
        }
    }
    sort(a,a+t);
    dfs(n,k);
}

```

