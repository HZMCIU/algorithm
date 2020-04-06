### [Shopping in Mars ](https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264)

PAT中罕见的二分。使用前缀和记录就行了。

审题还是不过关呀

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
typedef pair<int,int> P;

int sum[maxn];
int n,m;
int bsearch(int v)
{
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(sum[mid]==v)
            return mid;
        else if(sum[mid]>v)
        {
            r=mid-1;
        }
        else if(sum[mid]<v)
            l=mid+1;
    }
    return -1;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        sum[i]=sum[i-1]+t;
    }
    vector<P> ans;
//    for(int i=1;i<=n;i++)
//    {
//        printf("%d %d\n",i,sum[i]);
//    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(sum[i]>=m)
        {
            int ret=bsearch(sum[i]-m);
            if(ret!=-1)
            {
                printf("%d-%d\n",ret+1,i);
                f=1;
            }
        }
    }
    if(!f)
    {
        vector<P> ans;
        int mx=inf;
        for(int i=1;i<=n;i++)
        {
            if(sum[i]>=m)
            {
                int ret=lower_bound(sum,sum+1+n,sum[i]-m)-sum;
                if(ret!=-1)
                {
                    if(mx>sum[i]-sum[ret-1])
                    {
                        mx=sum[i]-sum[ret-1];
                        ans.clear();
                        ans.push_back({ret,i});
                    }
                    else if(mx==sum[i]-sum[ret-1])
                        ans.push_back({ret,i});
                }
            }
        }
        for(P p:ans)
            printf("%d-%d\n",p.first,p.second);
    }
	return 0;
}
```

