### [Balanced Lineup](https://vjudge.net/problem/POJ-3264#author=TIMEpings)

### 思路

使用线段树求出区间内的最大值和最小值。模板题。

### AC代码

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
int mi[maxn];
int mx[maxn];
int tree[maxn];
int a[maxn];
int ans_mi;
int ans_mx;
void push_up(int ro)
{
    mi[ro]=min(mi[ro<<1],mi[ro<<1|1]);
    mx[ro]=max(mx[ro<<1],mx[ro<<1|1]);
}
void build(int ro,int l,int r)
{
    if(l==r)
    {
        tree[ro]=a[l];
        mi[ro]=a[l];
        mx[ro]=a[l];
        return;
    }
    int m=(l+r)>>1;
    if(l<=m)
        build(ro<<1,l,m);
    if(m<r)
        build(ro<<1|1,m+1,r);
    push_up(ro);
}
void query(int ro,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        ans_mi=min(ans_mi,mi[ro]);
        ans_mx=max(ans_mx,mx[ro]);
        return ;
    }
    int m=(l+r)>>1;
    if(L<=m)
        query(ro<<1,l,m,L,R);
    if(m<R)
        query(ro<<1|1,m+1,r,L,R);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(q--)
    {
        ans_mx=-inf;
        ans_mi=inf;
        int l,r;
        scanf("%d%d",&l,&r);
        query(1,1,n,l,r);
        printf("%d\n",abs(ans_mi-ans_mx));
    }
    return 0;
}
```

