#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    printf("%d\n",q.size());
    q.pop();
    printf("%d\n",q.size());
    printf("%d %d\n",q.front(),q.back());

    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    puts("");
}

