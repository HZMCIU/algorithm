### [How Many Answers Are Wrong](https://cn.vjudge.net/problem/HDU-3038)

### 题意

有N个数。给出m条信息，$A_i,B_i,S_i$。表示$[A_i,B_i]$的和为$S_i$。问有多少条记录和前面的记录冲突。

### 思路

将输入的区间$[u,v]$改写成$(u-1,v]$ 。

`val[i]`表示`i`节点到其父节点的距离。如果$u,v$已经存在一个连通分量，并且我们又给出他们的和，那么我们就可以计算u与根，v与根的和值来计算$[u,v]$的和值。比较和信息中给出的和值是否相同。

###AC代码

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;
int par[maxn];
int val[maxn];
int n, m;
int find(int x)
{
    if(par[x] == -1)
        return x;
    int temp = find(par[x]);
    val[x] += val[par[x]];//进行路径压缩，同时也将x到根上的路径的距离加到一起
    return par[x] = temp;
}
int unite(int a, int b, int sum)
{
    int fa = find(a);
    int fb = find(b);
    if(fa != fb)
    {
        if(fa > fb)
        {
            par[fa] = fb;
            val[fa] = abs(val[a] + sum - val[b]);
        }
        else if(fa < fb)
        {
            par[fb] = fa;
            val[fb] = abs(val[a] + sum - val[b]);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d", &n, &m))
    {
        memset(val, 0, sizeof(val));
        memset(par, -1, sizeof(par));
        int a, b, c;
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            a--;
            int fa = find(a);
            int fb = find(b);
            if(fa == fb)
            {
                if(abs(val[a] - val[b]) != c)
                    ans++;
            }
            else
            {
                unite(a, b, c);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

