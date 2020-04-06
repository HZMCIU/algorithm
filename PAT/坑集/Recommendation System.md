### [Recommendation System](https://pintia.cn/problem-sets/994805342720868352/problems/994805348471259136)

### 题意

给出访问序列，遍历序列中的每个元素，然后给出当前访问量最大的前K个元素

### 思路

维护一个推荐数组，每次访问时，对这个数组进行更新。

### 坑点

当推荐数组满了，并且当前元素不在推荐数组中，更新方法有异。

1. 我的笨方法，从前到后扫，找到一个合适的位置，将当前元素插入推荐数组中
2. 题解方法，将当前元素和最后一个元素比较，因为维护的`out`推荐数组是有序的

我的方法会将不是最小的元素替换出去，例如现有推荐数组的频率`(3,2,2,1)` ，假设当前元素的频率也为`2`，那么就会将数组中的第二个或者第三个元素替换掉，但是真正应该替换的是最后一个元素，所以这样得到了错误的结果。

### 总结

没有充分利用`out`数组是有序的性质，直接判断最后一个元素就可以了

数组是降序排列的，从前到后更新，如果数组中的所有元素都不相等，那么只要发现比当前这个数小的数把他替换出来就行了。但是如果遇到存在重复值的情况，然后使用我的那种方法，就会GG。由于数组是降序排列的，而且我们求算的是最大值，所以正确的更新顺序是，从小到大更新，也就是从后往前更新，我的更新顺序根本上是错误的。

### WA代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int n,k;
int vis[maxn];
int out[20];
bool inlist[maxn];
bool cmp(int a,int b)
{
    if(vis[a]==vis[b])
        return a<b;
    else
        return vis[a]>=vis[b];
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int t;
    scanf("%d",&t);
    vis[t]+=1;
    int cur=0;
    if(k>=1)
    {
        out[0]=t;
        inlist[t]=true;
        cur=1;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d",&t);
        vis[t]+=1;
        printf("%d: ",t);
        if(cur)
        {
            printf("%d",out[0]);
            for(int j=1;j<cur;j++)
            {
                printf(" %d",out[j]);
            }
        }
        puts("");
        if(!inlist[t]&&cur<k)
        {
            out[cur++]=t;
            inlist[t]=true;
            sort(out,out+cur,cmp);
        }
        else if(inlist[t])
        {
            sort(out,out+cur,cmp);
        }
        else
        {
            for(int j=0;j<k;j++)
            {
                if(vis[out[j]]<vis[t])
                {
                    inlist[out[j]]=false;
                    out[j]=t;
                    inlist[t]=true;
                    break;
                }
                else if(vis[out[j]]==vis[t]&&t<out[j])
                {
                    inlist[out[j]]=false;
                    out[j]=t;
                    inlist[t]=true;
                    break;
                }
            }
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
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int n,k;
int vis[maxn];
int out[20];
bool inlist[maxn];
bool cmp(int a,int b)
{
    if(vis[a]==vis[b])
        return a<b;
    else
        return vis[a]>=vis[b];
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int t;
    scanf("%d",&t);
    vis[t]+=1;
    int cur=0;
    if(k>=1)
    {
        out[0]=t;
        inlist[t]=true;
        cur=1;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d",&t);
        vis[t]+=1;
        printf("%d: ",t);
        if(cur)
        {
            printf("%d",out[0]);
            for(int j=1;j<cur;j++)
            {
                printf(" %d",out[j]);
            }
        }
        puts("");
        if(inlist[t])
        {
            sort(out,out+cur,cmp);
        }
        else if(cur<k)
        {
            out[cur++]=t;
            inlist[t]=true;
            sort(out,out+cur,cmp);
        }
        else
        {
            if(vis[t]>vis[out[k-1]])
            {
                inlist[out[k-1]]=false;
                out[k-1]=t;
                inlist[t]=true;
                sort(out,out+cur,cmp);
            }
            else if(vis[t]==vis[out[k-1]]&&t<out[k-1])
            {
                inlist[out[k-1]]=false;
                out[k-1]=t;
                inlist[t]=true;
                sort(out,out+cur,cmp);
            }
        }
    }
    return 0;
}
```

**set版本代码**

**使用set内置find,erase函数来进行每次的更新，重写结构体的比较函数，set内部是有序的**

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

struct node
{
    int val,freq;
    node(int _val,int _freq):val(_val),freq(_freq){}
    bool operator <(const node &n)const{
        if(freq!=n.freq)
            return freq>n.freq;
        else
            return val<n.val;
    }
};
int vis[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,k,t;
    set<node> s;
    scanf("%d%d%d",&n,&k,&t);
    s.insert(node(t,1));
    vis[t]++;
    for(int i=1;i<n;i++)
    {
        int j=0;
        scanf("%d",&t);
        printf("%d:",t);
        for(auto it=s.begin();j<k&&it!=s.end();it++,j++)
        {
            printf(" %d",it->val);
        }
        puts("");
        auto it=s.find(node(t,vis[t]));
        if(it!=s.end())
        {
            s.erase(it);
        }
        vis[t]++;
        s.insert(node(t,vis[t]));
    }
    return 0;
}
```

