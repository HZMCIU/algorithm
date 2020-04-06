## [Tennis Game](https://cn.vjudge.net/problem/CodeForces-496D)

### 思路

1. 首先不断枚举所有的t值，而后验证t的正确性。如果采用暴力的验证，那么时间复杂度是$O(n^{2})$ 。所以在验证的时候采用二分法的技巧。在使用二分法的时候，首先要对数据进行预处理。$sum_{1},sum_{2}$表示1方和2方在到第i场比赛中一共获胜的次数。

### 总结

1. 二分搜索中最为关键的东西就是确定二分搜索的对象，相比较与对象，二分搜索的过程还是比较简单的。在这道题目中，二分搜索的对象就是两个数组，这两个数组表示了第i次比赛中1方一共胜利的次数和2方一共胜利的次数。
2. 写了两个二分搜索的题目，我的感觉是二分搜索的本质就是在不断的猜测。其中那个验证猜测是否正确的函数是至关重要的。
3. 这道题目又一次用到了累加和，我还是没有想到。对这个技巧还是没有掌握。

我的代码（Wrong Answer）

```cpp
#include <bits/stdc++.h>
using namespace std;
int  n;
int sum1[100010],sum2[100010];
typedef pair<int,int> P;
P a[100000];
int solve(int t)
{
    int a=0,b=0,now=0;
    while(now<=n)
    {
        int l=t+now;
        int r=now+2*t-1;
        int mid;
        int ans=-1;
        r=min(r,n);
        while(l<=r)
        {
            mid=(l+r) /2;
            if(sum1[mid]-sum1[now]>=t||sum2[mid]-sum2[now]>=t) 
            {
                if(sum1[mid]-sum1[now]==t) ans=mid;
                if(sum2[mid]-sum2[now]==t) ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%d\n",ans);
        if(ans==-1) return -1;
        if(sum1[ans]-sum1[now]==t) a++;
        if(sum2[ans]-sum2[now]==t) b++;
        now=ans;
    }
    printf("%d,%d\n",a,b);
    if(a==b) return -1;
    return max(a,b);
}
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        sum1[i]=sum1[i-1]+(t==1);
        sum2[i]=sum2[i-1]+(t==2);
    }
    int ans;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        ans=solve(i);
        if(ans==-1) continue;
        a[cnt].first=ans,a[cnt].second=i;
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%d %d\n",a[cnt].first,a[cnt].second);
    }
    return 0;
}
```

Accepted

```cpp
#include <bits/stdc++.h>
using namespace std;
int  n;
int sum1[100010],sum2[100010];
typedef pair<int,int> P;
P a[100000];
bool cmp(P a,P b)
{
    return a.first<b.first;
}
int solve(int t)
{
    int a=0,b=0,now=0;
    while(now<=n)
    {
        if(now==n) break;
        int l=t+now;
        int r=now+2*t-1;
        int mid;
        int ans=-1;
        r=min(r,n);
        while(l<=r)
        {
            mid=(l+r) /2;
            if(sum1[mid]-sum1[now]>=t||sum2[mid]-sum2[now]>=t) 
            {
                if(sum1[mid]-sum1[now]==t) ans=mid;
                if(sum2[mid]-sum2[now]==t) ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        //printf("%d\n",ans);
        if(ans==-1) return -1;
        if(sum1[ans]-sum1[now]==t) 
        {
             a++;
             if(ans==n)
             {
                 if(a<=b) return -1;
             }
        }
        if(sum2[ans]-sum2[now]==t) 
        {
            b++;
            if(ans==n)
            {
                if(b<=a) return -1;
            }
        }
        now=ans;
    }
    //printf("%d,%d\n",a,b);
    if(a==b) return -1;
    return max(a,b);
}
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        sum1[i]=sum1[i-1]+(t==1);
        sum2[i]=sum2[i-1]+(t==2);
    }
    int ans;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        ans=solve(i);
        //printf("%d\n",ans);
        if(ans==-1) continue;
        a[cnt].first=ans,a[cnt].second=i;
        cnt++;
    }
    printf("%d\n",cnt);
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        printf("%d %d\n",a[i].first,a[i].second);
    }
    return 0;
}

```



网上的参考代码

```cpp
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}e[150000];
int a[150000];
int sum[105000];
int sum2[105000];
int n;
int cmp(node a,node b)
{
    return a.x<b.x;
}
int Slove(int tt)
{
    int aa=0;
    int bb=0;
    int now=0;
    while(now<=n)
    {
        if(now==n)break;
        int ans=-1;
        int l=tt+now;//now是胜利的划分点
        int r=tt*2-1+now;//区间长度为tt
        r=min(r,n);
        while(r-l>=0)
        {
            int mid=(l+r)/2;
            if(sum[mid]-sum[now]>=tt||sum2[mid]-sum2[now]>=tt) //s的范围可能过大
            {
                if(sum[mid]-sum[now]==tt)ans=mid;
                if(sum2[mid]-sum2[now]==tt)ans=mid;
                r=mid-1;
            }
            else l=mid+1;//s的范围可能过小
        }
        if(ans==-1)return -1;//s为无效值
        else
        {
            if(sum[ans]-sum[now]==tt)
            {
                aa++;
                if(ans==n)//a获得了最后一盘的胜利，但是a获胜总数仍然小于b，即结果不存在
                {
                    if(aa<=bb)return -1;
                }
            }
            if(sum2[ans]-sum2[now]==tt)
            {
                bb++;
                if(ans==n)//同上
                {
                    if(bb<=aa)return -1;
                }
            }
            now=ans;
        }
    }
    int tmp=max(aa,bb);
    if(aa==bb)return -1;
    return tmp;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        memset(sum2,0,sizeof(sum2));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            if(a[i]==1)tmp++;
            sum[i]=sum[i-1]+tmp;
            tmp=0;
            if(a[i]==2)tmp++;
            sum2[i]=sum2[i-1]+tmp;
        }
        for(int i=0;i<=10;i++) printf("%d ",sum[i]);
        puts("");
        for(int i=0;i<=10;i++) printf("%d ",sum2[i]);
        puts("");
        system("pause");
        int tot=0;
        for(int t=1;t<=n;t++)
        {
            int ans=Slove(t);
            if(ans!=-1)
            {
                e[tot].x=ans;
                e[tot++].y=t;
            }
        }
        sort(e,e+tot,cmp);
        printf("%d\n",tot);
        for(int i=0;i<tot;i++)
        {
            printf("%d %d\n",e[i].x,e[i].y);
        }
    }
}



```

