### [Stars](https://vjudge.net/problem/HDU-1541#author=0)

### 题意

给出n个坐标。定义一个坐标点的`level`值为在它左下角点的个数。求`level`为[0,n-1]点的个数。

### 思路

由于输入的数据，y的值已经按照降序排列了。所以问题转化为对于点i，有多少在点i之前的点的x值小于点i。

由于坐标的范围只有32000，所以可以直接将每个坐标保存在数组`bit[]`中。`bit[i]=1`表示存在`x=i`的点。然后使用树状数组来进行求解区间和，就能获得有多少点小于当前的x的值。

### 总结

刚刚看到这道题，无从下手，因为存在两个变量`x,y`。遇到这样的问题，可以尝试固定一个变量然后对另外一个变量进行求解。虽然输入中给定的y值是按照降序排列的。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 3e5 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
int n;
int bit[maxn];
int level[maxn];
int lowbit(int x)
{
    return x & -x;
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
int add(int x, int v)
{
    for(int i = x; i <= maxn; i += lowbit(i))
    {
        bit[i] += v;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        memset(bit, 0, sizeof(bit));
        memset(level, 0, sizeof(level));
        for(int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            level[sum(++x)] += 1;
            add(x, 1);
        }
        for(int i = 0; i < n; i++)
            printf("%d\n", level[i]);
    }
    return 0;
}
```

