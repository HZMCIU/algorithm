### [A Delayed Palindrome](https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624)

### 题意

大数运算

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e3+200;
typedef long long ll;
typedef pair<int,int> P;

int p[maxn],q[maxn];
string add(string a,string b)
{
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    int len1=a.length(),len2=b.length();
    int len=max(len1,len2);
    for(int i=len1-1,j=0;i>=0;i--,j++)
        p[j]=a[i]-'0';
    for(int i=len2-1,j=0;i>=0;i--,j++)
        q[j]=b[i]-'0';
    int c=0;
    for(int i=0;i<len;i++)
    {
        q[i]=q[i]+p[i]+c;
        c=0;
        if(q[i]>=10)
        {
            c=q[i]/10;
            q[i]%=10;
        }
    }
    if(c==1)
        q[len]=1,len++;
    string res;
    for(int i=0;i<len;i++)
        res+='0'+q[i];
    reverse(res.begin(),res.end());
    return res;
}
bool check(string &str)
{
    int len=str.length();
    for(int i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-1-i])
            return false;
    }
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    string str;
    cin>> str;
    int i;
    for(i=1;i<=10;i++)
    {
        if(check(str))
            break;
        string b=str;
        reverse(b.begin(),b.end());
        cout << str << " + " << b << " = " << add(str,b) << endl;
        str=add(str,b);
    }
    if(!check(str))
    {
        puts("Not found in 10 iterations.");
    }
    else
    {
        cout << str << " is a palindromic number." << endl;
    }
    return 0;
}
```

