### [Pythagorean Triples ](http://codeforces.com/group/1EzrFFyOc0/contest/707/problem/C)

### 题意

给出直角三角形的一条边（直角边或者斜边），求出另外两条边。

### 思路

假设给出的边是*直角边* $a$, 那么根据勾股定理有$a^2+b^2=c^2$。

移项可得$a^2=c^2-b^2=(c-b)*(c+b)$ 。

**赋值**

$a\%2==1$

$\begin{cases}c-b=1\\c+b=a^2\end{cases}$

$a\%2==0$

$\begin{cases}c-b=2\\c+b=\frac{a^2}{2}\end{cases}$

解方程组可得

$a\%2==1$

$\begin{cases}c=\frac{a^2+1}{2}\\b=\frac{a^2-1}{2}\end{cases}$

$a\%2==0$

$\begin{cases}c=\frac{a^2}{4}+1\\c=\frac{a^2}{4}-1\end{cases}$

此处保证$a^2$能够被4整除，因为作为一个平方数，既然能够被2整除，那么他就一定包含了两个2的因子，能够被4整除。

$n==1,n==2$ 以上方程组无解。

### 总结

勇敢的对方程组赋值，求出解。

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
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

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
    ll n;
    while(cin >> n)
    {
        if(n==1||n==2)
        {
            cout << "-1" << endl;
        }
        else if(n&1)
        {
            cout << (n*n+1)/2 << " " << (n*n-1)/2 << endl;
        }
        else
        {
            cout << (n*n)/4+1 << " " << (n*n)/4-1 <<endl;
        }
    }
    return 0;
}
```







