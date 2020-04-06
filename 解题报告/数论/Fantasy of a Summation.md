### [Fantasy of a Summation](https://vjudge.net/problem/LightOJ-1213)

### 题意

给出代码，找规律。

### 思路

通过分析代码得出公式。

$ans=k\times n^{k-1}\times A[0]+...+k\times n^{k-1}\times A[K] $

然后使用快速幂就行了

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;


ll qpow(ll a,ll b,ll mod)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ll a[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        ll n,k,mod;
        scanf("%lld%lld%lld",&n,&k,&mod);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ll res=0;
        ll t=qpow(n,k-1,mod);
        t=t*k%mod;
        for(int i=0;i<n;i++)
        {
            res=(res+t*a[i])%mod;
        }
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}

```

