### [Best Reward](https://vjudge.net/problem/HDU-3613#author=0)

### 题意

给出一个字符串，切割这个字符串，使之成为两个部分。每个字母对应了一个价值，当且仅当这个字符串为回文串的时候才有价值。问如何切割字符串使得价值总和最大。

### 思路

https://blog.csdn.net/piaocoder/article/details/51057419

首先，用Manacher算法求出每个字符对应的最长回文串的长度。

因为切割后的字符串只有两个部分，所以通过计算**前缀和**可以快速得出每个子串对应的价值。

然后枚举每个切割点，得出最优的切割方案。

注意：必须要进行切割，如果没有切割，会出错。例如样例1中的`aba` 。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
char str[maxn];
char tmp[maxn<<1];
int Len[maxn<<1];
int pre[maxn];
int suf[maxn];
int val[30];
int sum[maxn];
int manacher(char str[])
{
    int len=strlen(str);
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
            Len[i]++;
        if(Len[i]+i>mx)
        {
            mx=Len[i]+i;
            po=i;
        }
        //在转化串T中,T[1->2*Len[i]-1]为回文串，
        //那么，对应于原串S中，S[1->Len[i]-1]为回文串
        if(i-Len[i]==0)
            pre[Len[i]-1]=1;
        //在转化串T中,T[i-Len[i]+1->2*len+1]为回文串，
        //那么，对应于原串S中，S[len-2*Len[i]+1->len]为回文串
        if(i+Len[i]==2*len+2)
            suf[Len[i]-1]=1;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        for(int i=0;i<26;i++)
            scanf("%d",&val[i]);
        scanf("%s",str);
        int len=strlen(str);
        for(int i=1;i<=len;i++)
        {
            sum[i]=sum[i-1]+val[str[i-1]-'a'];
        }
        manacher(str);
        int ans=0;
        //必须进行切割，i=[1,len)
        for(int i=1;i<len;i++)
        {
            int tmp=0;
            if(pre[i])
                tmp+=sum[i];
            if(suf[len-i])
                tmp+=sum[len]-sum[i];
            if(tmp>ans)
                ans=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

