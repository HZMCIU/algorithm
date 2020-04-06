#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
char mz[2020][2020];
bool vis[2020][2020];
int n,m,k;
vector<int> ans;
int dfsi(int i,int j,int step)
{
    if(j==m)
    {
        if(step>0) ans.push_back(step);
        return 0;
    }
    if(mz[i][j]=='.') dfsi(i,j+1,step+1);
    if(mz[i][j]=='*')
    {
        if(step>0) ans.push_back(step);
        step=0;
        dfsi(i,j+1,step);
    }
}
int dfsj(int i,int j,int step)
{
    if(i==n)
    {
        if(step>0) ans.push_back(step);
        return 0;
    }
    if(mz[i][j]=='.') dfsj(i+1,j,step+1);
    if(mz[i][j]=='*')
    {
        if(step>0) ans.push_back(step);
        step=0;
        dfsj(i+1,j,step);
    }
}
int main()
{

    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",mz[i]);
    }
    int sum=0;
    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            dfsi(i,0,0);
        }
        printf("%d\n",ans.size());
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        dfsi(i,0,0);
        for(int p=0;p<ans.size();p++)
        {
            if(ans[p]>=k) sum+=(ans[p]-k+1);
        }
        ans.clear();
    }
    for(int j=0;j<m;j++)
    {
        dfsj(0,j,0);
        for(int p=0;p<ans.size();p++)
        {
            if(ans[p]>=k) sum+=(ans[p]-k+1);
        }
        ans.clear();
    }
    printf("%d\n",sum);
    return 0;
}
