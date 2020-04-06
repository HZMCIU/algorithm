#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    string t="abcde";
    printf("%d\n",t.size());
    printf("%c\n",t[2]);
    t.erase(t.begin()+2);
    printf("%c\n",t[2]);
    cout<<t<<endl;
}

