###[Wall](https://vjudge.net/problem/POJ-1113)

### 题意

给出城堡N个点的坐标，建造一座城墙，而且城墙的距城堡的距离恰好为L。求出城墙最小的长度是多少。

### 思路

首先不用考虑城墙距离城堡的距离为L这个约束条件，那么求覆盖这N个点的最小的城墙，就是求这N个点的凸包。如果加上距离为L这个条件，那么就是在凸包的周长的基础上加上一个圆的周长（通过作图可以发现，多边形的外角和均为360度）。

### AC代码

```cpp
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
struct Point
{
    int x,y;
    Point(int _x,int _y):x(_x),y(_y){}
    Point(){}
    Point operator -(const Point&p)const
    {
        return Point(x-p.x,y-p.y);
    }
};
Point a[maxn];
int n;
Point stk[maxn];
int top;
double cross(Point a,Point b)
{
    return a.x*b.y-b.x*a.y;
}
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Point p,Point q)
{
    int c=cross(p-a[0],q-a[0]);
    if(c==0)
    {
        return dist(a[0],p)<dist(a[0],q);
    }
    return c>0;
}
void GrahamScan()
{
    int ty=inf,tx;
    int k;
    for(int i=0;i<n;i++)
    {
        if(ty>a[i].y)
            k=i,ty=a[i].y,tx=a[i].x;
        else if(ty==a[i].y&&a[i].x<tx)
            k=i,ty=a[i].y,tx=a[i].x;
    }
    stk[top++]=a[k];
    swap(a[0],a[k]);
    sort(a+1,a+n,cmp);
    stk[top++]=a[1];
    for(int i=2;i<n;i++)
    {
        while(cross(stk[top-1]-stk[top-2],a[i]-stk[top-2])<=0&&top>=2) top--;
        stk[top++]=a[i];
    }

}
int main(int argc,char **argv)
{
    freopen("in.txt", "r", stdin);
    int L;
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    GrahamScan();
    double ans=0;
    for(int i=0;i<top;i++)
    {
        ans+=dist(stk[i],stk[(i+1)%top]);
    }
    ans+=2*3.1415926*L;
    printf("%d\n",int(ans+0.5));
    return 0;
}
```

