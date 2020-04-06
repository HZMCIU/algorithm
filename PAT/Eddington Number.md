### [Eddington Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136)

### 题意

一个数叫做`Eddington Number` ，存在一个数E，在一个数列中有E个大于E的数，那么这个数就叫做`Eddington Number` 。求最大的`Eddington Number` 。

### 思路

排序，枚举长度，控制变量。在这道题目中存在两个变量，一个是最小值大于E，一个是长度大于E。排序后，通过枚举长度，如果`n-i`长度序列中的最小值大于`n-i`即可。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int arr[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(n-i<arr[i])
            ans=max(n-i,ans);
    }
    printf("%d\n",ans);
    return 0;
}
```

