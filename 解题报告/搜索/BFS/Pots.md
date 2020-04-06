### [Pots](https://cn.vjudge.net/problem/POJ-3414#author=cxsys_)

### 题意

问最少需要多少操作才能使得两个容器中有一个能够装满水。并且输出如何**倒水**的方式。

### 思路

广搜。使用了**前驱节点**来记录该节点之前的节点。当找到了答案的时候，通过指针回溯找到路径。使用`op`标志来标记`DROP,FILL,POUR`六种可能。

### 代码

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define SUBMIT
#define gcd  __gcd
#define watl(x) cout << (x) << endl
#define wats(x) cout << (x) << " "
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int a, b, c;
struct node
{
    bool vis;
    int step;
    int op;
    node * pre;//使用指针记录上一个状态的位置
    node(): pre(NULL), op(0), step(0), vis(0) {}
};
node st[maxn][maxn];
node *ans;//记录最后一个状态的位置
int bfs()
{
    queue<P> que;
    que.push(make_pair(0, 0));
    while(!que.empty())
    {
        P t = que.front();
        que.pop();
        int ta = t.first;
        int tb = t.second;
        int inc;
        if(ta == c || tb == c)
        {
            ans = &st[ta][tb];
            return st[ta][tb].step;
        }
        if(st[ta][tb].vis)
            continue;
        st[ta][tb].vis = 1;
        //fill 1
        if(!st[a][tb].vis)
        {
            que.push(make_pair(a, tb));
            st[a][tb].op = 1;
            st[a][tb].pre = &st[ta][tb];
            st[a][tb].step = st[a][b].step + 1;
        }
        //fill 2
        if(!st[ta][b].vis)
        {
            que.push(make_pair(ta, b));
            st[ta][b].op = 2;
            st[ta][b].pre = &st[ta][tb];
            st[ta][b].step = st[ta][tb].step + 1;
        }
        //drop 1
        if(!st[0][tb].vis)
        {
            que.push(make_pair(0, tb));
            st[0][tb].op = 3;
            st[0][tb].pre = &st[ta][tb];
            st[0][tb].step = st[ta][tb].step + 1;
        }
        //drop 2
        if(!st[ta][0].vis)
        {
            que.push(make_pair(ta, 0));
            st[ta][0].op = 4;
            st[ta][0].pre = &st[ta][tb];
            st[ta][0].step = st[ta][tb].step + 1;
        }
        //pour 2 to 1
        inc = min(a - ta, tb);
        int tta = ta + inc;
        int ttb = tb - inc;
        if(tta >= 0 && ttb >= 0 && !st[tta][ttb].vis)
        {
            que.push(make_pair(tta, ttb));
            st[tta][ttb].op = 5;
            st[tta][ttb].pre = &st[ta][tb];
            st[tta][ttb].step = st[ta][tb].step + 1;
        }
        //pour 1 to 2
        inc = min(ta, b - tb);
        tta = ta - inc;
        ttb = tb + inc;
        if(tta >= 0 && ttb >= 0 && !st[tta][ttb].vis)
        {
            que.push(make_pair(tta, ttb));
            st[tta][ttb].op = 6;
            st[tta][ttb].pre = &st[ta][tb];
            st[tta][ttb].step = st[ta][tb].step + 1;
        }
    }
    return -1;
}
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // SUBMIT
    cin >> a >> b >> c;
    int ret = bfs();
    if(ret == -1)
    {
        cout << "impossible" << endl;
    }
    else
    {
        int step = 0;
        vector<int> show;
        //通过指针回溯，找到路径。
        while(1)
        {
            show.push_back(ans->op);
            step += 1;
            ans = ans->pre;
            if(ans == NULL)
                break;
        }
        cout << step - 1 << endl;
        for(int i = show.size() - 1; i >= 0; i--)
        {
            if(show[i] == 1)
                cout << "FILL(1)" << endl;
            else if(show[i] == 2)
                cout << "FILL(2)" << endl;
            else if(show[i] == 3)
                cout << "DROP(1)" << endl;
            else if(show[i] == 4)
                cout << "DROP(2)" << endl;
            else if(show[i] == 5)
                cout << "POUR(2,1)" << endl;
            else if(show[i] == 6)
                cout << "POUR(1,2)" << endl;
        }
    }
    return 0;
}
```

