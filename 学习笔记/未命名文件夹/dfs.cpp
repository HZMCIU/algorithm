#include<bits/stdc++.h>
using namespace std;
bool did[100][100];
char mp[100][100];
int n,m;
int ans=INT_MAX;
int nex[4][2]={-1,0,1,0,0,-1,0,1};
void dfs(int x,int y,int step)
{
    if(x==n-1&&y==m-1)
    {
        ans=min(ans,step);
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+nex[i][0];
        int ny=y+nex[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!did[nx][ny]&&mp[nx][ny]=='.')
        {
            did[nx][ny]=true;
            dfs(nx,ny,step+1);
            did[nx][ny]=false;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    did[0][0]=true;
    dfs(0,0,0);
    printf("%d\n",ans);
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

