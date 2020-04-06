### [Aladdin and the Flying Carpet](https://vjudge.net/problem/LightOJ-1341#author=cjyl)

### 题意

给出$a,b$ ，求出将$a$分解为两个整数$n,m$相乘一共多少对可能，其中$min(n,m)\ge b$ 。

### 思路

[整数唯一分解定理](https://zh.wikipedia.org/zh-hans/%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86)

一个整数$n$可以分解成若干素数的乘积，而且分解方法是唯一的。

一个大于1的整数$N$，它的标准分解式为$N=P_1^{a_1}P_2^{a_2}...P_n^{a_n}$

- 那么它的**正因子**的个数$\sigma_0(N)=(1+a_1)(1+a_2)...(1+a_n)$
- 全体因子之和为$\sigma_1(N)=(1+P_1^1+P_1^2+...+P_1^{a_1})(1+P_2^1+P_2^2+...+P_1^{a_2})...((1+P_n^1+P_n^2+...+P_n^{a_n}))$

使用性质2，算出a所有的因子的个数k，k/2就是因子对的个数。例如6，有1，2，3，6，4个因子，那么就有2对因子对(2,3),(1,6)。

然后暴力枚举[1,b)中所有的a的因子对cnt。k-cnt就是答案。（有个疑问，[1,b)的暴力是1e6，能够AC,但是纯粹的暴力就会TLE。）

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
bool isprime[maxn];
int prime[maxn];
int cnt;
int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<maxn;i++)
        isprime[i]=1;
    isprime[0]=isprime[1]=false;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[cnt++]=i;
            for(int j=2*i;j<maxn;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        ll a,b;
        cin>>a>>b;
        int ans=1;
        if(b*b>=a)//找不到方案
        {
            printf("Case %d: %d\n",cs,0);
            continue;
        }
        ll ta=a;
        for(int i=0;i<cnt&&a>=prime[i];i++)//不能枚举所有的质数，否则会TLE
        {
            int k=1;
            while(a%prime[i]==0)
            {
                k++;
                a/=prime[i];
            }
            ans*=k;
        }
        if(a>1)//如果a不为1，那么a肯定为素数
            ans*=2;
        ans/=2;
        a=ta;
        for(int i=1;i<b;i++)
        {
            if(a%i==0)
                ans--;
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
```





