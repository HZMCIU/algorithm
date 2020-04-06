#include<map>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    map<long long,int> mp;
    mp[10000000000]=10;
    mp[10000000001]=20;
    mp[10000000002]=30;
    for(map<long long,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        printf("%lld %d\n",it->first,(*it).second);
    }
    printf("%d\n",mp[10000000000]);
    printf("size: %d\n",mp.size());
    mp.clear();
    printf("size: %d\n",mp.size());
    printf("%d\n",mp[10000000000]);
    printf("size: %d\n",mp.size());
    map<string,int> m;
    string temp="abc";
    m[temp]=10;
    temp="bcd";
    m[temp]=20;
    temp="cde";
    m[temp]=30;
    printf("%d\n",m["bcd"]);
    printf("size:%d\n",m.size());
    m.erase("bcd");
    printf("size:%d\n",m.size());
    printf("%d\n",m["bcd"]);
    printf("size:%d\n",m.size());
}

