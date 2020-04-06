###[Supermarket](https://cn.vjudge.net/problem/POJ-1456)

### 题意

超市里有$n$件待出售的商品，每件商品要在$d_i$前出售，且没见商品的获利为$p_i$。问最多可以获利多少。

### 思路

1. **贪心，暴力**

   首先对商品根据价值来进行排序，**每件物品要在deadline时出售**，那么就能够为其他物品尽可能提供出售时间，然后根据价值从大到小选择物品。

2. 并查集，大佬的想法。orz

   使用`par[i]`来表示第`i`天之前有多少可以空闲的时间。利用了并查集的树形结构来进行更新。

   ```cpp
   int t=find(pro[i].dea);
   //如果还有空闲的天数
   if(t>0)
   {
   	ans+=pro[i].val;
       //第i天被用了之后，前i天空闲的天数等于前i-1天空闲的天数
   	par[t]=t-1;
   }
   ```


### AC代码

思路一

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;
struct good
{
    int val;
    int dea;
};
good pro[maxn];
int vis[maxn];
bool cmp(good a,good b)
{
    return a.val>b.val;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&pro[i].val,&pro[i].dea);
        }
        sort(pro+1,pro+1+n,cmp);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[pro[i].dea])
            {
                vis[pro[i].dea]=true;
                ans+=pro[i].val;
//                printf("%d\n",pro[i].val);
            }
            else
            {
                for(int j=pro[i].dea-1;j>=1;j--)
                {
                    if(!vis[j])
                    {
                        vis[j]=true;
                        ans+=pro[i].val;
//                        printf("%d\n",pro[i].val);
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

思路2

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;
struct good
{
    int val;
    int dea;
};
good pro[maxn];
int par[maxn];
bool cmp(good a,good b)
{
    return a.val>b.val;
}
int find(int x)
{
    if(par[x]==-1)
        return x;
    return par[x]=find(par[x]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while(~scanf("%d",&n))
    {
        memset(par,-1,sizeof(par));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&pro[i].val,&pro[i].dea);
        }
        sort(pro+1,pro+1+n,cmp);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int t=find(pro[i].dea);
            if(t>0)
            {
                ans+=pro[i].val;
                par[t]=t-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

