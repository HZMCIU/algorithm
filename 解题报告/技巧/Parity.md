### [Parity](http://codeforces.com/contest/1110/problem/A)

### 题意

判断奇偶性

### 思路

利用乘法和加法模运算的性质,tourist,orz

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e3;
const int inf=0x3f3f3f3f;
typedef long long ll;
int mi[maxn];
int mx[maxn];
int main()
{
	freopen("in.txt","r",stdin)	;
	int b,k;
	cin>>b>>k;
	vector<int> a(k);
	for(int i=0;i<k;i++)
		cin>>a[i];
	int s=0,p=1;
	for(int i=k-1;i>=0;i--)	
	{
		s=(s+p*a[i])%2;
		p=(p*b)%2;
	}
	cout << (s?"odd":"even") << endl;
	return 0;	
}
```

