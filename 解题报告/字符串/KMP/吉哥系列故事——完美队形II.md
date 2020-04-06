###[吉哥系列故事——完美队形II](https://vjudge.net/problem/HDU-4513#author=hzoi2017_wty)

### 题意

求出最长回文子串的长度，但是要保证回文串是向两侧下降的。

### 思路

改写Manacher算法。保证梯度下降即可。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
int str[maxn];
int tmp[maxn<<1];
int Len[maxn<<1];
int manacher(int str[],int len)
{
    int ret=0;
    tmp[0]=-2;
    for(int i=1;i<=2*len;i+=2)
    {
        tmp[i]=-1;
        tmp[i+1]=str[i/2];
    }
    tmp[2*len+1]=-1;
    tmp[2*len+2]=-3;
    tmp[2*len+3]=-4;

    int mx=0,po=0,ans=0;
    for(int i=2;tmp[i]!=-4;i++)
    {
        if(mx>i)
            Len[i]=min(Len[2*po-i],mx-i);
        else
            Len[i]=1;
        while(tmp[i-Len[i]]==tmp[i+Len[i]])
        {
            //原串S位于转化串T的偶数位置。
            if((i+Len[i])%2==0)
            {
                if(tmp[Len[i]+i]<=tmp[Len[i]+i-2])
                    Len[i]++;
                else
                    break;
            }
            else
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
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&str[i]);
        int ans=manacher(str,n);
        printf("%d\n",ans);
    }
    return 0;
}
```

