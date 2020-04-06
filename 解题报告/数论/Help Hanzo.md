### [Help Hanzo](https://vjudge.net/problem/LightOJ-1197)

### 题意

筛选出区间内的素数的个数

### 思路

首先，先用素数筛，把1e6内的所有素数找出来。

然后，对$[a,b]$内的所有数，使用素数筛的方法，把不是素数的数去除。当然数组无法开到$2^{31}$ 。所以要进行**偏移**。

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;

bool vis[maxn];
bool isprime[maxn];
ll prime[maxn];
int cnt=0;

ll getprime()
{
    for(ll i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(ll j=i*i;j<maxn;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    getprime();
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        memset(isprime,0,sizeof(isprime));
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll ans=b-a+1;
        if(a==1)
            ans--;
        for(int i=0;i<cnt&&prime[i]*prime[i]<=b;i++)
        {
            for(ll j=a/prime[i]*prime[i];j<=b;j+=prime[i])
                if(j>=a&&j>prime[i])
                isprime[j-a]=1;

        }
        for(int i=0;i<=b-a;i++)
            if(isprime[i])
            ans--;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
```

