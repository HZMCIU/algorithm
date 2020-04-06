### [Mayor's posters](https://vjudge.net/problem/POJ-2528#author=swust20141567)

### 题意

贴$n$张海报，求贴完所有的海报后还剩余几张海报可见。

### 思路

由常识可知，上面的海报会将下面的海报掩盖。所以我们**从上往下**操作，使用线段树来维护每块瓷砖是否被贴了海报。但是瓷砖的数量大于$1e7$ 无法直接使用线段树来维护，但是海报的数量只有$1e4$ 张，所以将海报的左右端点进行**离散化处理**将其映射到一个较小的区间内。

由常识可知，如果一块瓷砖被最上方的海报占据，那么下方所有的海报无法被看见。结合这个常识，我们从上往下贴海报，如果一张海报能够占据没有被贴过海报的瓷砖的话，那么这张海报就可以被发现。

### 总结

刚开始想这道题目的时候，感觉无从下手，想不到一个合理的解决方案。想过使用线段树来维护区间的海报数，以及每块瓷砖是否被占用。但是对这些，我都无法想到一个合理的方法来更新线段树。看了题解后，原来别人是使用**逆向**的方法，从上往下，的确很巧妙，也很简洁。以后做题要往**逆向**这个方向考虑。

### 代码

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl
#define wats(x) cout << (x) << " "
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
struct
{
    int l, r;
} post[20000];
struct
{
    int l, r;
    bool covered;
} segtree[maxn];;
int hsh[maxn * 10];
int x[20000];
void build (int rt, int l, int r)
{
    segtree[rt].l = l;
    segtree[rt].r = r;
    segtree[rt].covered = false;

    if (l == r)
        return;

    int mid = (l + r) >> 1;
    build (rt << 1, l, mid);
    build (rt << 1 | 1, mid + 1, r);
}
bool Post (int rt, int l, int r)
{
    if (segtree[rt].covered)
        return false;

    if (l == segtree[rt].l && r == segtree[rt].r)
    {
        segtree[rt].covered = true;
        return true;
    }

    int mid = (segtree[rt].l + segtree[rt].r) >> 1;
    bool result;

    if (r <= mid)
        result = Post (rt << 1, l, r);
    else if (l > mid)
        result = Post (rt << 1 | 1, l, r);
    else
    {
        bool r1 = Post (rt << 1, l, mid);
        bool r2 = Post (rt << 1 | 1, mid + 1, r);
        result = r1 || r2;
    }

    if (segtree[rt << 1].covered && segtree[rt << 1 | 1].covered)
        segtree[rt].covered = true;

    return result;
}
int main()
{
#ifndef SUBMIT
    freopen ("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
    int T;
    int n;
    int cnt;
    int ans;
    scanf ("%d", &T);

    while (T--)
    {
        cnt = 0;
        ans = 0;
        scanf ("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d%d", &post[i].l, &post[i].r);
            x[cnt++] = post[i].l;
            x[cnt++] = post[i].r;
        }

        sort (x, x + cnt);
        cnt = unique (x, x + cnt) - x;//去除重复的点

        for (int i = 0; i < cnt; i++)
        {
            hsh[x[i]] = i;//将原来的左右端点映射为逐个递增的点
        }

        build (1, 0, cnt - 1);

        for (int i = n - 1; i >= 0; i--)
        {
            if (Post (1, hsh[post[i].l], hsh[post[i].r]) )//如果能占据瓷砖
                ans++;
        }

        printf ("%d\n", ans);
    }

    return 0;
}

```

