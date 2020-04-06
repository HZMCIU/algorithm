### [PAT Ranking](https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872)

### 题意

给出组内排名和全部排名

### 思路

水题。

+ 分数相同，序号升序排列
+ 序号如果不够13位，前面用0补充。坑呀。。

### 总结

PAT环境中使用64位整数要用`%lld`。

注意边界值的控制

### AC代码

```cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5;
const int inf = 0x3f3f3f3f;
typedef long long ll;

struct node
{
    ll num;
    int gp;
    int gd;
    int gpr;
    int trk;
};
bool cmp1(node a,node b)
{
    if(a.gd==b.gd)
        return a.num<b.num;
    return a.gd>b.gd;
}
node a[maxn];
int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    int cnt=0;
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%I64d %d",&a[cnt].num,&a[cnt].gd);
            a[cnt].gp=i;
            cnt++;
        }
        sort(a+cnt-n,a+cnt,cmp1);
        int rk=1;
        for(int j=cnt-n;j<cnt;j++)
        {
            int k=rk;
            a[j].gpr=rk;
            //越界了，防止越界
            while(a[j].gd==a[j+1].gd&&j<cnt&&j+1<cnt)
            {

                a[j+1].gpr=k;
                rk++;
                j++;
            }
            rk++;
        }
    }
    sort(a,a+cnt,cmp1);
    int rk=1;
    for(int i=0;i<cnt;i++)
    {
        a[i].trk=rk;
        int k=rk;
        //防止越界
        while(a[i].gd==a[i+1].gd&&i+1<cnt&&i<cnt)
        {
            a[i+1].trk=k;
            rk++;
            i++;
        }
        rk++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%013I64d %d %d %d\n",a[i].num,a[i].trk,a[i].gp,a[i].gpr);
    }
    return 0;
}
```

