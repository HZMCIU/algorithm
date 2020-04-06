### [Ignatius and the Princess IV](https://vjudge.net/problem/HDU-1029#author=zmyhh)

### 题意

看翻译

### 思路

暴力解法。排个序，找到出现次数最多的。

巧妙的解法。由于答案是出现次数最多的，而且比其他所有数出现的总和还要大。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
int a[maxn];
int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0,t,ans;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(ans==t) cnt++;
            else if(--cnt<0)
            {
                ans=t;
                cnt++;
            }
        }
        printf("%d\n",ans);//答案对于的cnt的值一定是正数
    }
    return 0;
}
```

