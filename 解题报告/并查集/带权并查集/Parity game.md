### [Parity game](https://vjudge.net/problem/POJ-1733)

### 题意

中文翻译

### 思路

根据已经存在的关系来判断现在给出的关系是否正确。

使用`val[x]`来代表x和父节点`par[x]`的关系。0-表示[x,root[x]]中有偶数，1-表示[x,root[x]]有奇数个。

通过map来进行离散化。

### AC代码

```cpp
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4;
int par[maxn];
int val[maxn];
map<int, int> mp;
int cnt = 0;
int insert(int x)
{
    if(mp.find(x) == mp.end())
        mp[x] = ++cnt;
    return mp[x];
}
int find(int x)
{
    if(par[x] == -1)
        return x;
    int t = par[x];
    par[x] = find(par[x]);
    //val[t]代表节点par[x]和root之间的关系
    val[x] = (val[x] + val[t]) % 2;
    return par[x];
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        mp.clear();
        memset(par, -1, sizeof(par));
        memset(val, 0, sizeof(val));
        cnt = 0;
        int ans = -1;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            char str[30];
            int re;
            scanf("%d%d%s", &u, &v, str);
            if(ans != -1)
                continue;
            if(str[0] == 'e')
                re = 0;
            else if(str[0] == 'o')
                re = 1;
            u = insert(u - 1);
            v = insert(v);
            int fu = find(u);
            int fv = find(v);
            if(fv == fu)
            {
                if((val[u]^val[v]) != re)
                    ans = i;
            }
            else
            {
                par[fu] = fv;
                val[fu] = (val[v] + val[u] + re) % 2;
            }
        }
        if(ans != -1)
            printf("%d\n", ans);
        else
            printf("%d\n", m);
    }
    return 0;
}
```

