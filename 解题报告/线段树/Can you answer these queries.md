###[Can you answer these queries?](https://vjudge.net/problem/HDU-4027#author=hzoi2017_csm)

### 题意

给出两种操作，一是查询区间[l,r]的和，二是将区间[l,r]中所有的数开平方。

### 思路

基础的线段树操作。

优化策略：

如果一个区间内的所有的数的值为1，那么就不对这个区间继续进行更新操作。

```cpp
if(sum[ro]==r-l+1)
    return;
```



### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
ll sum[maxn];
ll tree[maxn];
ll a[maxn];
void push_up(int ro)
{
    sum[ro]=sum[ro<<1]+sum[ro<<1|1];
}
void build(int ro,int l,int r)
{
    if(l==r)
    {
        sum[ro]=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(ro<<1,l,m);
    build(ro<<1|1,m+1,r);
    push_up(ro);
}
void update(int ro,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        if(sum[ro]==r-l+1)
            return;
        if(l==r)
        {
            sum[ro]=sqrt(sum[ro]);
            return;
        }
    }
    int m=(l+r)>>1;
    if(L<=m)
        update(ro<<1,l,m,L,R);
    if(m<R)
        update(ro<<1|1,m+1,r,L,R);
    push_up(ro);
}
ll query(int ro,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        return sum[ro];
    }
    int m=(l+r)>>1;
    ll ret=0;
    if(m>=L)
        ret+=query(ro<<1,l,m,L,R);
    if(m<R)
        ret+=query(ro<<1|1,m+1,r,L,R);
    return ret;
}
int cs=1;
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        build(1,1,n);
        int t;
        scanf("%d",&t);
        printf("Case #%d:\n",cs++);
        while(t--)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(l>=r)
                swap(l,r);
            if(op==0)
            {
                update(1,1,n,l,r);
            }
            else if(op==1)
            {
                ll ans=query(1,1,n,l,r);
                printf("%I64d\n",ans);
            }
        }
        puts("");
    }
    return 0;
}
```

