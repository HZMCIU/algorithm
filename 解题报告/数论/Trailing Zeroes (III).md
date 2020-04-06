### [Trailing Zeroes (III)](https://vjudge.net/problem/LightOJ-1138#author=0)

### 题意

求满足$n!$后面有$q$个零的最小的$n$ ,

### 思路

刚开始的时候，一直再找规律，但是还是因为细节问题出错了。

这道题目的难点在于如何计算$n$之前所有的数含有的5的个数，如果搞清这个难点，直接二分就行了。

注意：有些数，比如625，是含有三个5因子的

```cpp
// n/5,计算所有含1个5因子的数，n/25,计算所有含两个5因子的数的个数，以此类推
ll count(ll x)
{
	ll ret=0;
	while(x)
	{
		ret+=x/5;
		x/=5;
	}
	return ret;
}
```

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
const int inf=0x3f3f3f3f;
typedef long long ll;

ll count(ll x)
{
	ll ret=0;
	while(x)
	{
		ret+=x/5;
		x/=5;
	}
	return ret;
}

ll q;

ll bsearch()
{
	ll l=0,r=500000000;
	while(l<=r)	
	{
		ll mid=(l+r)>>1;
		if(count(mid)<q)
			l=mid+1;
		else 
			r=mid-1;
	}
	if(count(l)==q)
		return l;
	return 0;
}


int main()
{
	freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&q);
		int ans=bsearch();
		if(ans)
		{
			printf("Case %d: %d\n",i,ans);
		}
		else
		{
			printf("Case %d: impossible\n",i);
		}
	}
	return 0;
}
```

