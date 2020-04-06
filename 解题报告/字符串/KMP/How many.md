### [How many](https://vjudge.net/problem/HDU-2609)

### 题意

求出所有不重复（即不能通过旋转得到）字符串的类别个数

### 思路

通过最大最小表示法，找出所有的字符串字典序最小的字符串，然后使用set判重。

### AC代码

```cpp
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int maxn=1e4+100;
const int maxm=2e2+100;
const int inf=0x3f3f3f3f;
typedef long long ll;
char str[maxn][maxm];
char mistr[maxn];
set<string> s;
int getmin(char str[])
{
    int len=strlen(str);
    strncpy(str+len,str,len);
    int i=0,j=1,k=0;
    while(i<len&&j<len)
    {
        k=0;
        while(k<len&&str[(i+k)]==str[(j+k)]) k++;
        if(k>=len) break;
        if(str[(i+k)]>str[(j+k)]) i+=k+1;
        else j+=k+1;
        if(i==j) j++;
    }
    int t=min(i,j);
    strncpy(mistr,str+t,len);
//    printf("%s\n",mistr);
    s.insert(string(mistr));
    return min(i,j);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        s.clear();
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        for(int i=0;i<n;i++)
        {
            getmin(str[i]);
        }
        int ans=s.size();
//        for(auto i:s)
//            cout << i << endl;
        printf("%d\n",ans);
    }
    return 0;
}
```

