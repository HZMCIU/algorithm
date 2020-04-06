### [Nightmare Ⅱ](https://vjudge.net/problem/HDU-3085)

https://blog.csdn.net/ZHangFFYY/article/details/72436623

### 题意

一个迷宫中有两个人，一个鬼。一个人每次可以走一步，另一个人每次可以走三步。**并不一定走直线，可以走斜线。** 鬼每次可以分裂两个，占领两步内的方块。鬼遇到人就会把人吃掉。问两个人十分可以相遇，如果可以，最少要走多少步。

### 思路

曼哈顿距离。双向BFS。

使用变量`step`记录当前的步数。如果鬼和人的曼哈顿距离小于等于`2*step`那么那个状态就是不可达的。

双向BFS就是使用两个队列，然后交替进行状态的更新。在更新的过程中判断两个人是否相遇了。使用`dist`来记录状态是否访问过。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
typedef long long ll;
typedef pair<int, int> P;

struct node
{
    int x, y;
} gf, err, gh[2];
int n, m;
int step;
int dist[2][maxn][maxn];
char maze[maxn][maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
queue<node> que[2];
void read()
{
    int cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%s",maze[i]);
        for(int j=0; j<m; j++)
        {
            if(maze[i][j] =='M')
            {
                err.x = j;
                err.y = i;
            }
            else if(maze[i][j] =='G')
            {
                gf.x = j;
                gf.y = i;
            }
            else if(maze[i][j] =='Z')
            {
                gh[cnt].x = j;
                gh[cnt++].y = i;
            }
        }
    }
}
bool judge(node t)
{
    if(t.x >= m || t.x < 0 || t.y >= n || t.y < 0 || maze[t.y][t.x] == 'X')
        return 0;
    if(abs(t.x - gh[0].x) + abs(t.y - gh[0].y) <= 2 * step)
        return 0;
    if(abs(t.x - gh[1].x) + abs(t.y - gh[1].y) <= 2 * step)
        return 0;
    return 1;
}
bool bfs(int n)
{
    int sum = que[n].size();
    node t, next;
    while(sum--)
    {
        t = que[n].front();
        que[n].pop();
        if(judge(t) == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                next.x = t.x + dir[i][0];
                next.y = t.y + dir[i][1];
                if(judge(next) == 0)
                    continue;
                if(dist[n][next.y][next.x] != inf)
                    continue;
                if(dist[n ^ 1][next.y][next.x] != inf)
                    return 1;
                dist[n][next.y][next.x] = dist[n][t.y][t.x] + 1;
                que[n].push(next);
            }
        }
    }
    return 0;
}
int solve()
{
    while(!que[0].empty())
        que[0].pop();
    while(!que[1].empty())
        que[1].pop();
    memset(dist,inf,sizeof(dist));
    step=0;
    que[0].push(gf);
    que[1].push(err);
    dist[0][gf.y][gf.x] = 0;
    dist[1][err.y][err.x] = 0;
    while(!que[0].empty() || !que[1].empty())
    {
        step++;
        if(bfs(0) == 1)//走一步
            return step;
        if(bfs(1) == 1)//走三步
            return step;
        if(bfs(1) == 1)
            return step;
        if(bfs(1) == 1)
            return step;
    }
    return -1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        read();
        printf("%d\n", solve());
    }
    return 0;
}
```

