## [Shaass and Painter Robot](http://blog.csdn.net/fearlessxjdx/article/details/73927899)

#### 思路

从这道题目中，可以看到思考是很重要的。如果用搜索模拟机器人染色的过程，那么时间绝对不允许。

这里假设矩形棋盘的大小是NxM，通过观察可以发现，如果棋盘上的所有的格子全部都染色成黑白相间的，那么在四条边上的染色数量一定是(N+M-2)。如果在四条边上的节点一共有2 * (N+M-2)个，每一次碰撞都会使得边上的一个节点变成黑色，如果在2 * (N+M-2)次碰撞中没有使得四条边上的黑色节点数量为 (N+M-2)那个无论如何碰撞都不可能出现想要的结果

[题解](http://blog.csdn.net/fearlessxjdx/article/details/73927899) 

```cpp
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
int n,m,x,y,tot,a,b,f[4][10000000],dx,dy; //f[i][j]用来标记相应的边
char ch[5];
ll ans;
int solve(int x,int y)
{
    if(x==1) a=0,b=y;
    else if(x==n) a=1,b=y;
    else if(y==1) a=2,b=x;
    else if(y==m) a=3,b=x;
    //printf("%d\n",f[a][b]);
    //printf("a:%d b:%d\n",a,b);
    if(!f[a][b]) f[a][b]=1,++tot;
    if(x==1) dx=1;
    if(x==n) dx=-1;
    if(y==1) dy=1;
    if(y==m) dy=-1;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&x,&y);
    scanf("%s",&ch);
    ch[0]=='D'?dx=1:dx=-1;
    ch[1]=='R'?dy=1:dy=-1;
    //printf("dx:%d,dy:%d\n",dx,dy);
    int  t;
    ans=1;
    for(int i=1;i<=2*(n+m-2);i++)
    {
        //printf("i:%d\n",i);
        solve(x,y);
        if(tot>=n+m-2) 
        {
             printf("%I64d",ans);
             return 0;
        }
        //printf("tot:%d\n",tot);
        //printf("%d\n",ans);
        t=min(dy>0?m-y:y-1,dx>0?n-x:x-1);
        //printf("%d\n",t);
        ans+=t;
        x+=dx*t;y+=dy*t;
        //printf("x:%d y:%d\n",x,y);
    }
    puts("-1");
    return 0;
}

```

