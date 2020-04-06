### [Hard problem ](http://codeforces.com/group/1EzrFFyOc0/contest/706/problem/C)

### 题意

给出$n$个字符串，翻转第$i$个字符串需要$c[i]$能量。问将这$n$个字符串排成字典序，最少需要消耗多少能量。

### 思路

$dp[i][j]=min(dp[i][j],dp[i-1][0]+j*c[i])$

还不不大懂，这个方程。

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
ll dp[maxn][2];
int c[maxn];
string s[maxn];
string t[maxn];
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
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> c[i];
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            t[i] = s[i];
            reverse(t[i].begin(), t[i].end());
        }
        memset(dp, inf, sizeof(dp));
        dp[0][0] = 0, dp[0][1] = c[0];
        for(int i = 1; i < n; i++)
        {
            if(s[i] >= s[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            if(s[i] >= t[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            if(t[i] >= s[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
            if(t[i] >= t[i - 1])dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
        if(dp[n - 1][0] == inf && dp[n - 1][1] == inf)
            cout << -1 << endl;
        else
            cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}

```



