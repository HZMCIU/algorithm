### [String Problem](https://vjudge.net/problem/HDU-3374)

### 题意

求出循环字符串中字典序最小的rank值和字典序最大的rank值。同时输出字符串的循环节。

### 思路

最大最小表示法。

2003年，国家集训队周源论文。

两个循环同构的字符串（不相等）s,t；两个指针i,j分别从字符串起始位置开始移动。

当$s[i+k]!=t[j+k]$的时候，如果$s[i+k]>t[i+k]$的话，那么在$[i,i+k]$这个区间内不存在字典序最小的字符串的开始位置$M(s)$,所以$i+=k+1$，$i$指针后移，继续匹配。反之，如果$s[i+k]<s[j+k]$，那么$j$指针后移$k+1$个单位。

注意，因为s和t是循环同构，但是s和t不是完全相等的。所以i==j的时候j要加一。

如果k的值等于len的话，那么就说明此时的i,j就是$M(s)$，由于题目中要求最小值，所以返回最小值即可。

循环节使用KMP中的next数组即可求解

```cpp
len-next[len-1]-1;
```



### AC代码

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
int next[maxn];
char str[maxn];
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a>b?b:a;
}
int getnext(char str[])
{
    int len=strlen(str);
    next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=next[i-1];
        while(str[i]!=str[j+1]&&j>=0)
            j=next[j];
        if(str[i]==str[j+1])
            next[i]=j+1;
        else
            next[i]=-1;
    }
}
int getmin(char str[])
{
    int len=strlen(str);
    int i=0,j=1,k=0;
    while(i<2*len&&j<2*len)
    {
        k=0;
        while(k<len&&str[(i+k)%len]==str[(j+k)%len]) k++;
        if(k>=len) break;
        if(str[(i+k)%len]>str[(j+k)%len]) i+=k+1;
        else j+=k+1;
        //保证是循环同构的字符串，不相等
        if(i==j) j++;
    }
    return min(i,j);
}
int getmax(char str[])
{
    int len=strlen(str);
    int i=0,j=1,k=0;
    while(i<2*len&&j<2*len)
    {
        k=0;
        while(k<len&&str[(i+k)%len]==str[(j+k)%len]) k++;
        if(k>=len) break;
        if(str[(i+k)%len]>str[(j+k)%len]) j+=k+1;
        else i+=k+1;
        //保证是循环同构的字符串，不相等
        if(i==j)
            j++;
    }
    return min(i,j);
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",str))
    {
        memset(next,0,sizeof(next));
        getnext(str);
        int len=strlen(str);
        int rot=len-next[len-1]-1;
        int times=1;
        if(len%rot==0)
        {
            times=len/rot;
        }
        int a=getmin(str);
        int b=getmax(str);
        printf("%d %d %d %d\n",a+1,times,b+1,times);
    }
    return 0;
}
```

