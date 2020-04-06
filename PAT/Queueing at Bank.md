[Queueing at Bank](https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968)

### 题意

有K个窗口，N个人，求每个人等待的时间。

### 思路

要考虑窗口开的比人早的情况。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
typedef long long ll;
int N,K;
struct node
{
    int time;
    int process;
}customer[maxn];
const int start=8*60*60;
const int _end=17*60*60;
int windows[100];
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    int tot=0;
    for(int i=0;i<N;i++)
    {
        int hour,minute,second,process,time;
        scanf("%d:%d:%d%d",&hour,&minute,&second,&process);
        time=hour*60*60+minute*60+second;
        if(time<=_end)
        {
            customer[tot].process=process*60;
            customer[tot].time=time;
            tot++;
        }
    }
    sort(customer,customer+tot,[](node a,node b)->bool{return a.time<=b.time;});
    priority_queue<int,vector<int>,greater<int>> que;
    int pos=0;
    for(int i=0;i<K;i++)
        que.push(start);
    double total=0;
    while(pos<tot)
    {
        int t=que.top();
        que.pop();
        if(t<=customer[pos].time)
        {
            que.push(customer[pos].time+customer[pos].process);
        }
        else
        {
            total+=abs(customer[pos].time-t);
            que.push(t+customer[pos].process);
        }
        pos++;
    }
    total/=60;
    if(tot!=0)
    printf("%.1f\n",total/tot);
    else
        printf("0.0\n");
    return 0;
}
```

