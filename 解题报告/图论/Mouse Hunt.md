### [Mouse Hunt](http://codeforces.com/contest/1027/problem/D)

### 题意

寝室里有一只老鼠，在每个寝室里布置一个捕鼠装置需要花费$c_i$ 。如果老鼠在第$i$个房间内，那么它下一个要去的房间就是$a_i$。问最小花费将老鼠捕获。

### 思路

图论。由于输入一共有$n$条边，对于$n$个点来说，$n-1$条单向边，恰好可以连接$n$个点，但是如果有$n$条边的话，那么就会出现两个点之间有双向边。（不排除，单点的情况）。所以老鼠最后出现的点一定是双向边连接的点。

所以，只要找出所有的双向边连接的点和单点即可，取和的最小值即可。

### 总结

这里使用了图论中**入度**的概念，学习一下。

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=1e6+10;
int c[maxn];
int a[maxn];
int deg[maxn];
int que[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        deg[a[i]]++;
    }
    int topQ=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==0)
        que[topQ++]=i;
    for(int i=0;i<topQ;i++)
    {
        deg[a[que[i]]]--;
        if(deg[a[que[i]]]==0)
            que[topQ++]=a[que[i]];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0) continue;
        int u=i;
        int t=0x3f3f3f3f;
        while(deg[u]!=0)
        {
            deg[u]=0;
            t=min(t,c[u]);
            u=a[u];
        }
        ans+=t;
    }
    printf("%d\n",ans);
    return 0;
}
```

