### [ Heap Paths ](https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552)

### 题意

给出中序遍历序列，判断是否为一个堆。并输出从根到各个叶子节点的路径。

### 思路

根据堆的性质即可判断树中的各个元素是否满足堆的条件。

此外，在DFS的时候判断一个节点是否为叶子节点，需要比较`2*k+1>=n&&2*k+2>=n&&k<n` ，那么这个节点就是叶子节点，**因为叶子节点既没有左孩子，又没有右孩子** ，这个性质在DFS的时候比较有用。

### 坑点 

这道题目由于输入`long long `数据的时候，使用`scanf("%d")`，造成了有一个点没有通过

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
int tree[maxn];
int n;
vector<int> tmppath;
int dfs(int k)
{
    if(k*2+1>=n&&k*2+2>=n)
    {
        if(k<n)
        {
            printf("%d",tmppath[0]);
            for(int i=1;i<tmppath.size();i++)
                printf(" %d",tmppath[i]);
            puts("");
        }
        return 0;
    }
    tmppath.push_back(tree[2*k+2]);
    dfs(2*k+2);
    tmppath.pop_back();
    tmppath.push_back(tree[2*k+1]);
    dfs(2*k+1);
    tmppath.pop_back();
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d",&n);
//    memset(tree,-1,sizeof(tree));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tree[i]);
    }
    bool ismax=true;
    bool ismin=true;
    for(int i=0;i<n;i++)
    {
        if(2*i+1<n&&tree[i]>tree[2*i+1])
            ismin=false;
        if(2*i+2<n&&tree[i]>tree[2*i+2])
            ismin=false;
    }
    for(int i=0;i<n;i++)
    {
        if(2*i+1<n&&tree[i]<tree[2*i+1])
            ismax=false;
        if(2*i+2<n&&tree[i]<tree[2*i+2])
            ismax=false;
    }
    tmppath.push_back(tree[0]);
    dfs(0);
    if(!ismin&&!ismax)
    {
        puts("Not Heap");
    }
    else if(ismax)
        puts("Max Heap");
    else if(ismin)
        puts("Min Heap");
    return 0;
}
```

