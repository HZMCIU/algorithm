## [Bookshelf 2](https://cn.vjudge.net/problem/POJ-3628)

#### 思路

​	背包问题的中的`dp[i][j]`  是指第i次总重量不超出j的最大价值。在这道题目中，`dp[i][j]` 则代表了第i次选取奶牛，总的高度不超过j的最大高度。这道题目中，只有两个因子，高度和次数；然而在经典的背包问题中，有三个因子，次数，重量，价值；在这个问题中，价值因子被高度取代了，也就是物品的重量和价值是一样的。

​	这道题目的意思是求出奶牛高度总和大于b的最小值和b的差距。刚开始没有想到这事一道01背包问题，重新定义了一个状态`dp[i][j]`表示第i次选取奶牛，表示和j相差最小的值，`dp[0][j]=j`。但是没有找到状态转移方程。后来换了一个角度想了想，题目是要我们求解总和大于等于b的最小值，那么也就是说求解sum-b的最大值（sum是指所有奶牛的高度），然后就是对背包总重量为sum-b的进行背包操作。找到最大的值max，那么最小值就是`sum-max`了，然而wa了。

​	参考了网上的思路。原来就是简单的背包问题。`dp[n][j]` 就是表示所有牛都选取完成后，最大不超过j的最大值，又因为奶牛的总高度sum一定大于b，所以只需要在最后的状态中找到，最小大于b的值就可以了。辛酸。

WA代码

```cpp
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int dp[26][1000010];
int h[3500];
int main()
{
    int n,b,sum=0;
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]),sum+=h[i];
    dp[0][0]=1;  //其实状态
    for(int i=1;i<=b;i++) dp[0][i]=0;
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<=sum-b;j++)
        {
            if(h[i]<=j)
                dp[i][j]|=dp[i-1][j-h[i]];
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    int _max=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum-b;j++)
        {
            if(dp[i][j])
            _max=max(j,_max) ;
        }
    }
    if(sum-b==0) puts("0");//没有空闲位置
    else if(_max==0) printf("%d\n",sum-b);//重量为sum-b的背包太小了
    else printf("%d\n",abs(b-(sum-_max)));
    return 0;
}
```

AC代码

```cpp
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int dp[26][1000010];
int h[3500];
int main()
{
    int n,b,sum=0;
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]),sum+=h[i];
    for(int i=1;i<=b;i++) dp[0][i]=0;
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(h[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i]]+h[i]);
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    for(i=sum;dp[n][i]>=b;i--) ;
    printf("%d\n",abs(b-dp[n][i+1]));//在最后的状态中选取大于等于b的最小值
    return 0;
}


```

