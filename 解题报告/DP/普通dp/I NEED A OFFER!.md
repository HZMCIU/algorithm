## [I NEED A OFFER!](https://cn.vjudge.net/problem/HDU-1203)

#### 思路 

题目求解最大可能收到offer的概率，将最大可能收到的概率转化为最小不能收到offer的概率。

`dp[i]` 表示总金额为i最小不会被拒绝的概率。`dp[i]=min(dp[i],dp[i-a[j]])*(1-b[j])`

样例：

选择 `4 0.2  5 0.3` 这两个学校，那么最小被拒绝的概率为  `(1-0.2)*(1-0.7)=0.56` 那么最大收到offer的概率就是`1-0.56=0.44`

```cpp
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;


int a[1000000];
double b[1000000];
double dp[1000000];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
	{
        if(n==0&&m==0) break;
        for(int i=0;i<m;i++) scanf("%d%lf",&a[i],&b[i]);
        for(int i=0;i<=n;i++) dp[i]=100.00;
        for(int i=0;i<m;i++)
		{
			for(int j=n;j>=0;j--)
			{
                if(j>=a[i]) dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
			}
			//for(int i=0;i<=n;i++) printf("%f ",dp[i]);
			//puts("");
		}

		double res=100.0-dp[n];
		printf("%.1f%%\n",res);
	}
	return 0;
}

```

