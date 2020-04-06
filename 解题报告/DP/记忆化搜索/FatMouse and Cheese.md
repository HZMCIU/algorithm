### [FatMouse and Cheese](https://vjudge.net/problem/HDU-1078#author=0)

[博客](https://blog.csdn.net/qq_34374664/article/details/52243949)

### 题意

在一个$n\times n$的格子内，有一只老鼠。初始位置位于$(1,1)$ ，每次可以上下左右移动不超过$k$个单位。而且下一个移动的方块的奶酪的数量一定要大于现在的位于格子的奶酪的数量。问最多能够吃到多少的奶酪。

### 思路

记忆化搜索：先递归下去，直到这个点下面所有的状态都已经访问了，然后用最优解来更新这个状态的值。然后使用DP数组保存下来。下次再访问的时候能够直接得出最优解了。

> 记忆化搜索：这里的dp代表的是从后来所有点一路走来的最大权值，先不断递归，走到不能走了，就要返回，返回值是 dp\[x\]\[y\]+a\[x\]\[y\]，然后回到上一层递归，继续for循环，再到走不动。。。。然后取max的最大值，这时候dp【x】【y】就已经是最优解了，以后遇到他直接返回就行；回溯完了dp【0】【0】就是从0，0走的最大值；

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=110;
int dp[maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,k;
int a[maxn][maxn];
int dfs(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i<4;i++)
        {
            int tx=x+j*dir[i][0];
            int ty=y+j*dir[i][1];
            if(0<=tx&&tx<n&&0<=ty&&ty<n&&a[tx][ty]>a[x][y])
                ans=max(ans,dfs(tx,ty));
        }
    }
    return dp[x][y]=ans+a[x][y];
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1)
            break;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
```

