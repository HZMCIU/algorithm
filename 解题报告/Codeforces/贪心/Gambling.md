### [Gambling](http://codeforces.com/contest/1038/problem/C)

### 题意

A,B两个选手，每个选手各有n个数。有两种操作：删除对手的一个数；将自己的一个数加到`score`中并删除。每个选手都会采取最优策略，来使得各自的差值最大化。即$Score_a-Score_b$ 或者 $Score_b-Score_a$最大化。问进行到最后，$Score_a-Score_b$的差值是多少。

### 思路

**首先确定最优策略是什么？**

对A来讲，如果B的最大值比A的最大值大，删去B的最大值。否则，将A的最大值加入到A的`score`中。B，也是这样的策略。

`score`要用`long long`存。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
typedef long long ll;
typedef pair<int, int> P;
int a[maxn];
int b[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    int in1=n-1,in2=n-1;
    ll ans1=0,ans2=0;
    while(in1>=0||in2>=0)
    {
        if(a[in1]<b[in2]&&in1>=0&&in2>=0)
        {
            in2--;
        }
        else if(in1>=0)
        {
            ans1+=a[in1];
            in1--;
        }
        else if(in2>=0)
            in2--;
        if(b[in2]<a[in1]&&in1>=0&&in2>=0)
        {
            in1--;
        }
        else if(in2>=0)
        {
            ans2+=b[in2];
            in2--;
        }
        else if(in1>=0)
            in1--;
    }
    printf("%I64d\n",ans1-ans2);
    return 0;
}
```

