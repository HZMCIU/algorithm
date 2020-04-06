### [Count the Colors](https://vjudge.net/problem/ZOJ-1610#author=0)

### 题意

给区间染色，求一种颜色有多少个不连续的区间。

### 思路

线段树Lazy来进行染色。染色结束后将所有的叶子节点，重新拷贝到另外一个数组中，进行统计。

为了避免染色时，将端点的颜色覆盖掉，所以使用左开右闭的方法来代表一个区间。

```cpp
update(1,1,8000,l+1,r,v);
```



### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
int lazy[maxn];
int leaf[maxn];
int ans[maxn];
void push_down(int ro)
{
    if(lazy[ro]!=-1)
    {
        lazy[ro<<1]=lazy[ro<<1|1]=lazy[ro];
        lazy[ro]=-1;
    }
}
void update(int ro,int l,int r,int L,int R,int c)
{
    int mid=(l+r)>>1;
    if(L<=l&&r<=R)
    {
        lazy[ro]=c;
        return ;
    }
    push_down(ro);
    if(lazy[ro]==c)
        return;
    if(L<=mid)
        update(ro<<1,l,mid,L,R,c);
    if(mid<R)
        update(ro<<1|1,mid+1,r,L,R,c);
}
void query(int ro,int l,int r)
{
    int mid=(l+r)>>1;
    if(lazy[ro]!=-1)
    {
        for(int i=l;i<=r;i++)
            leaf[i]=lazy[ro];
        return ;
    }
    if(l!=r&&lazy[ro]==-1)
    {
        int mid=(l+r)>>1;
        query(ro<<1,l,mid);
        query(ro<<1|1,mid+1,r);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        memset(lazy,-1,sizeof(lazy));
        memset(leaf,-1,sizeof(leaf));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
//            l+=1;
//            r+=1;
            update(1,1,8000,l+1,r,v);
        }
        query(1,1,8000);
        int l=0,r=0;
        for(int i=0;i<maxn;i++)
        {
            if(leaf[i]!=-1)
            {
                int c=leaf[i];
                int j=i+1;
                while(leaf[j]==c)
                    j++;
                i=j-1;
                ans[leaf[i]]++;
            }
        }
        for(int i=0;i<=8000;i++)
        {
            if(ans[i])
            {
                printf("%d %d\n",i,ans[i]);
            }
        }
        puts("");
    }
    return 0;
}
```

