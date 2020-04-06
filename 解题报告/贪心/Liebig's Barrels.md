### [Liebig's Barrels ](http://codeforces.com/contest/985/problem/C)

### 题意

1. 给出$n*k$个数，把这些数分为$n$份，每份$k$个数，使得每份的最小值差距不大于$l$，求最小值之和的最大值。
2. 给出$n*k$个木板，使用k个木板搭成一个木桶，木桶的容量由最短的木板决定，并且所有各个木桶的容量差距不大于l。求n个木桶容量的最大值。

### 思路

1. 首先判断是否有可能组成组成差距不大于l的木桶。即，是否存在n-1个与a[1]差距小于等于l的数。

```cpp
sort(a, a + m);
int pos = upper_bound(a, a + m, a[0] + l) - a;
if(pos < n)
{
	cout << 0 << endl;
	continue;
}
```

2. 如果存在解。每个木桶的容量，即k个木板的最小值，一定位于$a[0,pos-1]$。

   把$a[0-pos-1]$分为两个部分，$a[0,t],a[t+1,pos-1]$。显而易见，$a[0,t]$用于组成 $n_1$ 个木桶

   $a[t+1,pos-1]$用于和$a[pos,m-1]$ 组成$n_2$个木桶。其中$n=n_1+n_2$

```cpp
int cur = 0;
for(int i = 0; i < n; i++)
{
	ans += a[cur++];
	for(int j = 0; j < k - 1; j++)
	{
		if(pos - cur > n - i - 1) cur++; //如果a[0,pos]中剩余的足够用来和后面的长木板组合，就把当前的木板用来组成小水桶
		else break;
	}
}
```

### 总结

首先去除无解情况，然后就比较好计算得到结果了

### 代码

```cpp
#include <bits/stdc++.h>
#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl;
#define wats(x) cout << (x) << " ";
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
ll a[maxn];
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // SUBMIT
    ll n, k, l;
    while(cin >> n >> k >> l)
    {
        ll m = n * k;
        for(int i = 0; i < m; i++)
            cin >> a[i];
        sort(a, a + m);
        int pos = upper_bound(a, a + m, a[0] + l) - a;
        if(pos < n)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            ans += a[cur++];
            for(int j = 0; j < k - 1; j++)
            {
                if(pos - cur > n - i - 1)
                {
                    cur++;
                }
                else break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```

