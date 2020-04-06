#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    printf("%d\n",lower_bound(v.begin(),v.end(),2)-v.begin());
    printf("%d\n",lower_bound(v.begin(),v.end(),3)-v.begin());
    printf("%d\n",upper_bound(v.begin(),v.end(),2)-v.begin());
    printf("%d\n",upper_bound(v.begin(),v.end(),3)-v.begin());
}

