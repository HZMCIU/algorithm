### [ Graduate Admission](https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136)

### 思路

模拟

### WA代码

```cpp
#include <bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
typedef long long ll;
typedef pair<int,int> P;

struct node
{
    int ge;
    int gi;
    int fi;
    int rnk;
    int id;
    int choice[10]={-1,-1,-1,-1,-1,-1};
    bool operator <(const node &a)const
    {
        if(fi!=a.fi)
            return fi>a.fi;
        else return ge>a.ge;
    }
};
vector<int> school[200];
node app[maxn];
int n,m,k;
int quota[200];
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
        scanf("%d",&quota[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&app[i].ge,&app[i].gi);
        app[i].id=i;
        app[i].fi=(app[i].ge+app[i].gi);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&app[i].choice[j]);
        }
    }
    sort(app,app+n);
    int pre_ge=app[0].ge;
    int pre_rnk=1;
    int pre_fi=app[0].fi;
    for(int i=0;i<n;i++)
    {
        if(pre_fi!=app[i].fi)
        {
            app[i].rnk=i+1;
            pre_rnk=i+1;
            pre_fi=app[i].fi;
            pre_ge=app[i].ge;
        }
        else if(pre_ge!=app[i].ge)
        {
            app[i].rnk=i+1;
            pre_rnk=i+1;
            pre_ge=app[i].ge;
            pre_fi=app[i].fi;
        }
        else
        {
            app[i].rnk=pre_rnk;
        }
    }
    for(int i=0;i<n;i++)
    {
        bool f=0;
        for(int j=0;j<k;j++)
        {
            int sch=app[i].choice[j];
            if(school[sch].size()<quota[sch])
            {
                school[sch].push_back(app[i].id);
                break;
            }
            else if(school[sch].size()>=quota[sch]&&quota[sch]>0)
            {
                //这里取出的最后一个学生的序号，不是最后一个学生在数组中的位置，找了半天
                int last=school[sch][school[sch].size()-1];
                if(app[last].rnk==app[i].rnk)
                {
                    school[sch].push_back(app[i].id);
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(school[i].size()==0)
        {
            puts("");
            continue;
        }
        else
        {
            sort(school[i].begin(),school[i].end());
            for(int j=0;j<school[i].size()-1;j++)
                printf("%d ",school[i][j]);
            printf("%d\n",school[i][school[i].size()-1]);
        }
    }
    return 0;
}
```



### AC代码

```cpp
#include <bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
typedef long long ll;
typedef pair<int,int> P;

struct node
{
    int ge;
    int gi;
    int fi;
    int rnk;
    int id;
    int choice[10]={-1,-1,-1,-1,-1,-1};
    bool operator <(const node &a)const
    {
        if(fi!=a.fi)
            return fi>a.fi;
        else return ge>a.ge;
    }
};
vector<node> school[200];
node app[maxn];
int n,m,k;
int quota[200];
bool cmp(node &a,node &b)
{
    return a.id<b.id;
}
int main()
{
  //  freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    for(int i=0;i<200;i++)
        school[i].clear();
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
        scanf("%d",&quota[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&app[i].ge,&app[i].gi);
        app[i].id=i;
        app[i].fi=(app[i].ge+app[i].gi);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&app[i].choice[j]);
        }
    }
    sort(app,app+n);
    int pre_ge=app[0].ge;
    int pre_rnk=1;
    int pre_fi=app[0].fi;
//    for(int i=0;i<n;i++)
//    {
//        printf("%d %d %d %d\n",app[i].id,app[i].rnk,app[i].ge,app[i].gi);
//    }
    for(int i=0;i<n;i++)
    {
        bool f=0;
        for(int j=0;j<k;j++)
        {
            node last;
            int sch=app[i].choice[j];
            if(school[sch].size()>0)
                last=school[sch][school[sch].size()-1];
            if(school[sch].size()<quota[sch])
            {
                school[sch].push_back(app[i]);
                break;
            }
            else if(app[i].fi==last.fi&&app[i].ge==last.ge)
            {
                school[sch].push_back(app[i]);
                break;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(school[i].size()>0)
        {
            sort(school[i].begin(),school[i].end(),cmp);
            for(int j=0;j<school[i].size()-1;j++)
                printf("%d ",school[i][j].id);
            printf("%d",school[i][school[i].size()-1].id);
        }
        puts("");
    }
    return 0;
}
```

