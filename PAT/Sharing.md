### [Sharing](https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920)

### 题意

给出两张链表，找出他们的公共节点

### 思路

刚开始，我是这样考虑的。如果一个点，是两张链表的公共节点的话，那么整个节点的地址一定会在next地址中出现两次。所以直接记录next地址出现的次数，大于两次就是公共节点。然后再加上一个特判，两个链表完全一样。但是WA了

后来，就直接模拟了。首先，标记第一张表中的所有节点，然后遍历第二张表，如果出现第一个第一张表中的节点，那么这个点就是公共节点了

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int nex[maxn];
int fl[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    int s1, s2;
    scanf("%d%d%d", &s1, &s2, &n);
    int a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d %*c %d",&a,&b);
        nex[a]=b;
    }
    int now=s1;
    while(now!=-1)
    {
        fl[now]=1;
        now=nex[now];
    }
    now = s2;
    int ans=-1;
    while(now!=-1)
    {
        if(fl[now]==1)
        {
            ans=now;
            break;
        }
        now=nex[now];
    }
    if(ans==-1)
        printf("-1\n");
    else
        printf("%05d\n",ans);
    return 0;
}
```

### WA代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int nex[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    int s1, s2;
    scanf("%d%d%d", &s1, &s2, &n);
    int s, ne;
    char v;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &s, &v, &ne);
        if(ne != -1)
            nex[ne] += 1;
        if(nex[ne] >=2)
        {
            ans = ne;
        }
    }
    if(s1==s2)
        ans=s1;
    if(ans == -1)
        puts("-1");
    else
        printf("%.5d\n", ans);
    return 0;
}
```

