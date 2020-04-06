## [Staircases](https://cn.vjudge.net/problem/URAL-1017#author=0)

[题解](http://blog.csdn.net/u011355420/article/details/9363907)

仍然有待加深理解

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long dp[900][901];
int main()
{
	int n;
	scanf("%d",&n);
	dp[0][0]=0;
	for(int i=1;i<=n;i++) dp[i][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i<j) dp[i][j]=dp[i][i];
			else if(i==j) dp[i][j]=dp[i][j-1]+1;
			else dp[i][j]=dp[i][j-1]+dp[i-j][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=dp[n][i];
	printf("%I64d\n",dp[n][n]-1);
	return 0;
}

```

