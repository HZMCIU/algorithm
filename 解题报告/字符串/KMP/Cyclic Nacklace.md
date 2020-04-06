### [Cyclic Nacklace](https://vjudge.net/problem/HDU-3746#author=SCU2018)

### 题意

问在字符串后面补充多少个字符，才能使字符串变成两个以上的循环节。

例如`pip`后只要补充一个`i`就能够变成两个由`pi`循环节组成的字符串。

在这里循环节应当保证使长度最小的字符串，例如`abcabcab`中的循环节是`abc`而不是`abcabc`。

### 思路

KMP中的`next`数组的含义就是最大公共前后缀的长度。

例如`next[i]`表示子串`substr[0..i]`的**最长公共前后缀长度-1**。也表示了和`str[i]`匹配的字符在数组中的位置，当然如果是`-1`那么说明不存在匹配的字符。

如果公共前缀和公共后缀没有重复的地方，那么显然循环节的长度就是`plen-(next[plen-1]+1)` 。即，减去公共后缀，那么字符串中剩下的就是循环节了。

字符串`“pip”` ，`next`数组是`-1,-1,0`，循环节的长度`3-(0+1)=2,"pi"`。

但是如果公共前后缀出现重叠

字符串`“abcabcabca”` ,公共前后缀就出现了重叠。可以发现，如果出现重叠，重叠的部分均为循环节里的内容。所以这时也只需要减去后缀的长度，就能获得循环节的长度了。

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
        {
            next[i]=j+1;
        }
        else
        {
            next[i]=-1;
        }
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",pat);
        int plen=strlen(pat);
        int ret=getnext(plen);
        int len=plen-next[plen-1]-1;
//        for(int i=0;i<plen;i++)
//            printf("%d ",next[i]);
//        puts("");
//        printf("%d\n",len);
        if(plen%len==0&&plen/len>=2)
            puts("0");
        else
        {
            printf("%d\n",len-plen%len);
        }
    }
    return 0;
}
```

