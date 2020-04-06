###[Cows](https://vjudge.net/problem/OpenJ_Bailian-2481)

### 题意

给出n个区间，求每个区间比这个区间范围大的区间有多少个

### 思路

树状数组。

区间$[S,T]$

固定变量法。固定区间的开始，按照升序排列。那么可以保证前一个区间的S比后一个区间的T要小。那么只需要前面区间中有多少个T比当前的T要大，答案就是比这个区间范围大的个数了。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5e5 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
ll cnt[maxn];
struct node
{
    int s;
    int e;
    int ans;
    int ord;
    bool operator < (const node &a) const
    {
        if(a.s==s)
            return e>a.e;
        return s<a.s;
    }
}a[maxn];
bool cmp(node a,node b)
{
    return a.ord<b.ord;
}
int lowbit(int x)
{
    return x & -x;
}
int add(ll *bit,int x, int v)
{
    for(int i = x; i < maxn; i += lowbit(i))
    {
        bit[i] += v;
    }
}
int sum(ll*bit ,int x)
{
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        ret += bit[i];
    }
    return ret;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset(cnt,0,sizeof(cnt));
        a[0].s=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].s,&a[i].e);
            a[i].s++;
            a[i].e++;
            a[i].ord=i;
        }
        sort(a+1,a+n+1);
        int sz=0;
        a[1].ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].s==a[i-1].s&&a[i].e==a[i-1].e)
                a[i].ans=a[i-1].ans;
            else
            {
                a[i].ans=i-sum(cnt,a[i].e-1)-1;
            }
            add(cnt,a[i].e,1);
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<n;i++)
        {
            printf("%d ",a[i].ans);
        }
        printf("%d\n",a[n].ans);
    }
    return 0;
}
```

