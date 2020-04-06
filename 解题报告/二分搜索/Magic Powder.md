## [Magic Powder](https://cn.vjudge.net/problem/CodeForces-670D2)

#### 思路

使用二分法猜测所有的值（这里有一个坑点，再使用二分搜索的时候，使用的数据类型都太小了，所有导致许多奇怪的错误。所以预先估计值得大小还是比较重要的。），而后判断每个值是否合法就可以了。

```cpp
#include <stdio.h>
#include <limits.h>
typedef long long ll;
ll ans=LLONG_MAX;
int n,k;
int a[100000+10],b[100000+10];
int check(ll mid)//就是在这里把数据开的太小了，改成ll就A了
{
    ll t=0;
    for(int i=0;i<n;i++)
    {
       if(mid*a[i]<=b[i])   continue;
       else if(mid*a[i]>b[i]) 
         //刚开始的时候还在纠结应该怎么分配K这种可以变成任何其他原料的材料，要保证可以造出最多的房子。但是没有想到一个合理的分配方法。
         //但是后来发现，其实在使用二分搜索的过程中其实并不重要。check()函数只要验证能否在K的限制条件下造出mid个房子就可以了。如果能够在K的限制条件下造出mid个房子，那么对于原材料不足的房子必定要进行补充，如果补充的数量超出了K的限制，那么造出mid个房子就是不可能的。
       {
           t+=(mid*a[i]-b[i]);
       }
       //printf("%d\n",t);
       if(t>k) return 0;
    }
    return 1;
}
int bsearch()
{
    ll l=0,r=2000000000;
    ll mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            //printf("%d\n",check(mid));
            ans=mid;//因为题目是要求解最大值，如果存在较小的mid的值，那么先把mid保存下来，然后再去二分更大的值，如果存在可行解的话，更新mid，如果不存在这个时候的mid就是答案了
            //printf("%d\n",mid);
            l=mid+1;
        }
        else 
        {
            r=mid-1;
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        ans=LLONG_MAX;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        /*int temp;
        scanf("%d",&temp);
        printf("%d\n",check(temp));*/
        bsearch();
        if(ans==LLONG_MAX) puts("0");
        else printf("%d\n",ans);
    }
    return 0;
}


```

