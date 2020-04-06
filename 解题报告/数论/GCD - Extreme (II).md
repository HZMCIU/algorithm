### [GCD - Extreme (II)](https://vjudge.net/problem/UVA-11426)

### 题意

求题目中给出的GCD公式

### 思路

将式子重新整理一下，可以转化为如下形式。令 $f(n)=\sum\limits_{i=1}^{n-1}gcd(i,n)​$ ,那么题目中的式子就可以转化为$G=\sum\limits_{i=1}^{n}f(i)​$ 。那么题目就转化为如何求解$f(n)​$了。

设满足$gcd(x,n)=i$的个数有$g(n,i)$个。$f(n)=\sum i*g(n,i)$ 

**满足$gcd(x,n)=i$和满足$gcd(\frac{x}{i},\frac{n}{i})=1$的个数是一致的**。那么，就转化为求欧拉函数$\phi(\frac{n}{i})$了 

最终$f(n)=\sum i*\phi(\frac{n}{i})​$

最后，枚举每个$i$，对应更新$f(k*i)=k*\phi(i)$ 。 

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e6;
const int inf=0x3f3f3f3f;
typedef long long ll;

ll phi[maxn];
ll res[maxn];
void init()
{
	for(int i=1;i<maxn;i++)
		phi[i]=i;
	for(int i=2;i<maxn;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<maxn;j+=i)
			{
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
	for(int i=2;i<maxn;i++)
	{
		for(int j=i;j<maxn;j+=i)
		{
			res[j]+=j/i*phi[i];
		}
	}
	for(int i=2;i<maxn;i++)
		res[i]+=res[i-1];
}
int main()
{
	freopen("in.txt","r",stdin);
	init();
	int n;
	while(~scanf("%d",&n)&&n)
		printf("%lld\n",res[n]);
	return 0;
}
```

