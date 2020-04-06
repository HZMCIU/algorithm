### [Blue Jeans](https://vjudge.net/problem/UVALive-3628)

### 题意

求出所有字符串中最长的公共子串，如果有多个最长公共子串，输出字典序最小的哪一个

### 思路

枚举第1个字符串的所有长度的子串，然后使用KMP取匹配其他的字符串，保存最长，字典序最小的答案。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100;
const int inf=0x3f3f3f3f;
char ans[maxn];
int Next[maxn];
char str[maxn][maxn];
int n;
int getnext(char str[],int len)
{
    Next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=Next[i-1];
        while(str[i]!=str[j]&&j>=0)
            j=Next[j];
        if(str[i]==str[j+1])
            Next[i]=j+1;
        else
            Next[i]=-1;
    }
    return 0;
}
int kmp(char pat[],char str[],int plen,int slen)
{
    int p_i=0,s_i=0;
    while(p_i<plen&&s_i<slen)
    {
        if(pat[p_i]==str[s_i])
        {
            s_i++;
            p_i++;
        }
        else
        {
            if(p_i==0)
                s_i++;
            else
                p_i=Next[p_i-1]+1;
        }
    }
    if(p_i==plen)
        return 1;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    char pat[maxn];
    while(t--)
    {
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        int len=strlen(str[0]);
        for(int i=0;i<len;i++)
        {
            strcpy(pat,str[0]+i);
            getnext(pat,strlen(pat));
            for(int j=1;j<=strlen(pat);j++)
            {
                bool f=1;
                for(int k=1;k<n;k++)
                {
                    if(kmp(pat,str[k],j,strlen(str[k]))==0)
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                {
                    char tmp[maxn];
                    strncpy(tmp,pat,j);
                    tmp[j]=0;
                    if(strlen(ans)<j)
                    {
                        strncpy(ans,pat,j);
                        ans[j]=0;
                    }
                    else if(strlen(ans)==j&&strcmp(ans,tmp)>0)
                    {
                        strncpy(ans,pat,j);
                        ans[j]=0;
                    }
                }
            }
        }
        if(strlen(ans)<3)
            puts("no significant commonalities");
        else
            printf("%s\n",ans);
    }
    return 0;
}
```

