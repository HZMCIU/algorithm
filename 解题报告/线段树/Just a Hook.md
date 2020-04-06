### [Just a Hook](https://vjudge.net/problem/HDU-1698)

### 题意

初始编号为1-n的点的值为1。每次将[l,r]区间内的点的值修改为v，问经过q次修改后，所有点总和为多少。

### 思路

线段树模板题。

Lazy标记

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
int lazy[maxn],sum[maxn];
void push_up(int ro)
{
    sum[ro]=sum[ro<<1]+sum[ro<<1|1];
}
void push_down(int ro,int l,int r)
{
    if(lazy[ro])
    {
        int mid=(r+l)>>1;
        lazy[ro<<1]=lazy[ro<<1|1]=lazy[ro];
        sum[ro<<1]=(mid-l+1)*lazy[ro];
        sum[ro<<1|1]=(r-mid)*lazy[ro];
        lazy[ro]=0;
    }
}
void build(int ro,int l,int r)
{
    int mid=(l+r)>>1;
    lazy[ro]=0;
    if(l==r)
    {
        sum[ro]=1;
        return ;
    }
    build(ro<<1,l,mid);
    build(ro<<1|1,mid+1,r);
    push_up(ro);
}
void update(int ro,int l,int r,int L,int R,int c)
{
    int mid=(l+r)>>1;
    if(L<=l&&r<=R)
    {
        lazy[ro]=c;
        sum[ro]=c*(r-l+1);
        return ;
    }
    push_down(ro,l,r);
    if(L<=mid)
        update(ro<<1,l,mid,L,R,c);
    if(mid<R)
        update(ro<<1|1,mid+1,r,L,R,c);
    push_up(ro);
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        while(q--)
        {
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
            update(1,1,n,l,r,v);
        }
        printf("Case %d: The total value of the hook is %d.\n",cs++,sum[1]);
    }
    return 0;
}
```

