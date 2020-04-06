### [Prime Path](https://vjudge.net/problem/POJ-3126)

### 题意

给出两个质数$a,b\in [1000,9999]$  。每次可以对改变$a$中的一个数位，使之成为质数$t$问最少需要多少步才能使得$a$转化为$b$。

### 思路

广搜。质数打表。通过打表发现$[1000,9999]$的质数的个数只有1000个，所以每次所有的复杂度上限为$O(1000)$。使用`vis`数组保证不会重复访问。

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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
const int maxn = 1e4;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
bool is_prime[maxn];
bool prime[maxn];
bool vis[maxn];
int cnt=0;
int a,b;
void init()
{
    for(int i=2;i<maxn;i++)
        is_prime[i]=1;
    for(int i=2;i<maxn;i++)
    {
        if(is_prime[i])
        {
            if(i>1000)
                prime[i]=1;
            for(int j=2*i;j<maxn;j+=i)
                is_prime[j]=0;
        }
    }
}

int bfs()
{
    queue<P> que;
    que.push(make_pair(0,a));
    memset(vis,0,sizeof(vis));
    while(!que.empty())
    {
        P t=que.front();
        que.pop();
        int p=t.second;
        if(vis[p]) continue;
        vis[p]=1;
        if(t.second==b) return t.first;
        int bs=1;
        int k;
        for(int i=1;i<=4;i++)
        {
            int n=p/bs;
            n%=10;
            for(int j=1;j<=9-n;j++)
            {
                k=t.second+bs*j;
                if(prime[k]&&!vis[k])
                {
                    que.push({1+t.first,k});
//                    cout << k << endl;
                }
            }
            for(int j=1;j<=n;j++)
            {
                if(i==4&&j==n) continue;
                k=t.second-bs*j;
                if(prime[k]&&!vis[k])
                {
                    que.push({1+t.first,k});
//                    cout << k <<endl;
                }
            }
            bs*=10;
        }
    }
    return inf;
}
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
//    freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // SUBMIT
    init();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int res=bfs();
        cout << res << endl;
    }
    return 0;
}
```

