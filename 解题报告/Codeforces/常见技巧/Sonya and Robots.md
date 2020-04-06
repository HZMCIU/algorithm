## [Sonya and Robots](http://codeforces.com/contest/1004/problem/C)

**题意**

给出一列数字，问有多少中不同且不重复的配对方式。如(a,b)，要保证a的位置在b的左边。

**思路 **

使用一个数组，求出p+1...n有多少种不重复的数字。当$a_i$ 第一次出现时,$dp_i=dp_{i+1}+1$ 。

如何判断一个数是第一次出现呢？由于$a_i$的数值较小，使用一个布尔数组`bool contain[]` 来判断，出现`i` 则`contain[i]=1` 。

**总结**

1. 使用布尔数组判重
2. 使用数组来记录到当前位置一共有多少个不重复的数字

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100010];  //记录数组
int b[100010]; //计算到当前位置一共有多少个不同的数字
bool contain[100010]; //布尔数组，用来判重
int main()
{
    int n;
    scanf("%d",&n);
    memset(con,0,sizeof(con));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(!con[a[i]]) b[i]=b[i+1]+1;
        else b[i]=b[i+1];
        contain[a[i]]=1;
    }

    memset(contain,0,sizeof(contain));
    long long ans=0;
    for(int i=0;i<n-1;i++)
    {
        //从左边数起，如果这个数在之前没有出现过，那么ans加上这个数右边一共有多少个不重复的数字的个数。
        //如果这个数重复出现了，那么这个数的所有配对一定在之前相同的数里被计算过了
        if(!contain[a[i]])
        {
            ans+=b[i+1];
        }
        contain[a[i]]=1;
    }

    printf("%I64d\n",ans);
    return 0;
}
```

