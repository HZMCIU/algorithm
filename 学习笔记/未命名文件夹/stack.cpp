#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    printf("%d\n",s.size());
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    puts("");
}

