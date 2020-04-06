###[Oulipo](https://vjudge.net/problem/HDU-1686#author=2015061210)

### 题意

模式串出现的次数，一个字符能够在多个模式串中出现。

例如在`ABABABA`中匹配`ABA`，那么一共匹配了3次。

但是不算重复的话，出现了2次。

### 思路

改写KMP。每当匹配到一个模式串的时候，不立刻返回，而是使用`next`数组进行下一个字符的匹配，如果不匹配，那么模式串就进行指针的回溯。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000010;
const int inf=0x3f3f3f3f;
char pat[maxn];
int next[maxn];
char sur[maxn];
int getnext(int len)
{
    next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=next[i-1];
        while(pat[j+1]!=pat[i]&&j>=0)
            j=next[j];
        if(pat[j+1]==pat[i])
            next[i]=j+1;
        else
            next[i]=-1;
    }
    return 0;
}
int kmp(int slen,int plen)
{
    int s_i=0,p_i=0;
    int ret=0;
    while(s_i<slen)
    {
        if(pat[p_i]==sur[s_i])
        {
            s_i++;
            p_i++;
            //继续进行匹配
            if(p_i==plen)
            {
                ret++;
            }
        }
        else
        {
            if(p_i==0)
                s_i++;
            else
                p_i=next[p_i-1]+1;
        }
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int plen;
        int slen;
        scanf("%s",pat);
        scanf("%s",sur);
        plen=strlen(pat);
        slen=strlen(sur);
        getnext(plen);
        int ans=kmp(slen,plen);
        printf("%d\n",ans);
    }
    return 0;
}
```

