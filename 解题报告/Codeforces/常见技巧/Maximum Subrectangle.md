### [ Maximum Subrectangle](http://codeforces.com/contest/1060/problem/C)

### 题意

给出两列数组`a`,`b`。矩阵$c_{ij}=a_i\times b_j$ 。求子矩阵，确保子矩阵的所有的元素的和不大于$x$。求出矩阵长度$l$和宽度$w$的乘积$s$的最大值。$max(s)=max(l*w)$

### 思路

引入一个数组，`min_continous_b` ，`min_continous_b[i]`，**表示数组$b$连续长度为$i$的和的最小值**。

例如，`b={3,4,2,2};min_contious_b={0,2,4,8,11}` 长度为3的连续和的最小值为8。

如果矩阵$c$由矩阵$a$,$b$构成,$c_{ij}=a_i\times b_j$。那么$\sum c_{ij}=\sum a_i\times\sum b_j$ .

例如，`a={1,2,3},b={4,5,6}` 那么$\sum c=(1+2+3)\times(4+5+6)=6*15=90=(4+5+6+8+10+12+12+15+18)=90$

**所以求解子矩阵和最小值转化为求解数组两段子序列和的最小值。**

$O(n^2)$ 求出`min_continous_a`。

然后枚举$a,b$所有的长度即可求出s的最大值。

```cpp
for(int i=0;i<n;i++)
{
	int sum=0;
	for(int j=i;j<n;j++)
	{
		sum+=a[j];
		min_continous_a[j-i+1]=min(min_continous_a[j-i+1],sum);
	}
}
```

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+100;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll a[maxn];
ll b[maxn];
ll ma[maxn];
ll mb[maxn];
ll n,m;
ll x;
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%I64d%I64d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        for(int j=0;j<m;j++)
            scanf("%I64d",&b[j]);
        scanf("%I64d",&x);
        for(int i=1;i<maxn;i++)
            ma[i]=mb[i]=inf;
        for(int i=0;i<n;i++)
        {
            ll sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=a[j];
                ma[j-i+1]=min(ma[j-i+1],sum);
            }
        }
        for(int i=0;i<m;i++)
        {
            ll sum=0;
            for(int j=i;j<m;j++)
            {
                sum+=b[j];
                mb[j-i+1]=min(mb[j-i+1],sum);
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(ll(ma[i]*mb[j])<=x)
                    ans=max(ans,i*j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

