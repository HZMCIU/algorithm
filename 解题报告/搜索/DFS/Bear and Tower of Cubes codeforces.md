## [Bear and Tower of Cubes](https://cn.vjudge.net/problem/CodeForces-680D)

[比较友好的题解](https://www.cnblogs.com/tyty-Somnuspoppy/p/5894126.html)

### 思路

​	对于当前剩余的体积余量m可以选取方块的边长的最大值a，那么剩余的体积就是$m-a^3$。选取方块的边长也可以是(a-1),那么剩余的体积就是$a^3-(a-1)^3-1$

**1.证明：** 剩余的体积要小于$a^3-(a-1)^3$，设当前剩余的体积为$m$ ，则有$m+(a-1)^3<a^3$ ,如果不满足的话，那么现在这个过程中的选取的方块$(a-1)^3$ 就不是最大值，$a^3$才是这个过程中的最大值

2. 只需要选取$(a-1)^3$后，剩下的$a^3-(a-1)^3-1$的体积中，一定可以再去选取$(a-2)^3$的。所有在一次选取中只要选取$a^3$和$(a-1)^3$就可以了

#### 总结

1. 这道题目是不同的算法结合在一起的简单的例子。做题目的时候，不能够局限于单一的算法中，要学会灵活，综合，应用算法。像这道题目Codeforces上的Tag是greedy，但是却用到了，binary search和dfs
2. 这道题目被局限于贪心算法，根本没有想到结合其他的解法去解决。结果找了很久的规律，还是没有出来结果。贪心应该只是局限于思想，具体的实现可以各种各样。

比较简洁的代码

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define CLR(a, b) memset(a, (b), sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int Solve(LL m) 
{
    int l = 1, r = 100000, ans;
    while(r >= l) 
    {
        int mid = (l + r) >> 1;
        if(1LL * mid * mid * mid > m)//体积过大，缩小范围 
        {
            r = mid - 1;
        }
        else //体积符合，但是可能存在长度更加大的方块
        {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}
LL ans1, ans2;//ans1是最多的个数，ans2是最大的体积
void DFS(LL m, LL cnt, LL sum) //剩余的m的个数，cnt记录搜索过程中的方块使用的个数，sum记录搜索过程总的体积
{
    if(m <= 7) //体积为1的立方块最多只能放7个
    {
        if(ans1 < cnt + m || (ans1 == cnt + m && ans2 < sum + m)) 
        {
            ans1 = cnt + m; ans2 = sum + m;
        }
        return ;
    }
    int p = Solve(m);//二分搜索找到最大的方块
    //cout << p << ' ' << m << endl;
    DFS(m - 1LL * p * p * p, cnt + 1, sum + 1LL * p * p * p);//选取一个长度为p的方块
    //if(sum+1LL*p*p*p<=(p+1)*(p+1)*(p+1))
    DFS(1LL * p * p * p - 1 - 1LL * (p-1) * (p-1) * (p-1), cnt + 1, sum + 1LL * (p-1) * (p-1) * (p-1));//选取边长为(p-1)的方块
}
int main()
{
    LL m;
    while(scanf("%lld", &m) != EOF) 
    {
        ans1 = ans2 = 0;
        DFS(m, 0, 0);
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}

```

