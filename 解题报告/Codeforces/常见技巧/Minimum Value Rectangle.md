### [Minimum Value Rectangle](http://codeforces.com/contest/1027/problem/C)

### 题意

给出$n$个数，找出出现两次以上的两个数，使得$\frac{(a+b)^2}{ab}$最小。

### 思路

只有$a,b$最接近的时候才可能由最小值。

### 总结

进行数值比较的时候尽量不要用$double$来进行比较，会有数值误差，不准确。使用$int$来代替。

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=1e6+10;
int a[maxn];
int cnt[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int top=0;
        a[n]=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                cnt[top++]=a[i];
                i+=1;
            }
        }
        int s=0,t=1;
        for(int i=1;i<top;i++)
        {
            if(1ll*(cnt[s]*cnt[s]+cnt[t]*cnt[t])*cnt[i-1]*cnt[i]>1ll*(cnt[i]*cnt[i]+cnt[i-1]*cnt[i-1])*(cnt[s]*cnt[t]))//使用int型数据来代替
            {
                s=i-1;
                t=i;
            }
        }
        printf("%d %d %d %d\n",cnt[s],cnt[s],cnt[t],cnt[t]);
    }
    return 0;
}
```

