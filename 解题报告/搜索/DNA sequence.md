### [DNA sequence ](https://cn.vjudge.net/problem/HDU-1560#author=zmyhh)

### 题意

找出一个DNA序列，是的题目中给出的子序列均为这个序列的子序列。

### 思路

由于未给定求解的序列的上限，所以状态空间无限大。采用**迭代加深搜索**，即逐步加大搜索的深度。

一个剪枝需要注意，如果已走的步数加上最少要走的步数大于上限的话，那么问题无解。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
char str[20][20];
char dna[] = {'A', 'C', 'G', 'T'};
int pos[20];
int len[20];
int t;
int n;
int ans;
vector<char> tmp;
int dfs(int dep, int lim, int pos[])
{
    if(dep > lim) return 0;//超过给定的上限，就返回
    if(ans != -1) return 0;//如果已经找到答案
    int ns = 0;//下一步，最小要走多少步
    for(int i = 0; i < n; i++)
    {
        ns = max(ns, len[i] - pos[i]);
    }
    if(dep + ns > lim) return 0;//要走的步数加上，已走的步数超过上限
    if(ns == 0)
    {
        ans = dep;
//        for(int i = 0; i < tmp.size(); i++)
//            printf("%c", tmp[i]);
//        puts("");
        return 0;
    }
    int tmp_pos[20];
    for(int i = 0; i < 4; i++)
    {
        bool flag = 0;
        int j;
        for(j = 0; j < n; j++)
        {
            if(str[j][pos[j]] == dna[i])
            {
                flag = true;
                tmp_pos[j] = pos[j] + 1;
            }
            else tmp_pos[j] = pos[j];
        }
        if(flag)
        {
            tmp.push_back(dna[i]);
            dfs(dep + 1, lim, tmp_pos);
            tmp.pop_back();
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--)
    {
        ans = -1;
        scanf("%d", &n);
        int lim = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
            lim = max(lim, len[i]);
        }
        int pos[20] = {0};
        while(ans == -1)
        {
            dfs(0, lim, pos);
            ++lim;
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

