### [Bi-shoe and Phi-shoe](https://vjudge.net/problem/LightOJ-1370#author=HUCM201732)

### 题意

给出一组数$x_i$。 找到一个$n_i$ 的最小值，使得$\phi(n_i)\ge x_i$ ,。$\phi(x)$为欧拉函数。 求$\sum n_i$

### 思路

一个整数$N$的标准分解式为$N=P_1^{a_1}P_2^{a_2}...P_n^{a_n}$

那么欧拉函数$\phi(N)=N*(1-\frac{1}{P_1})(1-\frac{1}{P_2})...(1-\frac{1}{P_n})$

方法一：

使用类似素数筛的方式来求出所有的欧拉函数。

```cpp
	for(int i=0;i<maxn;i++)//欧拉函数phi[n]初始化为n
        phi[i]=i;
    for(int i=0;i<maxn;i++)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;
    phi[1]=0;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])//每当找到一个数为质数，那么下面所有因子中包含这个质数的数都要进行更新
        {
            for(int j=i;j<maxn;j+=i)
            {
                isprime[j]=false;
                phi[j]-=phi[j]/i;//迭代更新
            }
        }
    }
```

最后使用一个`rec[i]`数组来记录欧拉函数大于i的最小整数的值。

方法二：

如果一个质数$P$，那么$\phi(P)=P-1$ 。

给出一个数$x$，求$\phi(n)\ge x $  $n$ 的最小值，如果$x$位于两个相邻的质数$P_1,P_2$之间那么，最小的$n$就是$P_2$。因为$P_1,P_2$之间所有的和数的欧拉函数值都小于$\phi(P_2)=P_2-1  \phi(P_1)=P_1-1$ 。如果$x$恰好是质数，那么n就是下一个比$x$大的质数。

通过打表找出所有的质数，然后二分找到$n$。

### AC代码

方法一：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
bool isprime[maxn];
int phi[maxn];
int rec[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for(int i=0;i<maxn;i++)
        phi[i]=i;
    for(int i=0;i<maxn;i++)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;
    phi[1]=0;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                isprime[j]=false;
                phi[j]-=phi[j]/i;
            }
        }
    }
    memset(rec,0,sizeof(rec));
    for(int i=0;i<maxn;i++)
    {
        for(int j=phi[i];j>=0&&rec[j]==0;j--)
        {
            rec[j]=i;
        }
    }
    for(int cs=1;cs<=t;cs++)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ans+=rec[x];
        }
        printf("Case %d: %lld Xukha\n",cs,ans);
    }
    return 0;
}
```

方法二：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
bool isprime[maxn];
int prime[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for(int i=0;i<maxn;i++)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;
    int tot=0;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[tot++]=i;
            for(int j=2*i;j<maxn;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int cs=1;cs<=t;cs++)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            int pos=upper_bound(prime,prime+tot,x)-prime;
            ans+=prime[pos];
        }
        printf("Case %d: %lld Xukha\n",cs,ans);
    }
    return 0;
}
```

