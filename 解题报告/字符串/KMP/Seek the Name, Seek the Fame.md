### [Seek the Name, Seek the Fame](https://vjudge.net/problem/POJ-2752#author=zkAndrew)

### 题意

求出一个字符串所有的公共前缀和公共后缀的长度。

### 思路

KMP算法法`next[i]`表示第i位字符公共前缀后缀数-1。显然，最大的公共前后缀位`next[plen-1]+1`，那么如何找到次小的前后缀呢。可以发现，求解次长的前后缀，就是在最大的前后缀中求解最大的前后缀，因为前缀和后缀是相等的。

例如字符串`alala` 最大的前后缀为`ala`，寻找第二大前后缀时，就是在前缀`ala`中寻找前缀，在后缀`ala`中寻，找后缀，因为此时前后缀均为`ala`，那么就相当于在`ala`中寻找最大前后缀。使用`next`数组不断进行回溯就能得到答案。

显然，当整个字符串也是公共前后缀。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+100;
const int inf=0x3f3f3f3f;
char pat[maxn];
int Next[maxn];
int ans[maxn];
int cnt=0;
//char sur[maxn];
int getnext(int len)
{
    Next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=Next[i-1];
        while(pat[j+1]!=pat[i]&&j>=0)
            j=Next[j];
        if(pat[j+1]==pat[i])
            Next[i]=j+1;
        else
            Next[i]=-1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",pat))
    {
        cnt=0;
        int plen=strlen(pat);
        getnext(plen);
        int n=plen-1;
        while(Next[n]!=-1)
        {
            ans[cnt++]=Next[n]+1;
            n=Next[n];
        }
        ans[cnt++]=plen;
        sort(ans,ans+cnt);
        for(int i=0;i<cnt;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
```

