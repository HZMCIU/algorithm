###[Mobile phones](https://vjudge.net/problem/POJ-1195)

### 题意

更改矩阵和求矩阵的区间和

### 思路

二维树状数组。模板题。输入略坑。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2e3 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
int n;
int bit[maxn][maxn];
int lowbit(int x)
{
    return x & -x;
}
int sum(int x, int y)
{
    ll ret = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        for(int j = y; j > 0; j -= lowbit(j))
        {
            ret += bit[i][j];
        }
    }
    return ret;
}
int add(int x, int y, int v)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= n; j += lowbit(j))
        {
            bit[i][j] += v;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int ins;
    int m;
    while(~scanf("%d%d", &m, &n))
    {
        while(scanf("%d", &ins) && ins != 3)
        {
            if(ins == 0)
            {
                scanf("%d", &n);
                memset(bit, 0, sizeof(bit));
            }
            else if(ins == 1)
            {
                int  x, y, a;
                scanf("%d%d%d", &x, &y, &a);
                x++;
                y++;
                add(x, y, a);
            }
            else if(ins == 2)
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
                x1++,x2++,y1++,y2++;
                int ans = sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
```

