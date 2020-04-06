## [Robberies](https://cn.vjudge.net/problem/HDU-2955#author=CCOA)



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
    int t;
    scanf("%d",&t);
    while(t--)
	{
		double p;int n,sum=0;
		scanf("%lf%d",&p,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%lf",&a[i],&b[i]);
			sum+=a[i];
		}
		//for(int i=1;i<=sum;i++) dp[i]=100.0;
		memset(dp,0,sizeof(dp));
		dp[0]=1.0;
		for(int i=0;i<n;i++)
		{
			for(int j=sum;j>=0;j--)
			{
				if(j>=a[i]) dp[j]=max(dp[j],dp[j-a[i]]*(1-b[i]));
			}
		}
		//for(int i=0;i<=sum;i++) printf("%f ",dp[i]);
		//puts("");
		for(int i=sum;i>=0;i--)
		{
			if(dp[i]>=(1-p))
			{
				printf("%d\n",i);
				break;
			}
		}
		//puts("0");
	}
	return 0;
}
```

