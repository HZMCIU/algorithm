### [Period](https://vjudge.net/problem/HDU-1358)

### 题意

问一个字符串中的前缀中有多少周期字符串，即存在两个以上的循环节。如果存在，那么输出前缀的长度，以及循环节出现的次数。

### 思路

使用`len=len-next[i]-1`的方法遍历所有的前缀，求出前缀所有的循环节，如果存在，那么输出。

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
int min(int a,int b)
{
    return a>=b?b:a;
}
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
    int plen;
    int cs=1;
    while(~scanf("%d",&plen)&&plen)
    {
        scanf("%s",pat);
        getnext(plen);
        int len;
        printf("Test case #%d\n",cs++);
        for(int i=1;i<plen;i++)
        {
            len=i+1-next[i]-1;
            if((i+1)%len==0&&(i+1)/len>=2)
                printf("%d %d\n",i+1,(i+1)/len);
        }
        puts("");
    }
    return 0;
}
```

