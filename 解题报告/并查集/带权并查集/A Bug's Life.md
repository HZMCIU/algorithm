### [A Bug's Life](https://cn.vjudge.net/problem/POJ-2492)

### 题意

有n只虫子。给出m条关系，表示两只正在交往的虫子，是否存在同性恋虫子。

### 思路

并查集来区分两个不同的集合。

`val[x]`，表示x和父节点par[x]的关系，0表示相同，1表示不同。

在`find`操作时将节点x连接到根节点上的时候顺便更新`val[x]`的值

```cpp
//val[t]--x的父节点和根节点的关系
//val[x]--x和父节点的关系
//更新之后就变成了x和根节点的关系
val[x] = (val[t] + val[x]) % 2;

```

`unite(a,b)` ，更新a所属集合和b所属集合之间的关系

```cpp
//val[x]--x和根节点的关系
//val[y]--y和根节点的关系
//这两个所属的集合是不同的集合
//如果x和根节点相同，y和根节点相同，那么x所属集合和y所属集合的关系相反
//如果x和根节点关系相反，y和根节点关系相同，那么x所属的集合和y所属的集合的关系相同
val[tx] = (val[y] + val[x] + 1) % 2;
```

### AC代码

```cpp
#include <cstdio>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;
int par[maxn];
int val[maxn];
void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        par[i] = i;
        val[i] = 0;
    }
}
int find(int x)
{
    if(par[x] == x)
        return x;
    int t = par[x];
    par[x] = find(par[x]);
    //val[t]--x的父节点和根节点的关系
    //val[x]--x和父节点的关系
    //更新之后就变成了x和根节点的关系
    val[x] = (val[t] + val[x]) % 2;
    return par[x];
}
int unite(int x, int y)
{
    int tx = find(x);
    int ty = find(y);
    par[tx] = ty;
    //val[x]--x和根节点的关系
    //val[y]--y和根节点的关系
    //这两个所属的集合是不同的集合
    //如果x和根节点相同，y和根节点相同，那么x所属集合和y所属集合的关系相反
    //如果x和根节点关系相反，y和根节点关系相同，那么x所属的集合和y所属的集合的关系相同
    val[tx] = (val[y] + val[x] + 1) % 2;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++)
    {
        int n, m;
        bool ans = true;
        scanf("%d%d", &n, &m);
        init(n + 10);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(find(a) == find(b))
            {
                if(val[a] == val[b])
                    ans = false;
            }
            else
            {
                unite(a, b);
            }
        }
        if(!ans)
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", cs);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", cs);
    }
    return 0;
}
```

