### [Power Strings](https://vjudge.net/problem/POJ-2406#author=YaoBIG)

### 题意

求出循环节出现的次数

### 思路

如果循环节就是这个字符串的时候，就直接输出1即可。

### AC代码

```cpp

#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6+100;
const int inf=0x3f3f3f3f;
char pat[maxn];
int next[maxn];
//char sur[maxn];
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
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",pat)&&pat[0]!='.')
    {
        int plen=strlen(pat);
        getnext(plen);
        int len=plen-next[plen-1]-1;
        if(plen%len==0)
            printf("%d\n",plen/len);
        else
            puts("1");
    }
    return 0;
}
```

