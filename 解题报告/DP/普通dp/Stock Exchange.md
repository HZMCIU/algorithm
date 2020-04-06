## [Stock Exchange](https://cn.vjudge.net/problem/POJ-3903)

#### 思路

最长上升子序列

#####[解析](https://www.cnblogs.com/frankchenfu/p/7107019.html)

#### 二分算法

```cpp
//模拟一个栈，每次读入一个数，如果这个数比栈顶元素大的话，这个元素入栈。如果这个数小于栈顶的话，用这个数更新，栈里面比这个数大的话用这个数更新栈里面的数，这样更加有“潜力”
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int a[100010];
int dp[100010];
const int INF = INT_MAX;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        fill(dp,dp+n,INF);
        for(int i=0;i<n;i++) *lower_bound(dp,dp+n,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    
    return 0;
}

```

#### 朴素算法

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int dp[100000];
int a[100000];

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int _max=-0x3f3f3f3f;
    for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				dp[i]=dp[j]+1;
				_max=max(dp[i],_max);
			}
		}
	}
	printf("%d\n",_max);
    return 0;
}

```

