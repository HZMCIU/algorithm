### [Apple Tree](https://vjudge.net/problem/POJ-3321)

### 题意

给出一棵树，树上有许多苹果。每次操作能够改变采摘下一个苹果或者重新长出一个苹果。问某个子树所有苹果的数量。

### 思路

树状数组。

由于树状数组处理的是线性的结构，但是题目中给出的树形结构。所以要进行预处理。首先求出树的**DFS序**，使用两个数组`start`和`end`来记录遍历节点x前的序号和遍历节点x后的序号。那么他们的差值`end[x]-start[x]`就是x下的子树了，[1,start[x]]表示，在一棵树中，节点x之上的节点。

这里使用的主要技巧就是使用DFS序，来将树形结构转化为线性结构。

### 总结

**树状数组只能维护线性结构，DFS序能够将树形结构转化为线性结构。**

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
int n;
vector<vector<int> > tree(maxn);
int start[maxn];
int _end[maxn];
int f[maxn];
int stmp=1;
int bit[maxn];
int dfs(int x)
{
    start[x]=stmp;
    for(int i=0;i<tree[x].size();i++)
    {
        stmp++;
        dfs(tree[x][i]);
    }
    _end[x]=stmp;
}
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
    for(int i = x; i <= n; i += lowbit(i))
    {
        bit[i] += v;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        add(start[i],1);
        f[i]=1;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        char op;
        int d;
        scanf(" %c%d",&op,&d);
        if(op=='C')
        {
            add(start[d],(f[d]^1)-f[d]);
            f[d]^=1;
        }
        else
            printf("%d\n",sum(_end[d])-sum(start[d]-1));
    }
    return 0;
}
```

