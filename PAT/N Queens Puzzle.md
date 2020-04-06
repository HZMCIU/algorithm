### [N Queens Puzzle](https://pintia.cn/problem-sets/994805342720868352/problems/994805348915855360)

### 题意

判断N皇后是否合法

### 思路

使用`digonal` 数组来记录对角线最下方所在的行数，用此来唯一标记一条对角线。如果这条对角线被占用，那么久判定为出现冲突。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int digonal[maxn];
int row[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        scanf("%d",&n);
        memset(digonal,0,sizeof(digonal));
        memset(row,0,sizeof(row));
        bool fail=false;
        int r;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&r);
            if(row[r])
                fail=true;
            if(digonal[r+i])
                fail=true;
            row[r]=true;
            digonal[r+i]=true;
        }
        if(fail)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
```

