###[Mysterious Bacteria](https://vjudge.net/problem/LightOJ-1220)

### 题意

$x=b^p$ 。给出$x$求最大的$p$

### 思路

根据唯一分解定理，$n=p_1^{a_1}p_2^{a_2}...p_n^{a_n}$

所谓最大的$x=b^p$中的最大的$p$就是$gcd(a_1,a_2,..a_n)$

此外，还要考虑一种特例。如果$x$是负数的化，那么$p$就一定不会是偶数。所以要把最后答案中所有的2因子去除。

这道题目没能AC。不知道为什么，但是不想在这里浪费时间。

### AC代码

```cpp
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 1000100
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
using namespace std;
int v[MAXN],prime[MAXN];
int k;
void isprime()
{
	int i,j;
	mem(v);
	v[1]=1;
	k=0;
	for(i=2;i<MAXN;i++)
	{
		if(v[i]==0)
		{
			prime[k++]=i;
			for(j=i*2;j<MAXN;j+=i)
			v[j]=1;
		}
	}
}
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
//////
	isprime();
	LL n;
	int t,i;
	int cas=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		int bz=0;
		if(n<0)
		n=-n,bz=1;
		int ans=0;
		for(i=0;prime[i]*prime[i]<=n&&i<k;i++)//就是这，因为表的限制，所以i不能大于等于k
		{
			if(n%prime[i]==0)
			{
				int cnt=0;
				while(n%prime[i]==0)
				{
					cnt++;
					n/=prime[i];
				}
				if(ans==0)
				ans=cnt;
				else
				ans=gcd(ans,cnt);
			}
			if(n==1)
			break;
		}
		if(n>1)
		ans=1;
		if(bz)
		{
			while(ans%2==0)
			ans/=2;
		}
		printf("Case %d: ",++cas);
		printf("%d\n",ans);
	}
	return 0;
}
```

### WA代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e7 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
ll prime[maxn / 5];
bool vis[maxn];
ll tot;

void getprime()
{
    for(ll i = 2; i < maxn; i++)
        if(!vis[i])
        {
            prime[tot++] = i;
            for(ll j = i * i; j < maxn; j += i)
                vis[j] = 1;
        }
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    freopen("in.txt", "r", stdin);
    getprime();
    int T;
    ll n;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++)
    {
        scanf("%I64d", &n);
        int f = 0;
        if(n < 0)
        {
            n = -n;
            f = 1;
        }
        ll t = n;
        ll cnt = 0;
        int ans = 0;
        for(ll j = 0; j < tot && prime[j]*prime[j] <= t; j++)
        {
            cnt = 0;
            while(t % prime[j] == 0)
                cnt++, t /= prime[j];
            ans = ans ? gcd(ans, cnt) : cnt;
            if(t == 1)
                break;
        }
        if(t > 1)
            ans = 1;
        if(f)
        {
            while(ans % 2 == 0)
                ans /= 2;
        }
        printf("Case %d: %d\n", cs, ans);
//        cout << "Case " << cs << ": "<< ans << endl;
    }
    return 0;
}

```

