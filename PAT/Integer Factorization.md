### [Integer Factorization](https://pintia.cn/problem-sets/994805342720868352/problems/994805364711604224)

### 题意

### 思路

搜索。刚开始直接暴力搜索，直接WA。剪枝优化。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e3+100;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p;
vector<int> ans;
vector<int> tmp;
ll Pow[40][10];
int Cal(int a,int p)
{
    int ret=1;
    for(int i=1;i<=p;i++)
        ret*=a;
    return ret;
}
// pre 是上一步中的选取的的数，这样能够保证选取的数是有序的，最重要的是能够降低复杂度呀。。。:(
int dfs(int n,int cnt,int pre)
{
    if(n==0&&cnt==k)
    {
        if(ans.size()==0)
        {
            ans=tmp;
            sort(ans.begin(),ans.end(),[](int a,int b)->bool{return a>b;});
        }
        else
        {
            vector<int> tmpp=tmp;
            sort(tmpp.begin(),tmpp.end(),[](int a,int b)->bool{return a>b;});
            int a=0,b=0;
            bool f=false;
            for(int i=0;i<ans.size();i++)
                a+=ans[i],b+=tmpp[i];
            if(a<b)
                ans=tmpp;
            else if(a==b)
            {
                for(int i=0;i<ans.size();i++)
                    if(ans[i]!=tmpp[i])
                    {
                        f=ans[i]<tmpp[i];
                    }
                if(f)
                    ans=tmpp;
            }
        }
        return 0;
    }
    if(n<=0||cnt>=k)
        return 0;
    //从上一个数开始选
    for(int i=pre;i<=20;i++)
    {
        //假设接下来(k-cnt)个数全部选取最小的数，Pow[i][p],但是仍然还是比n大，那么就不必要继续往下搜索了，剪枝优化
        if(n>=Pow[i][p]*(k-cnt))
        {
            tmp.push_back(i);
            int t=Pow[i][p];
            dfs(n-t,cnt+1,i);
            tmp.pop_back();
        }
        else break;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=20;i++)
    {
        for(int j=2;j<=7;j++)
            Pow[i][j]=Cal(i,j);
    }
    dfs(n,0,1);
    if(ans.size()==0)
        puts("Impossible");
    else
    {
        printf("%d = ",n);
        printf("%d^%d",ans[0],p);
        for(int i=1;i<ans.size();i++)
            printf(" + %d^%d",ans[i],p);
        puts("");
    }
    return 0;
}
```

