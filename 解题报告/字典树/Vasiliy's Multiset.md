### [Vasiliy's Multiset ](http://codeforces.com/group/1EzrFFyOc0/contest/706/problem/D)

### 题意

给出三个操作

1. “+ x”，向集合中加入$x$
2. “-x”，集合中删除$x$
3. “？ x” ，询问$x$和集合中元素的最大异或值

### 思路

​	字典树。使用元素高位到低位的二进制数值来建立字典树，并向字典树节点中添加`cnt`来模拟删除操作。query时，从字典树的高位向低位询问，查看是否存在一条边和当前二进制值相反的，如果有，沿着那条边往下走，如果没有，任意往下走。

​	默认集合中已经存在了$0$，所以要先对$0$建立建立边。否则会`RE`。

### 总结

​	这道题目，使用了类似字典树的结构。利用了字典树一次查询就得到所有前缀的情况的性质。使得能够在$O(logn)$的复杂度内算出最大异或值。勉强的说，这道题还有一点点贪心，体现在从高位到低位建边，因为这样能够保证出来的异或值最大。询问时优先选择不同的二进制值。

```cpp
#include <bits/stdc++.h>
#define SUBMIT
#define gcd  __gcd
#define watl(x) cout << (x) << endl
#define wats(x) cout << (x) << " "
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
    node *next[2];
    int cnt;
}*root;
node *build()
{
    node*k = new(node);
    memset(k->next, 0, sizeof(k->next));
    k->cnt = 1;
    return k;
}
void init()
{
    node *r = root;
    for(int i = 31; i >= 0; i--)
    {
        r->next[0] = build();
        r = r->next[0];
    }
}
void insert(int n)
{
    node *r = root;
    for(int i = 31; i >= 0; i--)
    {
        int t = (n >> i & 1);
        if(r->next[t] == nullptr)
        {
            r->next[t] = build();
        }
        else r->next[t]->cnt++;
        r = r->next[t];
    }
}
void erase(int n)
{
    node *r = root;
    for(int i = 31; i >= 0; i--)
    {
        int t = (n >> i & 1);
        r = r->next[t];
        r->cnt--;
    }
}
int query(int n)
{
    node *r = root;
    int ret = 0;
    for(int i = 31; i >= 0; i--)
    {
        bool t = (n >> i & 1);
        if(r->next[!t] != nullptr && r->next[!t]->cnt > 0)
        {
            r = r->next[!t];
            ret += (1 << i);
        }
        else
        {
            r = r->next[t];
        }
    }
    return ret;
}
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // SUBMIT
    int q;
    while(cin >> q)
    {
        root = build();
        init();
        char op;
        int n;
        for(int i = 0; i < q; i++)
        {
            cin >> op >> n;
            if(op == '+')
                insert(n);
            else if(op == '-')
                erase(n);
            else if(op == '?')
                cout << query(n) << endl;
        }
    }
    return 0;
}

```

