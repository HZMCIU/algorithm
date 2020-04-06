### [High School: Become Human ](http://codeforces.com/contest/987/problem/B)

数学题，还是要合理的利用数学的，不能盲目的暴力，还有学会了一个新的函数。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x,y;
    scanf("%lf%lf",&x,&y);
    double t=y*log(x)-x*log(y);
    if(t==0.0) puts("=");
    else if(t>0) puts(">");
    else if(t<0) puts("<");
    return 0;
}

```



