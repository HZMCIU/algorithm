### [Eight II](https://cn.vjudge.net/problem/HDU-3567)

### 题意

八数码问题升级版。问从一个状态到达另一个状态需要的最小步数，如果有多个解，输出字典序最小的哪一个。

### 思路

A*算法无法保证步数最小。所以采用广搜，来保证最小步数。题目保证A状态到B状态必定有解，所以无需计算逆序数。

这里使用一个技巧将A状态映射问八数码的初始状态，即`X12345678`，`1X2345678`，`12X345678`，…，`12345678X`。将状态B也做对应的映射，然后求解A到B的最小步数。

映射的规则：将A状态的数字和初始状态的数字一一映射。然后将这种映射应用于状态B上即可。

例如状态A $12X453786$   状态B $12345678X$ 。

首先将状态A映射到初始状态 即，$12X453786$  $\rightarrow$ $12X345678$ 。

$1\rightarrow 1$ 

$2\rightarrow 2$ 

$4\rightarrow 3$

$5\rightarrow 4$

$3\rightarrow 5$

$7\rightarrow 6$

$8\rightarrow 7$

$6\rightarrow 8$

然后对状态B也做对应的变换，可以得到$12534867X$

每个初始状态$A'$进行BFS得到$A'$到其他各个状态$B'$的最小路径，保存在前驱`pre[10][500000]`上。然后只要进行逆推就可。

如何保证**字典序最小**。每次拓展节点是先拓展字典序小的方向`dlru`。

```cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;
const int maxn = 500000;
int pre[10][maxn];
int ans[10][maxn];
int hsh[100] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
char path[] = "dlru";
int dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
bool vis[maxn];
struct node
{
    int x, y;
    int maze[3][3];
    node(char *s)
    {
        int a = 0, b = 0;
        for(int i = 0; i < 9; i++)
        {
            if(s[i] == 'X')
            {
                x = a, y = b;
                maze[a][b++] = 0;
            }
            else
                maze[a][b++] = s[i] - '0';
            if(b == 3)
                a += 1, b = 0;
        }
    }
    node() {}
};
node s;
int get_hash(int a[3][3])
{
    int t[9], k = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            t[k++] = a[i][j];
    int cnt = 0;
    int ret = 0;
    for(int i = 0; i < 9; i++)
    {
        cnt = 0;
        for(int j = i + 1; j < 9; j++)
        {
            if(t[i] > t[j])
                cnt++;
        }
        ret += cnt * hsh[8 - i];
    }
    return ret;
}
int bfs(int p)
{
    memset(pre[p], -1, sizeof(pre[p]));
    memset(vis, 0, sizeof(vis));
    node t, next;
    queue<node> que;
    que.push(s);
    pre[p][get_hash(s.maze)] = -2;//将初始状态的值设置为-2
    vis[get_hash(s.maze)] = true;
    while(!que.empty())
    {
        t = que.front();
        que.pop();
        next = t;
        int hash_t = get_hash(t.maze);
        int hash_next;
        memcpy(next.maze, t.maze, sizeof(t.maze));
        for(int i = 0; i < 4; i++)
        {
            next.x = t.x + dir[i][0];
            next.y = t.y + dir[i][1];
            if(next.x < 0 || next.x > 2 || next.y < 0 || next.y > 2)
                continue;
            swap(next.maze[next.x][next.y], next.maze[t.x][t.y]);
            hash_next = get_hash(next.maze);
            if(pre[p][hash_next] == -1)
            {
                vis[hash_next] = true;
                que.push(next);
                pre[p][hash_next] = hash_t;
                ans[p][hash_next] = i;
            }
            swap(next.maze[next.x][next.y], next.maze[t.x][t.y]);
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    s = node("X12345678");
    bfs(0);
    s = node("1X2345678");
    bfs(1);
    s = node("12X345678");
    bfs(2);
    s = node("123X45678");
    bfs(3);
    s = node("1234X5678");
    bfs(4);
    s = node("12345X678");
    bfs(5);
    s = node("123456X78");
    bfs(6);
    s = node("1234567X8");
    bfs(7);
    s = node("12345678X");
    bfs(8);
    char str_a[100], str_b[100];
    int num[100];
    node a, b;
    int cs = 0;
    while(t--)
    {
        scanf("%s", str_a);
        scanf("%s", str_b);
        int p;
        for(int i = 0, j = 0; i < 9; i++)
        {
            if(str_a[i] == 'X')
                p = i;
            else
            {
                num[str_a[i] - '0'] = j++;
            }
        }
        for(int i = 0; i < 9; i++)
        {
            if(str_b[i] == 'X')
                continue;
            str_b[i] = num[str_b[i] - '0'] + '1';
        }
        s = node(str_b);
        int cur = get_hash(s.maze);
        string pat = "";
        while(cur != -2)//逆推，直到找到初始状态
        {
            pat += path[ans[p][cur]];
            cur = pre[p][cur];
        }
        printf("Case %d: %d\n", ++cs, pat.size() - 1);//多加了一个目标状态的操作，所以要删除。
        for(int i = pat.size() - 2; i >= 0; i--)
            printf("%c", pat[i]);
        puts("");
    }
    return 0;
}
```

