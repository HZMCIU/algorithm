### [True Liars](https://vjudge.net/problem/POJ-1417)

### 题意

中文翻译

### 思路

由于好人只说正确的话，坏人只说错误的话。从而可以推到出来，如果一个人说yes,那么这两个人是同类；如果一个人说no那么这两个人不是同类。

使用带权的并查集可以在一个连通分量里面容纳两个类别。

首先将所有的人群分成若干个连通分量，每个连通分量下面有两类。

然后使用一个数组`com[][2]`来统计每个连通分量下面不同两个类别的人数。

然后，使用DP尝试选取每个连通分量中的一个类，看能够凑出p个好人来而且方案唯一。如果能够凑出来，那么每个连通分量是好人还是坏人。然后逆推求出解。

**状态转移方程**

DP\[i\]\[j\]代表前面i个连通分量凑出j个好人的方案个数

`DP[i][j]=sum{DP[i-1][j-com[i][0]]+DP[i-1][j-com[i][1]]}`

### AC代码

```CPP
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e3;
int val[maxn];
int par[maxn];
int com[maxn][2];//统计每个连通分量下面不同两个类别的人数
int dp[maxn][500];
map<int, int> mp;//将连通分量的根节点重新映射为一个新的编号
int cnt;
int insert(int x, int re)
{
    if(mp.find(x) == mp.end())
        mp[x] = ++cnt;
    com[mp[x]][re]++;
    return 0;
}
int find(int x)
{
    if(par[x] == -1)
        return x;
    int t = par[x];
    par[x] = find(par[x]);
    val[x] = (val[x] + val[t]) % 2;
    return par[x];
}
int unite(int a, int b, int re)
{
    int fa = find(a);
    int fb = find(b);
    if(fa != fb)
    {
        par[fa] = fb;
        val[fa] = (val[a] + val[b] + re) % 2;
    }
    return 0;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n, p, q;
    while(~scanf("%d%d%d", &n, &p, &q)&&p+n+q)
    {
        memset(par, -1, sizeof(par));
        memset(val, 0, sizeof(val));
        memset(com, 0, sizeof(com));
        memset(dp, 0, sizeof(dp));
        cnt = 0;
        mp.clear();
        char str[30];
        for(int i = 0; i < n; i++)
        {
            int a, b, re;
            scanf("%d%d%s", &a, &b, str);
            int fa = find(a);
            int fb = find(b);
            if(str[0] == 'n')
                re = 1;
            else if(str[0]=='y')
                re = 0;
            if(fa != fb)
            {
                unite(a, b, re);
            }
        }
        for(int i = 1; i <= p + q; i++)
        {
            int fi = find(i);
            insert(fi, val[i]);
        }
        dp[0][0]=1;
        for(int i = 1; i <= cnt; i++)
        {
            for(int j = 0; j <= p; j++)
            {
                if(j >= com[i][0])
                    dp[i][j] += dp[i - 1][j - com[i][0]];
                if(j >= com[i][1])
                    dp[i][j] += dp[i - 1][j - com[i][1]];
            }
        }
        //逆推
        if(dp[cnt][p] == 1)
        {
            int choice[maxn];//每个联通分量所代表的是好人还是坏人
            memset(choice,-1,sizeof(choice));
            int k=p;
            for(int i=cnt;i>=1;i--)
            {
                if(dp[i][k]==dp[i-1][k-com[i][0]])
                {
                    choice[i]=0;
                    k-=com[i][0];
                }
                else if(dp[i][k]==dp[i-1][k-com[i][1]])
                {
                    choice[i]=1;
                    k-=com[i][1];
                }
            }
            for(int i=1;i<=p+q;i++)
            {
                int fi=mp[find(i)];
                if(val[i]==choice[fi])
                {
                    printf("%d\n",i);
                }
            }
            puts("end");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
```

