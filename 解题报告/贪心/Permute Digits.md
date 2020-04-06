### [Permute Digits ](http://codeforces.com/contest/915/problem/C)

### 题意

给出两个数a,b。求出a的各个数位经过重组后，不大于b的最大值。

### 思路

1. 如果a的位数小于b的位数，那么将a的数位降序排序一遍即可。
2. a的位数等于b的位数，从最高为位开始逐位换上未使用过的较大的数字，并将后面的数位进行升序排序，如果a小于b，那么处理下一位。以此类推。

### 总结

从最大值里面找较小值，不断迭代。

```cpp
#include <bits/stdc++.h>
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
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main()
{
#ifndef SUBMIT
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif // SUBMIT
#ifdef SUBMIT
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // SUBMIT
    string a, b;
    while(cin >> a >> b)
    {
        sort(a.begin(), a.end());
        if(b.length() > a.length())//a的位数小于b的位数
        {
            reverse(a.begin(), a.end());
        }
        else
        {
            int len = a.length();
            string t;
            for(int i = 0; i < len; i++)
            {
                t = a;//a的备份
                for(int j = len - 1; j > i; j--)
                {
                    swap(a[j], a[i]);//将未使用的最大的数，换到改为该位
                    sort(a.begin() + i + 1, a.end());//保证下一次取到的值是最大的
                    if(a.compare(b) > 0)
                    {
                        a = t;
                    }
                    else break;//如果小于那么该位就完成
                }
            }
        }
        cout << a << endl;
    }
    return 0;
}

```

