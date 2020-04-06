###[Allowance](https://vjudge.net/problem/POJ-3040)

**思路**

明显的贪心，对我而言，这道题目的难点在于如何模拟。

1. 先取完所有比c大的硬币
2. 从大开始取，再从小取，来取到离c最近的allowances
3. ***使用use数组记录发一次allowances的硬币的组合方式（学到了）***

```cpp
//clean version
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
P a[30];
int use[30]; //used to record the combination of coins,the key point
int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    int ans = 0;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (a[i].first >= c)
        {
            ans += a[i].second;
            a[i].second = 0;
        }
        else break;
    }
    while (1)
    {
        memset(use, 0, sizeof(use)); // initial the combination of coin
        int tc = c; //copy of c
        int suc = 0; // if find the combination of coin
        for (int i = n - 1; i >= 0; i--) //select from the smallest
        {
            if (a[i].second)
            {
                int k = tc / a[i].first;
                int m = min(k, a[i].second); // in case k is big than a[i].second;
                use[i] = m;
                tc -= m * a[i].first;
                if (tc == 0)
                {
                    suc = 1;
                    break;
                }
            }
        }
        if (tc > 0) // combination is not over
        {
            for (int i = 0; i < n; i++) // select from the biggest
            {
                if (use[i] < a[i].second) // still remain
                {
                    while (use[i] < a[i].second)
                    {
                        tc -= a[i].first;
                        use[i]++;
                        if (tc <= 0) // find the combination
                        {
                            suc = 1;
                            break;
                        }
                    }
                }
                if (suc) break;
            }
        }
        if (!suc) break;
        int cnt = INT_MAX; // count number of this combination
        for (int i = 0; i < n; i++)
        {
            if (use[i]) cnt = min(cnt, a[i].second / use[i]);
        }
        for (int i = 0; i < n; i++) // update the remain
        {
            if (use[i]) a[i].second -= use[i] * cnt;
        }
        ans += cnt;
    }
    printf("%d\n", ans);
    return 0;
}


```

