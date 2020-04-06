### [Minimum Inversion Number](https://vjudge.net/problem/HDU-1394)

### 题意

给出一个数组，将头部的元素放置到尾部，问这个过程中逆序数最小为多少。

### 思路

首先求出原始的序列的逆序数。在移动过程中可以发现逆序数的变化量为$N-a[0]-（a[0]-1)$ 。因为$a[0]$如果在头部，那么小于a[0]的元素个数有a[0]-1个，大于a[0]的元素个数有n-a[0]个。经过移动，原来a[0]-1个逆序对消失，但是重新生成了n-a[0]新的逆序对。模拟这个过程，然后求出最小值即可。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5e3 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
int bit[maxn + 10];//bit[i]表示数字i出现的次数
int a[maxn + 10];
int lowbit(int x)
{
    return x & -x;
}
int add(int x, int v)
{
    for(int i = x; i < maxn; i += lowbit(i))
    {
        bit[i] += v;
    }
}
int sum(int x)
{
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        ret += bit[i];
    }
    return ret;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n))
    {
        memset(bit, 0, sizeof(bit));
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i]++;
            add(a[i], 1);
            //求出有多少数字小于a[i]
            ans += i - sum(a[i]);
        }
        ll tmp = ans;
        //模拟，求出最小值
        for(int i = 1; i <= n; i++)
        {
            tmp = tmp - (a[i] - 1) + n - a[i];
            ans = min(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
```

