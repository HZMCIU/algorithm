### [Large Division](https://vjudge.net/problem/LightOJ-1214#author=0)

### 题意

给出两个整数$a,b$。其中$-10^{200}\le a \le 10^{200}$ 。问$a$是否能够被$b$整除。

### 思路

首先毫无疑问，$a$需要存在数组中。那么我们是如何根据字符数组中的值来转化为整型的值的呢？

高位*10+低位，然后迭代运算。在这个过程中，根据模运算定理，我们可以对中间值进行取模操作，这个时候的值还是INT范围内的。

在迭代求值的过程中进行模运算。根据$(a+b)\%c = ((a\%c)+(b\%c)\%c)$ 。

### 总结

在迭代过程中，进行操作。类似参考，快速幂。

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;

char s[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    ll n;
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        scanf("%s %lld",s,&n);
        if(n<0)
            n=-n;
        int len=strlen(s);
        if(len==1&&s[0]=='0')
        {
            printf("Case %d: divisible\n",cs);
            continue;
        }
        ll tmp=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='-')
                continue;
            tmp=tmp*10+s[i]-'0';
            tmp=tmp%n;
        }
        if(tmp==0)
            printf("Case %d: divisible\n",cs);
        else
            printf("Case %d: not divisible\n",cs);
    }
    return 0;
}
```

