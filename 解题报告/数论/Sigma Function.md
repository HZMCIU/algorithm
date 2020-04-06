### [Sigma Function](https://vjudge.net/problem/LightOJ-1336#author=0)

### 题意

求解[1,n]中约数和为偶数的个数。

### 思路

**背景知识**

[整数唯一分解定理](https://zh.wikipedia.org/zh-hans/%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86)

一个大于1的整数$N$，它的标准分解式为$N=P_1^{a_1}P_2^{a_2}...P_n^{a_n}$

全体因子之和为

$\sigma_1(N)=(1+P_1^1+P_1^2+...+P_1^{a_1})(1+P_2^1+P_2^2+...+P_1^{a_2})...((1+P_n^1+P_n^2+...+P_n^{a_n}))$

**问题分析**

求解约数和为偶数的个数，可以通过N-约数和为奇数的个数获得。所以问题转化为求解[1,n]约数和为偶数的个数。

奇数$\times$奇数=奇数。偶数$\times$ (奇数|偶数)=偶数。要使得$\sigma (N)$为奇数，那么就要保证$\sigma(N)$**所有的项均为奇数**。除了2之外的所有质数均为奇数。如果先不考虑2，所以只要保证所有的$a_i$为**偶数**即可。如果所有的$a_i$为偶数，那么$n$就是**完全平方数**。

如果$P=2$，那么$(1+P^1+..+P^n)$的值**永远为奇数**。所以只要$n$中含有因子2，那么$\sigma(n)=奇数$ 。但是如果$n$中因子2出现偶数次，那么$n$就是完全平方数（此时仍然要保证其他项是奇数，即$a_i$为偶数），在上一步中已经被计算过了。所以这些数是**完全平方数的2n倍(n为奇数)**。可以除以2，转化为完全平方数求得。`sqrt(n/2)`。

所以$\sigma(N)=奇数$为所有的**完全平方数**的个数加上**完全平方数的2n倍(n为奇数)**的个数。

### 总结

**反面求解**。不直接求解偶数，而是求解奇数来获得解。

### AC代码

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
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        ll n;
        cin>>n;
        //分别是小于n完全平方数的个数以及完全平方数2倍的个数
        ll ans = n-ll(sqrt(n)) -ll(sqrt(n/2));
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}

```

