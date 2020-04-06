## [The Triangle](https://cn.vjudge.net/problem/POJ-1163#author=0)

#### 记忆化搜索

```CPP
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int mz[110][110];
int dp[120][120];
int n;


int dfs(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==n) return dp[i][j]=mz[i][j];
	int t=max(dfs(i+1,j),dfs(i+1,j+1))+mz[i][j];
	dp[i][j]=t;
}


int main()
{

	while(~scanf("%d",&n))
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				scanf("%d",&mz[i][j]);
			}
		}
		dfs(1,1);
		printf("%d\n",dp[1][1]);
	}
	return 0;
}

```

