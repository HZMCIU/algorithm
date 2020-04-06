### [Magic Coupon](https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472)

### 题意

将两个数组各个元素相乘，如何得到最大值

### 思路

把两个数组排序，正数、正数相乘，负数、负数相乘，如果正负不匹配，那么就忽略

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 10;
const int maxm = 1e2;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int a[maxn],b[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n,m;
    scanf("%d",&n);
    int n_a=0,n_b=0;
    int p_a=0,p_b=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0)
            p_a++;
        else if(a[i]<0)
            n_a++;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]>0)
            p_b++;
        else if (b[i]<0)
            n_b++;
    }
    sort(a,a+n);
    sort(b,b+m);
    ll ans=0;
    for(int i=0;i<min(n_a,n_b);i++)
        ans=ans+a[i]*b[i];
    for(int i=n-1,j=m-1,k=0;k<min(p_a,p_b);i--,j--,k++)
    {
        ans=ans+a[i]*b[j];
    }
    printf("%lld\n",ans);
    return 0;
}
```

