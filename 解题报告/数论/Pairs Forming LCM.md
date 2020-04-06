### [Pairs Forming LCM](https://vjudge.net/problem/LightOJ-1236)

### 题意

给出如下代码，编写能够在$n<=10^{14}$情况下运行的代码

```cpp
long long pairsFormLCM( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = i; j <= n; j++ )
           if( lcm(i, j) == n ) res++; // lcm means least common multiple
    return res;
}
```

### 思路

分析上诉的代码可以得到，`lcm(i,j)`其中`i,j`是无序的。

根据唯一分解定理，任意整数$n$可以分解得到$n=p_1^{k_1}\times p_2^{k_2}\times p_3^{k_3} ...\times p_n^{k_n}$

所以，

$a=p_1^{d_1}\times p_2^{d_2}\times p_3^{d_3} ...\times p_n^{d_n}$  

$b=p_1^{e_1}\times p_2^{e_2}\times p_3^{e_3} ...\times p_n^{e_n}$ 

$lcm(a,b)=n=p_1^{k_1}\times p_2^{k_2}\times p_3^{k_3} ...\times p_n^{k_n}$

其中$k_i=max(e_i,d_i)$

若是$gcd(a,b)=n=p_1^{k_1}\times p_2^{k_2}\times p_3^{k_3} ...\times p_n^{k_n}$

那么有，$k_i=min(e_i,d_i)$

这也就解释了$lcm(a,b)=\frac{i\times j}{gcd(a,b)}$公式的来历了

+ 分解$n$的质因子，得到这样的形式，$n=p_1^{k_1}\times p_2^{k_2}\times p_3^{k_3} ...\times p_n^{k_n}$
+ 那么对于任意一位，有$e_i=k_i$ 或者$d_i=k_i$ ，另外一位任取，那么就有$2*k_i+2$种方案，因为$e_i=d_i=k_i$重复计算了，所以去除重复后的方案的个数为$2\times k_i+1$个
+ 由于是要计算无序对，所以最后的结果要除以2。

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e7+100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
//不知道为什么，如果ll prime[maxn]，那么就会runtime error
ll prime[maxn/10];
bool vis[maxn];
ll tot;

void getprime()
{
     for(ll i=2;i<maxn;i++)
        if(!vis[i])
        {
            prime[tot++]=i;
            for(ll j=i*i;j<maxn;j+=i) vis[j]=1;
        }

}
int main()
{
  //  freopen("in.txt", "r", stdin);
    getprime();
    int T;
    scanf("%d",&T);
    for(ll cs=1;cs<=T;cs++)
    {
        ll n;
        cin>>n;
        ll t=n;
        ll ans=1;
        for(int i=0;i<tot&&prime[i]*prime[i]<=n;i++)
        {
            ll cnt=0;
            while(t%prime[i]==0) cnt++,t/=prime[i];
            ans*=(2*cnt+1);
        }
        if(t>1) ans*=3;
        ans = ans/2 +1;
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }
    return 0;
}
```

