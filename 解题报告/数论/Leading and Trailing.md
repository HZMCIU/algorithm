### [Leading and Trailing](https://cn.vjudge.net/problem/LightOJ-1282)

### 题意

给出n,k。求$n^k$的前三个数字和后三个数字。

### 思路

后三个数字，用**快速幂**求解。

前三个数字的求解。

假设$n^k$ 的前三位为$a,b,c$。那么$n^k $可以表示为$a.bc\times 10^m$ 。

$m$的大小可以通过`log10()`函数来求解，$m$的值为`log10(n^k)`的**整数部分**。 

设`log(n^k)`的小数部分为`t`，那么$10^t=a.bc$。

```cpp
double t=k*log10(n)-int(k*log10(n));//t为小数部分
ll(pow(10,t)*100)//求出10^t,乘以100，取整，那么获得的值就是前三位的值
```

### 总结

学会使用`log10()`来获得一个数前$n$位数字的方法。

### AC代码

注意如果没有满三位，那么需要用0来填充。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
ll qpow(ll n,ll k)
{
    ll ans=1;
    ll base=n%1000;
    while(k)
    {
        if(k&1)
            ans=ans*base%1000;
        base=(base*base)%1000;
        k>>=1;
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        ll n,k;
        cin>>n>>k;
        double t=k*log10(n)-int(k*log10(n));
        printf("Case %d: %03lld %03lld\n",cs,ll(pow(10,t)*100),qpow(n,k));
    }
    return 0;
}
```

