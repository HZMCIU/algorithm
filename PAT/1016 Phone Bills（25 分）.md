[1016 Phone Bills（25 分）](https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488)

###  题意

从一堆通话记录中挑选出通话的起始和结束的时间，并且计算出这段通话时长花费的费用。0-24小时通话的费用不同。

### 思路

**熟练使用STL** ，跪了。

合理的求解差值，`billFromZero` ，通过计算俩个时间到原点所花费的金钱，**差值**就是这一段时间花费的费用了。

能通过增加变量解决的问题，就不要通过就算解决。因为能够写代码的复杂度，实现各种计算需要写各种代码，出现错误的概率也变大了。

### 总结

模拟的能力还需要加强

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
typedef long long ll;
int cost[25];
int N;
struct node
{
    string name;
    int month,day,hour,minute,time;
    int status;
};
bool cmp(node a,node b)
{
    return a.name!=b.name?a.name<b.name:a.time<b.time;
}
double billFromZero(node call)//通过差值计算一段时间内花费，学到了
{
    double total=cost[call.hour]*call.minute+cost[24]*60*call.day;
    for(int i=0;i<call.hour;i++)
        total+=cost[i]*60;
    return total/100.0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    for(int i=0;i<24;i++)
    {
        scanf("%d",&cost[i]);
        cost[24]+=cost[i];
    }
    scanf("%d",&N);
    vector<node> data(N);
    string tmp;
    for(int i=0;i<N;i++)
    {
        cin>> data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;//通过增加一个转化为分钟的变量，避免后面时间相互转化的麻烦
        cin>>tmp;
        data[i].status=(tmp=="on-line")?1:0;
    }
    sort(data.begin(),data.end(),cmp);
    map<string,vector<node>> customer;
    for(int i=1;i<N;i++)
    {
        if(data[i].name==data[i-1].name&&data[i-1].status==1&&data[i].status==0)
        {
            customer[data[i-1].name].push_back(data[i-1]);
            customer[data[i].name].push_back(data[i]);
        }
    }
    for(auto it:customer)
    {
        vector<node> tmp=it.second;
        cout << it.first;
        printf(" %02d\n",tmp[0].month);
        double total=0;
        for(int i=1;i<tmp.size();i+=2)//前面加了两遍
        {
            double t=billFromZero(tmp[i])-billFromZero(tmp[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",tmp[i-1].day,tmp[i-1].hour,tmp[i-1].minute,tmp[i].day,tmp[i].hour,\
            tmp[i].minute, tmp[i].time-tmp[i-1].time,t);
            total+=t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}

```

