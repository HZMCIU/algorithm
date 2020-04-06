### [Girls' research](https://vjudge.net/problem/HDU-3294#author=0)

### 题意

给出一个字符和一个字符串，将字符串中的每个字符平移若干个单位后，求出处理后的字符串的最长公共回文串。输出回文串的开始和结束位置。以及输出回文串。

### 思路

转化串T和原串S位置的对应关系。Manacher算法。

```cpp
st= (i-Len[i]+2)/2-1;
en=(i+Len[i]-2)/2-1;
```

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
int st;
int en;
int manacher(char str[])
{
    int len=strlen(str);
    tmp[0]='$';
    for(int i=1;i<=2*len;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=str[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='*';
    tmp[2*len+3]=0;

    int mx=0,po=0,ans=0;
    for(int i=2;tmp[i];i++)
    {
        if(mx>i)
            Len[i]=min(Len[2*po-i],mx-i);
        else
            Len[i]=1;
        while(tmp[i-Len[i]]==tmp[i+Len[i]])
            Len[i]++;
        if(i+Len[i]>mx)
        {
            mx=Len[i]+i;
            po=i;
        }
        if(Len[i]-1>ans)
        {
            ans=Len[i]-1;
            st= (i-Len[i]+2)/2-1;
            en=(i+Len[i]-2)/2-1;
        }
    }
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    char t[20];
    while(~scanf("%s%s",t,str))
    {
        int diff='a'-t[0];
        int t;
        for(int i=0;str[i];i++)
        {
            t=(str[i]-'a'+diff)%26;
            str[i]=t<0?t+26+'a':t+'a';
        }
        int ans=manacher(str);
        if(ans>=3)
        {
            printf("%d %d\n",st,en);
            for(int i=st;i<=en;i++)
                putchar(str[i]);
            puts("");
        }
        else
        {
            puts("No solution!");
        }
    }
    return 0;
}
```

