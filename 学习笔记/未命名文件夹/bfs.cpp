#include<bits/stdc++.h>
using namespace std;
bool did[100][100];
char mp[100][100];
int step[100][100];
int n,m;
int ans=INT_MAX;
int nex[4][2]={-1,0,1,0,0,-1,0,1};
void bfs()
{
    queue<pair<int,int> > q;
    q.push({0,0});
    while(!q.empty())
    {

        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=t.first+nex[i][0];
            int ny=t.second+nex[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!did[nx][ny]&&mp[nx][ny]=='.')
            {
                did[nx][ny]=true;
                q.push({nx,ny});

                step[nx][ny]=step[t.first][t.second]+1;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    did[0][0]=true;
    bfs();
    printf("%d\n",step[n-1][m-1]);
}
/*
9 19
..#################
#............######
######.#####.######
####.#.#####.....##
##...#..####.######
####...#####...####
####.#######.######
####.#######.######
####...............
*/

