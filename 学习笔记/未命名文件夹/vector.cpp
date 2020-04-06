#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(10);


    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    puts("");
    v.pop_back();
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    puts("");
    v.erase(v.begin());       //v.erase(v.begin()+1);

    //遍历方法
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    puts("");
    puts("");
    printf("%d\n",v.size());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)        //auto
        printf("%d ",(*it));
    puts("");

    printf("%d\n",v.size());
    for(vector<int>::reverse_iterator it=v.rbegin();it!=v.rend();it++)  //auto
        printf("%d ",(*it));
    puts("");

    v.clear();
    printf("%d\n",v.size());
    if(v.empty()) printf("YES\n");
}

