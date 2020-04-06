### [ Cut Integer](https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072)

### 题意

显然

### 思路

显然

### 坑点

**浮点错误** ，除以0或者模0的情况

### WA代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

ll n,z;
ll pow(int k)
{
    ll ret=1;
    for(int i=0;i<k;i++)
        ret*=10;
    return ret;
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        char str[100];
        scanf("%s",str);
        sscanf(str,"%lld",&z);
        ll base=pow(strlen(str)/2);
        ll a,b;
        a=z%base;
        b=z/base;
        if(z%(a*b)==0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
```

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

ll n,z;
ll pow(int k)
{
    ll ret=1;
    for(int i=0;i<k;i++)
        ret*=10;
    return ret;
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        char str[100];
        scanf("%s",str);
        sscanf(str,"%lld",&z);
        ll base=pow(strlen(str)/2);
        ll a,b;
        a=z%base;
        b=z/base;
        if(a==0||b==0)
            puts("No");
        else if(z%(a*b)==0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
```

