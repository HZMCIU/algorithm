### [Median](https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968)

### 题意

合并两个数组，并输出数组中间的数。两个数组是按照升序排列的，合并后的数组也要按照升序排列。

### 思路

由于这道题目，卡内存，所以不能使用`开两个数组a，b然后将和合并的结果存在c中`的方法，会爆内存的。

开一个数组a存第一个数组，然后**在线处理**第二个数组。使用两个指针，类似于归并排序的方法，合并两个数组，使用`count`记录已经处理的元素的个数，当到达`(n+m+1)/2`的时候，将答案存下来

这道题目其实是不用long long 数组的，只要int数组就可以了

### 总结

学会了

1. 在线处理
2. 优化程序的内存
3. 使用循环时，初始值的选择，要保证代码的可读性，易理解

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int a[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    int pa=1,cnt=0;
    int ans;
    int x;
    //这里初始值i=1，比i=0，更容易理解
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        while(x>=a[pa]&&pa<=n)
        {
            pa++;
            cnt++;
            if(cnt==(n+m+1)/2)
                ans=a[pa-1];
        }
        cnt++;
        if(cnt==(n+m+1)/2)
            ans=x;
    }
    //最后还可能会有残留的
    while(pa<=n)
    {
        pa++;
        cnt++;
        if(cnt==(n+m+1)/2)
            ans=a[pa-1];
    }
    printf("%d\n",ans);
    return 0;
}
```

