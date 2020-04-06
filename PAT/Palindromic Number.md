###[Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608)

### 题意

大整数运算

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int a[maxn];
bool check(string s)
{
    int len=s.length();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-1-i])
            return false;
    }
    return true;
}
string add(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    int len=s.length();
    int c=0;
    int j=0;
    for(int i=len-1;i>=0;i--,j++)
    {
        a[j]=s[i]-'0'+t[i]-'0'+c;
        c=0;
        if(a[j]>9)
            a[j]-=10,c=1;
    }
    if(c)
        a[j++]=1;
    string res;
    for(int i=j-1;i>=0;i--)
    {
        res+=char(a[i]+'0');
    }
    return res;
}
int main()
{
    //freopen("in.txt", "r", stdin);
//    cout << add("67") ;
    string n;
    int k;
    cin >> n;
    cin >> k;
    int cs=0;
    for(int i=1;i<=k;i++)
    {
        if(check(n))
            break;
        n=add(n);
//        cout << n << endl;
        cs++;
    }
    cout << n << endl;
    cout << cs << endl;
    return 0;
}
```

