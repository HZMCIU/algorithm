### [Warrior and Archer](https://vjudge.net/problem/CodeForces-595C)

#### 题意

有两个人进行博弈，抹去坐标上的点。先手希望距离尽可能小，后手希望距离尽可能大。问最小的距离为多少。

#### 思路

假设最后存在的两个点的序号为l,r。那么有$l-r\leq \frac{n}{2}$ 。因为先手希望距离尽可能小，那么他就抹去$l,r$之外的坐标，那么他所抹去的$\frac{n}{2}-1$坐标都位于这一区间之外。同理后手希望距离尽可能大，那么他所抹去的坐标都位于区间之内。所以可以得出$l-r=\frac{n}{2}$。 **求解$a_{i},a_{i+\frac{n}{2}}$之间的最短距离即可**

```cpp
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
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int a[maxn];
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
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int ans=inf;
        for(int i=0;i<n/2;i++)
            ans=min(ans,a[n/2+i]-a[i]);
        cout << ans << endl;
    }
    return 0;
}
```

