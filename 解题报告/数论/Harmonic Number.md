### [Harmonic Number](https://vjudge.net/problem/LightOJ-1234)

### 题意

求$\sum\limits_{k=1}^n{\frac{1}{k}}$ ，其中$n\leq10^8$

### 思路

打表，把结果先计算出来，然后存在数组里面。当然，不能把$10^8$个结果全部计算出来，会MLE。而是每隔50个，保存一下结果。这样，不会爆内存，而且每次计算利用已经得到的结果，最多计算50次。

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const long long maxn = 1e8;
const int inf = 0x3f3f3f3f;
typedef long long ll;

double a[maxn/50+50];

void init()
{
    a[0]=0.0;
    double t=0.0;
    for(int i=1;i<=maxn;i++)
    {
        t+=1.0/(1.0*i);
        if(i%50==0)
        {
            a[i/50]=t;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    init();
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        int n;
        scanf("%d",&n);
        double ans=a[n/50];
        for(int i=(n/50)*50+1;i<=n;i++)
            ans+=1.0/(1.0*i);
        printf("Case %d: %.10lf\n",cs,ans);
    }
    return 0;
}
```

