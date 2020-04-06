## [Bear and Prime Numbers](https://cn.vjudge.net/problem/CodeForces-385C)



### 思路

​	求解出每个素数能够整除$X_{n}$的个数，然后将区间内的所有素数累加，就能够得到答案。思想不算难，但是给我的能力只能实现最暴力的解法，就是对从区间中每挑出一个素数，就对整个$X_{n}$集合进行一次取模，找到能够被整除的个数，这样的解法想想都觉得肯定会超时。

​	网络上的解法。首先，由于素数的范围给定是$10^{12}$但是$X_{i}$的范围给定的是$10^{6}$， 因为素数的范围必定大于$X_{i}$所以只要对$10^{6}$内的素数进行筛选就可以了。使用的技巧主要有**素数筛**和**预处理求和**

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m,l,r;
const int N=10000002;
int dp[N];
int cnt[N];
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        cnt[t]++;//记录相应的次数出现的次数
    }
    for(int i=2;i<N;i++)//dp[i]:能够被i整除的个数,如果i不是素数那么dp[i]=-1
    {
        if(dp[i]>=0) 
        {
            dp[i]=cnt[i];
            for(int  j=2*i;j<N;j+=i) //使用了埃氏筛的思想,将所有能够被i整除的x的个数进行累加，并且将标记不是素数的点
            {
                dp[i]+=cnt[j];dp[j]=-1;
            }
        }
    }
    for(int  i=1;i<N;i++)//求解区间和，先将所有的值进行累加，dp[i]表示[0-i]所有值得累加和。接下来如果给定区间范围r,l,那么只需要计算dp[r]-do[l-1]就能够获得区间的累加和
    {
        dp[i]=(dp[i]<0?0:dp[i])+dp[i-1];
    }
    scanf("%d",&m);
    for(int  i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        if(r>=N) r=N-2;
        l>r?puts("0"):printf("%d\n",dp[r]-dp[l-1]);
    }
    return 0;
}

```



### 技巧

1. 素数筛的使用
2. 求解区间和

### 总结

​	学习算法，学会算法的思想，并且能够活用到具体的情景中才是最重要的。