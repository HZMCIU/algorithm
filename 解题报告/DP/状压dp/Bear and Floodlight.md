## [Bear and Floodlight](https://vjudge.net/problem/CodeForces-385D)

  ```cpp
#include<bits/stdc++.h>
using namespace std;
const int  MAX_N = 1<<20;
const int MOD = 1e9+7;
double dp[MAX_N];//dp[i]表示i状态最多可以照亮的连续区域长度
double x[25],y[25],a[25],l,r;
double solve(double len,int j)//第j个灯从dp[i]位置开始照可以照多长的距离
{
    double temp = atan((r-x[j])/y[j]);//三角形右侧的弧度
    temp = min(temp,atan((len-x[j])/y[j])+a[j]);//两种情况，一是dp[i]已经到达了xi，另外就是dp[i]还没有到达xi，求解最小的张角
    return x[j] + (y[j] * tan(temp));//返回加上第j盏灯后的最大长度
}

int main()
{
    int N,M,T;
    while(~scanf("%d%lf%lf",&N,&l,&r))
    {
        r -= l;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            scanf("%lf%lf%lf",&x[i],&y[i],&a[i]);
            x[i] -= l;//对齐到原点
            a[i]=a[i]/180.*acos(-1.0); //atan中变量为弧度
            cout<<a[i]<<endl;
        }
        int n = 1<<N;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<N;j++)
            {
                if((i&(1<<j))==0)//i&(1 << j)=0表示第j个灯不在i状态中然后把第j个灯的照射范围放在最右边
                {
                    dp[i^(1<<j)] = max(dp[i^(1<<j)] ,solve(dp[i],j));//和0异或后不改变数的值
                }
            }
        }
        printf("%.12f\n",dp[n-1]);
    }
    return 0;
}


  ```

​                  