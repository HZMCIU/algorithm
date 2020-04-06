### [Fliptile](https://cn.vjudge.net/problem/POJ-3279)

### 题意

有一个$n\times m$的矩阵，问需要翻转多少次才能将这个矩阵变成全为$0$的矩阵。每次翻转一个点，都会将相邻的上下左右的四点翻转。

### 思路

如果使用暴力搜索需要$O(2^{nm})$ ,程序的复杂度无法在时限算出结果。

通过观察可以发现，如果第一行的哪些点需要翻转已经确定，那么第二行要翻转的点也已经确定，因为如果第一行中$matrix[0][j]$含有$1$的点，那么第二行$matrix[1][j]$就必须进行翻转。以此类推，$2-n$ 翻转的状态也已经确定。

所以枚举第一行的翻转状态即可，复杂度为$O(2^n),n\in[0,15]$ 符合要求。

如何枚举第一行的状态，这里用了二进制枚举。

### 总结

通过观察，选取特殊的点（第一行的翻转状态确定，全部的翻转状态就确定），来降低复杂度。

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cstring>
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
const int maxn = 30;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int a[maxn][maxn];
int t[maxn][maxn];
int res[maxn][maxn];
int mov[maxn][maxn];
int n, m;
void flip(int i, int j)//翻转一个点
{
    t[i][j] ^= 1;
    if(i + 1 < n) t[i + 1][j] ^= 1;
    if(j + 1 < m) t[i][j + 1] ^= 1;
    if(i - 1 >= 0) t[i - 1][j] ^= 1;
    if(j - 1 >= 0) t[i][j - 1] ^= 1;
}
bool check()//检查最后一行是否全部为0
{
    for(int i = 0; i < m; i++) if(t[n - 1][i]) return false;
    return true;
}
int all_flip()//翻转2-n行
{
    int ret = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i - 1 >= 0 && t[i - 1][j])
            {
                ret++;
                flip(i, j);
                mov[i][j] = 1;
            }
        }
    }
    bool res = check();
    if(res) return ret;
    return inf;
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
    cin >> n >> m;
    int ans = inf;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int pos = 1 << n;
    for(int i = 0; i < pos; i++)
    {
        memcpy(t, a, sizeof(a));
        memset(mov, 0, sizeof(mov));
        int moved = 0;
        for(int j = 0; j < n; j++)
        {
            if(i >> (n - 1 - j) & 1)
            {
                flip(0, j);
                mov[0][j] = 1;//第一行已经翻转了，需要进行标记
                moved++;//第一行翻转的次数
                mov[0][j] = 1;
            }
        }
        int retd = all_flip();
        if(retd + moved < ans)
        {
            ans = retd;
            memcpy(res, mov, sizeof(mov));
        }
    }
    if(ans == inf)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
```



