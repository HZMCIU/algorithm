### [XOR and OR ](http://codeforces.com/problemset/problem/282/C)

### 题意

定义一个操作：去相邻的两个二进制位$x,y$,定义$p=x\quad xor \quad y,q=x\quad or \quad y$，用$p,q$取代原来的$x,y$或者$y,x$。例如$11$ 可以变成$10$或者$01$。

给出两个二进制字符串$a,b$，问是否有可能对$a$进行多次上述操作使得$a=b$ 。

### 思路

枚举每两位字符可以变化的情况

$00$ : $00$(第一次)

$01$ : $11$（第一次）,$10,01$ （第二次）

$10$ : $11$（第一次），$10,01$（第二次）

$11$：$10,01$ （第一次），$11$(第二次)

从上诉我们可以发现$11,01,10$这三个可以互相转换，$00$无法转化。

$11,01,10$互相转换的性质，可以实现二进制位的增减和移动。

由此，我们猜测只要a，b字符串中含有上诉三个二进制中的一个，我们就可以实现a到b的转化。即，a，b都不能为全零字符串。

### 总结

大胆的猜测

```cpp
#include<bits/stdc++.h>
#define SUBMIT
#define gcd __gcd
#define watl(x) cout << (x) << endl;
#define wats(x) cout << (x) << " ";
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
#endif
    string a,b;
    while(cin>>a>>b)
    {
        if(a.length()!=b.length())
        {
            cout << "NO" << endl;
            continue;
        }
        bool fa=false,fb=false;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='1') fa=1;
            if(b[i]=='1') fb=1;
        }
        if(fa&&fb) cout << "YES" << endl;
        else if(a==b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

```

