## [Balance](https://cn.vjudge.net/problem/POJ-1837)

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
int dp[30][150010];
/*
 * dp[i][j] 表示第i次挂物品的时候天平的平衡度
 * dp[i][j] = dp[i-1][j-c[p]*g[q]]
 */
int main()
{
    int c,g;
    int cc[100],gg[100];
    scanf("%d%d",&c,&g);
    for(int i=1;i<=c;i++) scanf("%d",&cc[i]);
    for(int i=1;i<=g;i++) scanf("%d",&gg[i]);
    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;
    for(int i=1;i<=g;i++) 
    {
        for(int j=-7500;j<=7500;j++)
        {
            if(dp[i-1][j+7500])
            {
                for(int k=1;k<=c;k++)
                {
                    dp[i][j+7500+gg[i]*cc[k]]+=dp[i-1][j+7500];
                }
            }
        }
    }
    printf("%d\n",dp[g][7500]);
    return 0;
}

```

