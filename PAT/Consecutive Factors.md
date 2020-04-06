### [ Consecutive Factors ](https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688)

### 题意

给出一个数$n$，求出这个数最长的连续因子。例如630的最长的连续因子为6 7 8 ，630%(6\*7\*8)=0。

### 思路

过了个年，脑子就废了。刚看到这道题目的时候，想到的是用素数筛来做，把所有的质因子求出来，然后组合这些质因子，获得一个新的质因子`k`，然后从求剩下的质因子能否构造出`k+1` ，以此类推，woc，我的榆木脑袋。这么笨的方法。

看了网上的题解，如果这个数是合数的话，那么这个数的最大的因子的数不会超过$\sqrt{n}$ 。所以明白了这个性质后，只要暴力枚举就可以了。

### 总结

如果一道题目能够使用简单的方法解决，那么尽量使用简单的方法。像这道题题目我上来就使用素数筛，最后把一道简单题搞得神烦。

其次分析题目给出的条件，找出特殊的地方，能够大大简化解题的过程。就像这道题中的合数的最大因子不会超过$\sqrt {n}$ .

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=4e5+100;
typedef long long ll;
typedef pair<int,int> P;
int main()
{
//    freopen("in.txt","r",stdin);
    ll n;
    scanf("%lld",&n);
    bool isprime=true;
    ll l=-1,r=-1;
    ll ans=0;
    for(ll i=2;i<=sqrt(n)+1;i++)
    {
        if(n%i==0)
        {
            ll tl=i;
            ll t=n/i;
            ll tr;
            for(tr=i+1;t%tr==0;tr++)
                t/=tr;
            if(ans<tr-tl)
            {
                ans=tr-tl;
                l=tl;
                r=tr-1;
            }
        }
    }
    //是素数
    if(l==-1)
    {
        printf("1\n%lld",n);
    }
    else
    {
        printf("%d\n",ans);
        printf("%d",l);
        for(int i=l+1;i<=r;i++)
            printf("*%d",i);
    }
    return 0;
}
```

