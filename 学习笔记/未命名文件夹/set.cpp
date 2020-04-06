#include<set>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string temp="abc";
    set<string> s;
    s.insert(temp);
    temp="bcd";
    s.insert(temp);
    temp="bcde";
    s.insert(temp);
    for(set<string>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<endl;
    }
    printf("%d\n",s.size());
    s.erase(s.begin());

    for(set<string>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }

    printf("%d\n",s.size());
    set<string>::iterator tt=s.find("bcd");

    cout<<*tt<<endl;
    tt=s.find("ert");
    if(tt!=s.end())
    cout<<*tt<<endl;
}

