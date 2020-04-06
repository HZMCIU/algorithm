### [Recover the Smallest Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704)

### 题意

给出一系列数字，问如何组合这些数字使得组合得到的数字最小

### 思路

通过观察发现，不能仅仅比较字符串之间的字典序。例如`3214` 和`321` 两者较小部分`321`的字典序相同，但是`321`比`3214`更优越，因为`3213214`比`3214321`要小。所以当两个字符串的较小部分相同的时候，假设较小字符长度为`len`，那么就要比较第`len`位和第`0`位的大小，小的优先级高。WA了，改不动，以后再该。

以上是我麻烦的版本，其实只要将两个数字合并，然后比较两种合并顺序的字典序计科。例如，`3214`和`321`，得到两个合并版本`3214321`和`3213214`比较字典序即可。

### WA代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e4 + 10;
const int maxm = 20;
const int inf = 0x3f3f3f3f;
typedef long long ll;
struct node
{
    char str[10];
};
node a[maxn];
bool cmp(node a,node b)
{
    int lena=strlen(a.str);
    int lenb=strlen(b.str);
    int len=min(lena,lenb);
    for(int i=0;i<len;i++)
    {
        if(a.str[i]!=b.str[i])
            return a.str[i]<=b.str[i];
    }
    if(lena>lenb&&a.str[0]>a.str[len])
        return 1;
    else
        return 0;
    if(lena<lenb&&b.str[0]>b.str[len])
        return 0;
    else
        return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].str);
    }
    sort(a,a+n,cmp);
    int first=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;a[i].str[j];j++)
            if(a[i].str[j]=='0'&&first)
            continue;
            else
            {
                putchar(a[i].str[j]);
                first=0;
            }
    }
    if(first)
        puts("0");
    return 0;
}

```

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e4 + 10;
const int maxm = 20;
const int inf = 0x3f3f3f3f;
typedef long long ll;
struct node
{
    char str[10];
};
node a[maxn];
bool cmp(node a,node b)
{
    char s[30]={0};
    char t[30]={0};
    strcat(s,a.str);
    strcat(s,b.str);
    strcat(t,b.str);
    strcat(t,a.str);
    return strcmp(s,t)<=0;
//    int lena=strlen(a.str);
//    int lenb=strlen(b.str);
//    int len=min(lena,lenb);
//    for(int i=0;i<len;i++)
//    {
//        if(a.str[i]!=b.str[i])
//            return a.str[i]<=b.str[i];
//    }
//    if(lena>lenb&&a.str[0]>a.str[len])
//        return 1;
//    else
//        return 0;
//    if(lena<lenb&&b.str[0]>b.str[len])
//        return 0;
//    else
//        return 1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].str);
    }
    sort(a,a+n,cmp);
    int first=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;a[i].str[j];j++)
            if(a[i].str[j]=='0'&&first)
                continue;
            else
            {
                putchar(a[i].str[j]);
                first=0;
            }
    }
    if(first)
        puts("0");
    return 0;
}
```

