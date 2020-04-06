### [A Simple Problem with Integers](https://vjudge.net/problem/POJ-3468)

### 题意

更改、查询区间内的和。

### 思路

线段树模板题，使用**延迟查询**。

### 注意点

1. `cin >> ch;` 使用`cin`来读入字符，避免出现读入换行符。
2. 查询过程种线段树向下更新条件
   1. `mid >= r` 向下更新左子树
   2. `mid < l` 向下更新右子树
   3. 但是`mid > r` 更新左子树，`mid <= l` 更新右子树会出错。（雾）
3. 这个版本的线段树的思路是，把要查询的区间$[a,b]​$ 递归分摊到各个节点上，如果分摊的节点的左右区间`segtree[rt].l` `segtree[rt].r` 等于目前递归函数查询的左右端点$[l,r]​$，那么返回$inc*(l-r)+sum​$ 。更新的函数也是一样的原理。**lazy标记的另一种实现**

```cpp
#include <iostream>
#include <cstdio>
#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl
#define wats(x) cout << (x) << " "
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
struct
{
    int l, r;
    ll sum;
    ll inc;
} segtree[maxn];
int arr[maxn];
void build (int rt, int l, int r)
{
    segtree[rt].l = l;
    segtree[rt].r = r;
    segtree[rt].inc = 0;

    if (l == r)
    {
        segtree[rt].sum = arr[l];
        return ;
    }

    int mid = (l + r) >> 1;
    build (rt << 1, l, mid);
    build (rt << 1 | 1, mid + 1, r);
    segtree[rt].sum = segtree[rt << 1].sum + segtree[rt << 1 | 1].sum;
}

void add (int rt, int l, int r, ll c)
{
    if (l == segtree[rt].l && segtree[rt].r == r)//正好分摊线段树节点上
    {
        segtree[rt].inc += c; 
        return;
    }

    segtree[rt].sum += (r - l + 1) * c;//此线段树节点是根节点，包含了[l,r]区间，所以要加上区间和
    int mid = (segtree[rt].l + segtree[rt].r) >> 1;

    if (r <= mid)//要查询的区间正好在线段树的左半部分
        add (rt << 1, l, r, c);
    else if (l > mid)//要查村的区间正好在线段树的右半部分
        add (rt << 1 | 1, l, r, c);
    else//查村的区间横跨左右
    {
        add (rt << 1, l, mid, c);
        add (rt << 1 | 1, mid + 1, r, c);
    }
}

ll query (int rt, int l, int r)
{
    if (l == segtree[rt].l && r == segtree[rt].r)
    {
        return segtree[rt].sum + segtree[rt].inc * (segtree[rt].r - segtree[rt].l + 1);
    }

    segtree[rt].sum += segtree[rt].inc * (segtree[rt].r - segtree[rt].l + 1);//将lazy的和加到sum中
    int mid = (segtree[rt].l + segtree[rt].r) >> 1;
    add (rt << 1, segtree[rt].l, mid, segtree[rt].inc);//更新左子树的sum
    add (rt << 1 | 1, mid + 1, segtree[rt].r, segtree[rt].inc);//更新右子树的sum
    segtree[rt].inc = 0;//lazy置零

    if (mid < l)
        return query (rt << 1 | 1, l, r);
    else if (mid >= r)
        return query (rt << 1, l, r);
    else
    {
        return query (rt << 1, l, mid) + query (rt << 1 | 1, mid + 1, r);
    }
}

int main()
{
#ifndef SUBMIT
    freopen ("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
    int n, q;
    int i;
    int a, b, c;
    char ch;

    while (~scanf ("%d%d", &n, &q) )
    {
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &arr[i]);
        }

        build (1, 1, n);

        for (i = 0; i < q; i++)
        {
            cin >> ch;

            if (ch == 'Q')
            {
                scanf ("%d%d", &a, &b);
                printf ("%I64d\n", query (1, a, b) );
            }
            else if (ch == 'C')
            {
                scanf ("%d%d%d", &a, &b, &c);
                add (1, a, b, c);
            }
        }
    }

    return 0;
}

```



