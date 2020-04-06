

##[Triangular Pastures](https://cn.vjudge.net/problem/POJ-1948)

####思路

使用dp求解一条边是i，一条边是j，另外一条边是sum-i-j的可能性。而后对dp\[i]\[j]=1的组成情况判断是否可以组成三角形，然后求解最大值

**Wrong Answer**

```cpp
#include <bits/stdc++.h>
using namespace std;
double area(double a,double b,double c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int dp[60][60];
int len[60];
int main()
{
    /*double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%lf\n",area(a,b,c));*/
    int n,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&len[i]);
        sum+=len[i];
    }
    dp[0][0]=1;
    int a[3];
    int tot=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=40;j++)
        {
            for(int k=1;k<=40;k++)
            {
                if(j>=len[i]&&dp[j-len[i]][k]) dp[j][k]=1;
                if(k>=len[i]&&dp[j][k-len[i]]) dp[j][k]=1;
            }
        }
    }
    for(int i=0;i<=40;i++)
    {
        for(int j=0;j<=40;j++)
        {
            //if(dp[i][j]==2) printf("i %d j %d\n",i,j);
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
}


```

Accept

```cpp
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool dp[805][805];//能否达到一条边是i，另外一条边是j
int len[60];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&len[i]);
            sum+=len[i];
        }
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum/2;j>=0;j--)//一条边的最大值不会超过sum/2，所以从sum/2开始。i从小到达大开始取值。如果从小到大开始取值的话，后面较大的值会收到前面较小的值得影响
            {
                for(int k=j;k>=0;k--)
                {
                    if(j>=len[i]&&dp[j-len[i]][k]) dp[j][k]=1;
                    if(k>=len[i]&&dp[j][k-len[i]]) dp[j][k]=1;
                }
            }
        }
        int ans=-1;
        int c;
        for(int i=0;i<=sum/2;i++)
        {
            for(int j=0;j<=sum/2;j++)
            {
                if(dp[i][j])
                {
                    c=sum-i-j;
                    if((i+j>c)&&(i+c>j)&&(j+c>i)) 
                    {
                        double p=1.0*sum/2.0;//注意精度问题
                        int t=sqrt(p*(p-i)*(p-j)*(p-(sum-i-j)))*100;
                        ans=max(t,ans);
                    }
                }

            }
        }
        printf("%d\n",ans);      
    }
}

```

