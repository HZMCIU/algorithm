### [Acute Stroke](https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072)

### 题意

求三维连通块

### 思路

使用如下的方向数组`int dir[8][3]={0,0,1, 0,0,-1, 0,1,0, 0,-1,0, 1,0,0, -1,0,0};` ，然后进行三维BFS求出联通块。

###	AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1288;
const int maxm=138;
const int maxl=62;
typedef long long ll;
typedef pair<int,int> P;
int dir[8][3]={0,0,1, 0,0,-1, 0,1,0, 0,-1,0, 1,0,0, -1,0,0};
int m,n,l,T;
bool mat[maxl][maxn][maxm];
bool vis[maxl][maxn][maxm];
int ans;
struct node
{
    int x;
    int y;
    int z;
};
void bfs()
{
    queue<node> que;
    node t;
    node next;
    int tx,ty,tz;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(!vis[i][j][k]&&mat[i][j][k]==1)
                {
                    int cnt=1;
                    vis[i][j][k]=1;
                    next.x=i,next.y=j,next.z=k;
                    que.push(next);
                    while(!que.empty())
                    {
                        t=que.front();
                        que.pop();
                        for(int i=0;i<8;i++)
                        {
                            tx=t.x+dir[i][0];
                            ty=t.y+dir[i][1];
                            tz=t.z+dir[i][2];
                            if(tx>=l||tx<0||ty>=m||ty<0||tz>=n||tz<0||vis[tx][ty][tz]==1||mat[tx][ty][tz]==0)
                                continue;
                            cnt+=1;
                            vis[tx][ty][tz]=1;
                            next.x=tx,next.y=ty,next.z=tz;
                            que.push(next);
                        }
                    }
                    if(cnt>=T)
                        ans+=cnt;
                }
            }
        }
    }
}
int main()
{
  //  freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&m,&n,&l,&T);
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                scanf("%d",&mat[i][j][k]);
            }
        }
    }
    bfs();
    printf("%d\n",ans);
    return 0;
}
```

