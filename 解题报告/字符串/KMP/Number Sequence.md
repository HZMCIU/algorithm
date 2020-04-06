### [Number Sequence](https://vjudge.net/problem/HDU-1711#author=a2788016970)

### 题意

求出匹配串的位置

### 思路

KMP模板题。初次使用KMP。

`next[i]`数组表示`i-1`为最长公共前缀的数量-1。

当失配的时候，模式串指针`p_i=next[p_i-1]-1` 来进行回溯。

KMP的整个算法的思路就是基础模式串的对称的特点进行的。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6+100;
const int inf=0x3f3f3f3f;
char pat[maxn];
int next[maxn];
char sur[maxn];
int ans=0;
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
}
int kmp(int slen,int plen)
{
    int s_i=0,p_i=0;
    while(s_i<slen&&p_i<plen)
    {
        if(pat[p_i]==sur[s_i])
        {
            s_i++;
            p_i++;
        }
        else
        {
            if(p_i==0)
                s_i++;
            else
                //失配，指针回溯
                p_i=next[p_i-1]+1;
        }
    }
    return p_i==plen?(s_i-plen+1):-1;
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

    }
    return 0;
}
```

