### [Digital Library](https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336)

### 题意

根据书名等信息查询，书的编号

### 思路

模拟

**C++技巧**

stringstream,map<string,set<string\>>,getline()

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int,int> P;

//map里面再套其他的容器
map<string,set<string>>  title, author,word, publisher, year;
void output(map<string,set<string>> &a,string &s)
{
    //截取从第三个开始的子串
    map<string,set<string>>::iterator t=a.find(s.substr(3));
    if(t==a.end()||t->second.empty())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        //map输出是降序的
        for(set<string>::iterator it=t->second.begin();it!=t->second.end();it++)
        {
            puts(it->c_str());
        }
    }
}
int main()
{
   //freopen("in.txt","r",stdin);
    int n;
    string s;
    stringstream ss;
    cin >> n;
    cin.ignore(1);
    for(int i=0;i<n;i++)
    {
        string id;
        getline(cin,id,'\n');
        getline(cin,s,'\n');
        title[s].insert(id);
        getline(cin,s,'\n');
        author[s].insert(id);
        getline(cin,s,'\n');
        //使用stringstream，来读入一行的多个字符
        ss.clear();
        ss<<s;
        while(ss>>s)
        {
            word[s].insert(id);
        }
        getline(cin,s,'\n');
        publisher[s].insert(id);
        getline(cin,s,'\n');
        year[s].insert(id);
    }
    int m;
    cin>>m;
    //忽略换行符
    cin.ignore(1);
    for(int i=0;i<m;i++)
    {
        getline(cin,s);
        cout << s << endl;
        switch(s[0])
        {
        case '1':
            output(title,s);
            break;
        case '2':
            output(author,s);
            break;
        case '3':
            output(word,s);
            break;
        case '4':
            output(publisher,s);
            break;
        case '5':
            output(year,s);
            break;
        }
    }
    return 0;
}

```

