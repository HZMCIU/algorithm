#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    //priority_queue<int,vector<int>,greater<int> > pq;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    printf("%d\n",pq.size());
    while(!pq.empty())
    {
        printf("%d\n",pq.top());
        pq.pop();
    }
}

