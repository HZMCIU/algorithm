### [Sort with Swap(0, i)](https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560)

### 题意

模拟

### 思路

当0换回了第0个位置而全部数据并没有有序排列，这个时候就需要把0和那个在错误位置上的数据交换。

一个简单粗暴的方法，就是遍历全部数组，找到错位的数，然后和0交换。但是$O(n\times m)$的操作显然在数据为$1e5$的时候会超时。

使用一个简单但是有效的技巧，在循环外保存一个变量$i$，指向错位的数字，当0再次回到第0位，而且数组不是有序的时候，从$i$开始而不是从$0$开始向后查找。之所以如此是因为$i$之前的数据都是已经有序的了，不需要重复查找浪费时间，这样复杂度就优化到了$O(n+m)$了。

**标记法，记录上一个状态的结果，达到优化的目的**  

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,string> P;
int pos[maxn];
int vis[maxn];
int cnt;
int wrong;
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int t;
    int mi_diff=n-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t!=i)
        {
            wrong++;
        }
        pos[t]=i;
    }
    int cnt=0;
    int i=1;
    while(wrong>1)
    {
        if(pos[pos[0]]!=0)
        {
            swap(pos[0],pos[pos[0]]);
            cnt++;
            wrong--;
        }
        //如果下一个位置是0的话，那么直接把0和最小的错位数字交换
        else
        {
            //直接从上个位置开始查找
            for(;i<n;i++)
                if(i!=pos[i])
                break;
            if(i==n)
                break;
            swap(pos[0],pos[i]);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
```

