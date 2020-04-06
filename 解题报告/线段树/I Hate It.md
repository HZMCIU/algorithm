### [I Hate It ](https://vjudge.net/problem/HDU-1754)

### 题意

求出区间内的最大值

### 思路

线段树模板题。向上更新。**pushup**

```cpp
#include <bits/stdc++.h>
//#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl;
#define wats(x) cout << (x) << " ";
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 2e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int tree[maxn];
void build(int rt, int l, int r)
{
    if(l == r)
    {
        cin >> tree[rt];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build((rt << 1) + 1, mid + 1, r);
    tree[rt] = max(tree[rt << 1], tree[(rt << 1) + 1]);
}
void update(int p, int sr, int l, int r, int rt)
{
    if(l == r)
    {
        tree[rt] = sr;
        return ;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(p, sr, l, mid, rt << 1);
    else update(p, sr, mid + 1, r, (rt << 1) + 1);
    tree[rt] = max(tree[rt << 1], tree[(rt << 1) + 1]);
}
int query(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
    {
        return tree[rt];
    }
    int ret = 0;
    int mid = (l + r) >> 1;
    if(L <= mid) ret = max(ret, query(rt << 1, l, mid, L, R));
    if(R > mid) ret = max(ret, query((rt << 1) + 1, mid + 1, r, L, R));
    return ret;
}
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif // SUBMIT
    int n, m;
    while(cin >> n >> m)
    {
        build(1, 1, n);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            char ch;
            cin >> ch >> a >> b;
            if(ch == 'Q')
                cout << query(1, 1, n, a, b) << endl;
            else if(ch == 'U')
                update(a, b, 1, n, 1);
        }
    }
}

```



