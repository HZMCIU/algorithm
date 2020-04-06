### [Eight](https://cn.vjudge.net/problem/HDU-1043#author=HUO_ZHE)

### 题意

求解将九宫格上的八个数码移初始状态$\begin{matrix}1 &2&3\\4&5&6\\7&8&0\end{matrix}$ 所需要的步骤

### 思路

全程看题解。使用**A*搜索**，**曼哈顿距离**，八数码相关的**逆序数对**结论，**康托展开**来对一个序列进行hash。

加入评估函数发$f=g+h$。其中$g$为已经走过的步数，$h$为和目标状态的曼哈顿距离，$x,y$轴绝对值距离差值之和，$|x_1-x_2|+|y_1-y_2|$ 。

八数码问题的相关结论：

1. 无论八数码如何移动，不会改变该序列的逆序数的**奇偶性**。
2. $\begin{matrix}1 &2&3\\4&5&6\\7&8&0\end{matrix}$ 序列的逆序数对为**偶数**
3. 偶序列的可以经过若干步移动到达 **任意**一个偶序列，奇序列同理。
4. 综上，如果一个序列是偶序列的话，那么**必定有解**，即，可以通过若干步的移动到达初始状态。若一个序列的逆序数为奇数，**必定无解**。

**康托展开**

康托展开是一个**全排列到自然数**的双射。

$X=a_n(n-1)!+a_{n-1}(n-2)!+...+a_10!$

康托展开的最大值为$n!$。当如此排列时$n,n-1,n-2,...,1$  。

例如，$3 5 7 4 1 2 9 6 8 $展开为 $98884$。因为$X=2*8!+3*7!+4*6!+2*5!+0*4!+0*3!+2*2!+0*1!+0*0!=98884$.

排列的第一位是3，比3小的数有两个，以这样的数开始的排列有8!个，因此第一项为2*8!

排列的第二位是5，比5小的数有1、2、3、4，由于3已经出现，因此共有3个比5小的数，这样的排列有7!个，因此第二项为3*7!

以此类推，直至0*0!

```cpp
#include  <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
struct node
{
    int maze[3][3];
    int _hash;
    int h, g;
    int x, y;
    operator<(const node a)const
    {
        return a.h != h ? h > a.h : g > a.g;
    }
};
int vis[maxn];
int pre[maxn];
int hsh[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0}; //rlud
const int destinate = 322560;
int get_hash(int a[3][3])
{
    int t[9];
    int k = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            t[k++] = a[i][j];
    int ret = 0;
    int cnt = 0;
    for(int i = 0; i < 9; i++)
    {
        cnt = 0;
        for(int j = 0; j < i; j++)
            if(t[i] < t[j])cnt++;
        ret += cnt * hsh[i];
    }
    return ret;
}
int get_h(int a[3][3])
{
    int ret = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(a[i][j])
            {
                ret += abs(i - (a[i][j] - 1) / 3) + abs(j - (a[i][j] - 1) % 3);
            }
        }
    }
    return ret;
}
bool ok(int a[3][3])
{
    int t[9], k = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            t[k++] = a[i][j];
    int ret = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < i; j++)
            if(t[i] < t[j] && t[i] && t[j]) ret++;
    }
    return !(ret & 1);
}
bool astar(node a)
{
    priority_queue<node> que;
    node t;
    int tmp_maze[3][3];
    node add;
    que.push(a);
    while(!que.empty())
    {
        t = que.top();
        que.pop();
        if(t._hash == destinate) return 1;
        int tx, ty;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                tmp_maze[i][j] = t.maze[i][j];
        for(int i = 0; i < 4; i++)
        {
            tx = t.x + dir[i][0];
            ty = t.y + dir[i][1];
            if(tx < 0 || tx >= 3 || ty < 0 || ty >= 3) continue;
            swap(tmp_maze[tx][ty], tmp_maze[t.x][t.y]);
            int _hash = get_hash(tmp_maze);
            if(vis[_hash] == -1 && ok(tmp_maze))
            {
                memcpy(add.maze, tmp_maze, sizeof(tmp_maze));
                add.g = t.g + 1;
                add._hash = _hash;
                add.h = get_h(tmp_maze);
                add.x = tx;
                add.y = ty;
                que.push(add);
                vis[_hash] = i;
                pre[add._hash] = t._hash;
            }
            swap(tmp_maze[tx][ty], tmp_maze[t.x][t.y]);
        }
    }
    return false;
}
int main()
{
    node t;
    char str[100];
    while(gets(str) != NULL)
    {
        int num;
        int len = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                while(!('0' <= str[len] && str[len] <= '9' || str[len] == 'x'))
                    len++;
                if(str[len] == 'x')
                {
                    t.x = i;
                    t.y = j;
                    t.maze[i][j] = 0;
                }
                else t.maze[i][j] = str[len] - '0';
                len++;
            }
        }
        if(ok(t.maze))
        {
            memset(vis, -1, sizeof(vis));
            memset(pre, -1, sizeof(pre));
            t._hash = get_hash(t.maze);
            t.g = 0;
            t.h = get_h(t.maze);
            int cur = destinate;
            int _hash = get_hash(t.maze);
            vis[_hash] = -2;
            astar(t);
            string ans;
            while(pre[cur] != -1)
            {
                if(vis[cur] == 0)
                    ans.push_back('r');
                else if(vis[cur] == 1)
                    ans.push_back('l');
                else if(vis[cur] == 2)
                    ans.push_back('u');
                else if(vis[cur] == 3)
                    ans.push_back('d');
                cur = pre[cur];
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
        else
        {
            puts("unsolvable");
        }
    }
    return 0;
}
```



