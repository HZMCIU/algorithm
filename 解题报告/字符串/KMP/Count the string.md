### [Count the string](https://vjudge.net/problem/HDU-3336#author=cust_acm)

### 题意

求出所有前缀在字符串中匹配的次数

### 思路

+ 所有的前缀至少在字符串中匹配一次
+ 如果一个较短的前缀能够匹配多次，那么一定是**后面所有**较长前缀中的**所有公共前后缀**。所有前缀中的所有公共前后缀的数目加上所有的前缀的数量就是答案了。
+ 举例，`abab` ，前缀`ab`能够匹配2次，`ab`同时也是`abab`前缀的前后缀；`a`能够匹配2次，`a`也是`aba`最长前后缀。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=2e5+100;
const int inf=0x3f3f3f3f;
char str[maxn];
int Next[maxn];
int n;
const int mod=10007;
int getnext(char str[],int len)
{
    Next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=Next[i-1];
        while(str[i]!=str[j+1]&&j>=0)
            j=Next[j];
        if(str[i]==str[j+1])
            Next[i]=j+1;
        else
            Next[i]=-1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len;
        scanf("%d",&len);
        scanf("%s",str);
        getnext(str,len);
        int ans=len;
        for(int i=0;i<len;i++)
        {
            int cur=Next[i];
            //如果一个较短的前缀能够匹配多次，那么一定是后面所有较长前缀中的所有公共前后缀。所有前缀中的所有公共前后缀的数目加上所有的前缀的数量就是答案了。
            while(cur!=-1)
            {
                ans=(ans+1)%mod;
                cur=Next[cur];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

