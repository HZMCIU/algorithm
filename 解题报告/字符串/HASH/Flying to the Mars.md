## [Flying to the Mars](https://cn.vjudge.net/problem/HDU-18000)

#### 思路

字符串哈希

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 1000005;
const int MOD = 100007;
int hsh[N],cnt[N];

unsigned int elfhash(char *str)
{
    unsigned int h = 0;
    unsigned int x;
    while(*str)
    {
        h = (h << 4) + *str++;
        x = h & 0xF0000000L;
        if(x)
        {
            h ^= x>>24;
            h &= ~x;
        }
    }
    return h & 0x7FFFFFFF;
}
int hashhit(char *str)
{
    while(*str == '0') str++;
    int k = elfhash(str);
    int t = k % MOD;
    while(hsh[t] != k && hsh[t] != -1) ///开放地址法
        t = (t + 10) % MOD;
    if(hsh[t] == -1)
    {
        cnt[t] = 1;
        hsh[t] = k;
    }
    else cnt[t]++;
    return cnt[t];
}

int main()
{
	int n;
	char str[105];
	while(scanf("%d",&n)!=EOF)
	{
		int ans=1;
		//memset(cnt,0,sizeof(cnt)); 因为是哈希算法，所以不需要每次去清零
		memset(hsh,-1,sizeof(hsh));
		while(n--)
		{
			scanf("%s",str);
            ans=max(ans,hashhit(str));
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/

```

