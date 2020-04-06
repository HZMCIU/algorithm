##[Shaass and Lights](http://codeforces.com/contest/294/problem/C)

[题解](http://www.cnblogs.com/liuweimingcprogram/p/6240558.html)

#### 思路



```cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
const ll  mod=1000000007;
ll qpow(ll a,ll b)//快速幂
{
    ll base=a,ans=1;
    while(b!=0)
    {
        if(b&1!=0) 
        {
             ans*=base;
             ans%=mod;//防止超范围
             //printf("%I64d\n",ans);
        }
        base=base*base%mod;//防止超范围
        b>>=1;
    }
    return ans;
}
ll c[1010][1010];
void init()//对于小数据，使用杨辉三角来计算组合数
{
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=2;i<=1000;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
            c[i][j]%=mod;//防止超出范围
        }
    }
}
int light[1010];

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    int t;
    init();
    int sumon=m,sumoff=n-m;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        light[t-1]=1;
    }
    ll ans=1;
    int l=0,r=n-1;
    int sum=0;
    while(!light[l]) l++,sum++;
    ans*=c[sumoff][sum];
    ans%=mod;
    //printf("%d\n",ans);
    sumoff-=sum;
    sum=0;
    for(int i=l+1;i<n;i++)
    {
        if(light[i]) 
        {
            if(sum==0) continue;
            ans*=c[sumoff][sum];
            //printf("C:%d\n",c[sumoff][sum]);
            //printf("ans:%d\n",ans);
            ans%=mod;
            ans*=qpow(2,sum-1);
            /*printf("pow:%I64d\n",qpow(2,sum-1));
            printf("ans:%I64d\n",ans);
            printf("sum:%d sumoff:%d\n",sum,sumoff);
            system("pause");*/
            ans%=mod;
            sumoff-=sum;
            sum=0;
            continue;
        }
        sum++;
    }
    printf("%I64d\n",ans);
    return 0;
}

```

