### [Harmony Analysis](https://vjudge.net/problem/CodeForces-610C)

### 思路

奇巧淫技。

首先对$2^k,k=1$  构造出$\begin{matrix}1&1\\1&-1\end{matrix}$ 然后对$2^k,k\geq2$ 将$2^k,k-1$ 的情况复制四份，其中右下的矩阵取反。例如$k=2$有$\begin{matrix}1&1&1&1\\1&-1&1&-1\\1&1&-1&-1\\1&-1&-1&1\end{matrix}$

然后直接模拟就可以了。

```cpp
//我的比较繁琐的方法
#include <bits/stdc++.h>
#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl;
#define wats(x) cout << (x) << " ";
#define __builtin_parity
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = (1<<10)+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int a[maxn][maxn];
void init()
{
    a[0][0]=a[0][1]=a[1][0]=1;
    a[1][1]=-1;
    for(int i=2;i<=9;i++)
    {
        int s=1<<(i-1);
        for(int j=0;j<s;j++)
        {
            for(int k=0;k<s;k++)
            {
                a[j][k+s]=a[j][k];
            }
        }
        for(int j=0;j<s;j++)
        {
            for(int k=0;k<s;k++)
            {
                a[j+s][k]=a[j][k];
            }
        }
        for(int j=0;j<s;j++)
        {
            for(int k=0;k<s;k++)
            {
                a[j+s][k+s]=-a[j][k];
            }
        }
    }
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
    int n;
    init();
    while(cin >> n)
    {
        n=1<<n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1) cout << "+";
                else cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}
```

[简洁明了](http://www.cnblogs.com/claireyuancy/p/6929655.html)

```cpp
//使用了位运算后的简洁的方法
#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "queue"
#include "stack"
#include "cmath"
#include "utility"
#include "map"
#include "set"
#include "vector"
#include "list"
#include "string"
#include "cstdlib"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n;
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	n = 1 << n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			printf("%c", __builtin_parity(i & j) ? '*' : '+');
		printf("\n");
	}
	return 0;
}
```

