##  [Painting Fence](https://cn.vjudge.net/problem/CodeForces-448C)

#### 思路

搜索形式的二分查找。

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[5050];
int n;
int ans=0;
int dfs(int l,int r)
{
    int _min=INT_MAX,_max=INT_MIN;
    for(int  i=l;i<r;i++)
    {
        _min=min(_min,a[i]);
        _max=max(_max,a[i]);
    }
    if(_min==_max)//两块木板高度相同
    {
        ans+=min(_min,r-l);//取横向刷和纵向刷中的较小者
        return 0;
    }
    for(int i=l;i<r;i++) a[i]-=_min;
    ans+=min(_min,r-l);
    for(int i=l;i<r;i++)
    {
        if(a[i])
        {
            int j;
            for(j=i;j<r;j++)
            {
                if(a[j]==0||a[j]>0&&j==r-1) 
                {
                    if(a[j]>0&&j==r-1) j++;//由于不包含右区间，如果最后一个元素是非零元素，那么j+1
                    break;
                }
            }
            int t=ans;
            dfs(i,j);
            if(ans-t>j-i)//比较横向刷和纵向刷的较小者
            {
                ans=t+j-i;
            }
            i=j;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    dfs(0,n);
    printf("%d\n",min(n,ans));//刷的最大次数不会超过n次
    return 0;
}

```

