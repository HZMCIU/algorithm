###[Palindrome](https://vjudge.net/problem/POJ-3974)

### 题意

求最长回文串。

### 思路

Manacher模板题

### AC代码

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e6+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
char str[maxn];
char tmp[maxn<<1];
int Len[maxn<<1];
int manacher(char str[])
{
    int len=strlen(str);
    int ret=0;
    tmp[0]='*';
    for(int i=1;i<=2*len;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=str[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';
    tmp[2*len+3]=0;

    int mx=0,po=0,ans=0;
    for(int i=2;tmp[i];i++)
    {
        if(mx>i)
            Len[i]=min(Len[2*po-i],mx-i);
        else
            Len[i]=1;
        while(tmp[i-Len[i]]==tmp[i+Len[i]])
        {
            Len[i]++;
        }
        if(Len[i]+i>mx)
        {
            mx=Len[i]+i;
            po=i;
        }
        ret=max(ret,Len[i]-1);
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    int cs=1;
    while(~scanf("%s",str))
    {
        if(strcmp(str,"END")==0)
            break;
        int ans=manacher(str);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
```

