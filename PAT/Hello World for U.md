### [Hello World for U ](https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416)

### 题意

将字符串转化为U型，并且长和宽要尽可能接近，并且底边尽可能大

### 思路

将字符串的长度加2，这样就得到了U型字符串的周长了。周长/3就得到了侧边的长度，底边的长度就可以得到了

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 5e2+10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
char ch[maxn][maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    char str[maxn];
    scanf("%s",str);
    int len=strlen(str)+2;
    int n=len/3;
    int m=len-2*n;
    int cnt=0;
    for(int i=0;i<n;i++)
        ch[i][0]=str[cnt++];
    for(int j=1;j<m-1;j++)
        ch[n-1][j]=str[cnt++];
    for(int i=n-1;i>=0;i--)
        ch[i][m-1]=str[cnt++];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ch[i][j]!='\0')
                putchar(ch[i][j]);
            else
                putchar(' ');
        }
        puts("");
    }
    return 0;
}
```

