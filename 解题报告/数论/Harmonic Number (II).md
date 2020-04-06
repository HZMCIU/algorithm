###[Harmonic Number (II)](https://vjudge.net/problem/LightOJ-1245)

### 题意

题目给出一段代码，重写代码快速计算题目中给出的代码

```cpp
long long H( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ )
        res = res + n / i;
    return res;
}
```

### 思路

通过转化问题可以得到，在数字$i$有$[\frac{n}{i}-\frac{n}{i+1})$ 个，那么原问题就转化为求解区间$[[\frac{n}{i}-\frac{n}{i+1})]$的大小了，看似还需要遍历所有的$n$，复杂度没有得到简化。但是仔细思考可以发现，当$i$的值大到一定程度的时候，区间的大小就小于1,这可以通过函数$\frac{k}{x}-\frac{k}{x+1}\le1$ 得到，当$i\ge \sqrt{n}$的时候区间的大小就小于1。

但是这样仍然不够，这是因为进行的是整数取整运算，所以有些区间可能是1，有些区间可能是0。怎么判断区间是1呢，可以发现区间$[\frac{n}{i}-\frac{n}{i+1})$ 为1的时候的$\frac{n}{i}$的值均小于$\sqrt{n}$。

通过以上的简化，复杂度降到了$O(\sqrt{n})$。

woc，这他妈规律也太难找了吧。还是太菜。。。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5;
const int inf = 0x3f3f3f3f;
int main()
{
   // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        int k=sqrt(n*1.0);
        for(int i=1;i<=k;i++)
        {
            ans+=(n/i);
            ans+=i*(n/i-n/(i+1));
        }
        if(n/k==k) ans-=k;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
```

