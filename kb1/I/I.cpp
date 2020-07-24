#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 15;
int Case,t,m,n;
char g[maxn][maxn];
bool vis[maxn][maxn];
int vis1[maxn][maxn];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

struct node
{
    int x,y;
    int step;
};

bool can_vis(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    if(vis[x][y])
        return false;
    if(g[x][y]=='.')
        return false;
    return true;
}

void bfs(int x1,int y1,int x2,int y2)
{
    memset(vis,0,sizeof(vis));
    memset(vis1,0x3f,sizeof(vis1));
    node cur1,cur2,cur,next;
    cur1.x = x1;cur1.y = y1;
    cur2.x = x2;cur2.y = y2;
    cur1.step = cur2.step = 0;
    queue<node> q;
    q.push(cur1);q.push(cur2);
    vis[x1][y1] = 1;vis[x2][y2] = 1;
    while(!q.empty())
    {
        cur = q.front();q.pop();
        vis1[cur.x][cur.y] = min(vis1[cur.x][cur.y],cur.step);
        for(int i=0;i<4;i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if(can_vis(next.x,next.y))
            {
                vis[next.x][next.y] = 1;
                next.step = cur.step + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        int ans = 0x3f3f3f3f;
        for(int x1=0;x1<n;x1++)
        {
            for(int y1=0;y1<m;y1++)
            {
                for(int x2=0;x2<n;x2++)
                {
                    for(int y2=0;y2<m;y2++)
                    {
                        if(g[x1][y1]=='#' && g[x2][y2]=='#')
                        {
                            bfs(x1,y1,x2,y2);
                            int maxx = 0;
                            for(int i=0;i<n;i++)
                            {
                                for(int j=0;j<m;j++)
                                {
                                    if(g[i][j]=='#')
                                    {
                                        maxx = max(maxx,vis1[i][j]);
                                    }
                                }
                            }
                            ans = min(ans,maxx);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",++Case,ans==0x3f3f3f3f?-1:ans);
    }
}

