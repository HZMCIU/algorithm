### [Kuchiguse ](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)

### 题意

找公共后缀，暴力，但是很奇妙的WA了，然后又很奇妙的A了

### WA1代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;

string s[200];
int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    cin.ignore(1);
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i],'\n');
        reverse(s[i].begin(),s[i].end());
    }
    int ans=0;
    for(int i=0;;i++)
    {
        bool f=1;
        for(int j=0;j<n;j++)
        {
            //超出了最短字符串的长度
            if(s[j].length()<i)
            {
                f=0;
                break;
            }
            if(s[j][i]!=s[0][i])
            {
                f=0;
                break;
            }
        }
        if(f)
            ans++;
        else
            break;
    }
    if(ans==0)
        puts("nai");
    else
    {
        for(int i=ans-1;i>=0;i--)
            putchar(s[0][i]);
    }
	return 0;
}
```

### WA代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;

string s[200];
int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    cin.ignore(1);
    int len=inf;
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i],'\n');
        reverse(s[i].begin(),s[i].end());
        //直接找最短字符串的长度
        len=min(len,int(s[i].length()));
    }
    int ans=0;
    for(int i=0;i<len;i++)
    {
        bool f=1;
        for(int j=0;j<n;j++)
        {
            //过滤空格，emmm
            if(s[j][i]!=s[0][i]||s[j][i]==' ')
            {
                f=0;
                break;
            }
        }
        if(f)
            ans++;
        else
            break;
    }
    if(ans==0)
        puts("nai");
    else
    {
        for(int i=ans-1;i>=0;i--)
            putchar(s[0][i]);
    }
	return 0;
}
```



### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;

string s[200];
int main()
{
   // freopen("in.txt","r",stdin);
   // 很迷的一道题
    int n;
    scanf("%d",&n);
    cin.ignore(1);
    int len=inf;
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i],'\n');
        reverse(s[i].begin(),s[i].end());
        len=min(len,int(s[i].length()));
    }
    int ans=0;
    for(int i=0;i<len;i++)
    {
        bool f=1;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]!=s[0][i])
            {
                f=0;
                break;
            }
        }
        if(f)
            ans++;
        else
            break;
    }
    if(ans==0)
        puts("nai");
    else
    {
        for(int i=ans-1;i>=0;i--)
            putchar(s[0][i]);
    }
	return 0;
}
```

