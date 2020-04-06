## [Sonya and Exhibition](http://codeforces.com/contest/1004/problem/B)

题意

找出一个二进制字符串组合，使得每一段0的个数的乘积和1的个数的乘积最大。0101010....这一字符串就是最大的。

总结

这类题目不能被题意迷惑，要自己找规律，不能使用题目里的规则。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%*d%*d");
    }
    for(int i=1;i<=n;i++)
    {
        //输出01字符串
        if(i&1) printf("0"); 
        else printf("1");
    }
    return 0;
}
```



