###[MooFest](https://vjudge.net/problem/OpenJ_Bailian-1990)

### 题意

每只牛都有一个耳背值$V_i$ ，当牛i和牛j进行对话时，通话的分贝至少为max(Vi,Vj)\*distance(i,j)，distance(i,j)为两牛的距离。问所有牛通话分贝的最小和。

### 思路

树状数组的优点就是查询和更新数组的区间和的速度快。所以要使用树状数组，就需要将原问题转化为求解区间和。

通过观察可以发现，可以枚举每一只牛，然后找出所有音量比这只牛小的牛，然后使用树状数组求解出来牛之间的距离之差，然后使用这只牛的音量乘以距离差的总和即可。

使用树状数组来维护两个数组,sum,cnt；分别表示一个点的坐标，以及一个点是否出现过。

这样我们就可以通过树状数组的getsum(x)来获得有多少个小于x的点，以及小于x点的坐标和。

如果已知一个点$X_i$,那么各个点到该点的距离之和的计算步骤如下：

1. 获得当前所有点的坐标和，total
2. s1=getsum(cnt,x)//获取有多少个点小于x
3. s2=getsum(s,x)//获取小于x点的坐标和
4. ans+=a[i].v*(a[i].x\*s1-s2+total-s2-(i+1-s1)\*a[i].x)//在a[i].x之前的点，在a[i].x之后的点

**我好菜呀**

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5e4 + 90;
const int inf = 1e9 + 10;
typedef long long ll;
ll cnt[maxn];
ll s[maxn];
struct node
{
    ll x;
    ll v;
    bool operator < (const node &a)const
    {
        return v<a.v;
    }
}a[maxn];
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
    freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d",&n))
    {
        ll total=0;
        ll ans=0;
        memset(cnt,0,sizeof(cnt));
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&a[i].v,&a[i].x);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            add(cnt,a[i].x,1);
            add(s,a[i].x,a[i].x);

            ll s1=sum(cnt,a[i].x);
            ll s2=sum(s,a[i].x);

            total+=a[i].x;
            ans+=a[i].v*(a[i].x*s1-s2+(total-s2-a[i].x*(i+1-s1)));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

