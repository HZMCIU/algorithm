##  [The Child and Set](https://cn.vjudge.net/problem/CodeForces-437B)

#### 思路

`n&-n`就是lowbit的值，然后将lowbit的值进行排序，然后从后往前取。高位的二进制可以用低位来代替，但是低位的二进制不可用高位的二进制来代替。所以先取高位的。

```cpp
#include <cstdio>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
pair<int,int> a[100010];
int lowbit(int n)
{
    return n&(-n);
}
int main()
{
    int n,sum;
    cin >> sum >> n;
    for(int i=1;i<=n;i++)
    {
        //a[i]={lowbit(i),i};
        a[i].first=lowbit(i);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    vector<int> ans; 
    for(int i=n;i>=1;i--)
    {
        if(sum>=a[i].first) 
        {
            sum-=a[i].first;
            ans.push_back(a[i].second);
        }
    }
    if(sum==0)
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    }
    else puts("-1");
    return 0;
}
```

