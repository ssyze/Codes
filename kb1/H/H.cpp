#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int a,b,c;
map<pair<int,int>, bool> vis;
struct node
{
    int a,b;
    int step;
    vector<int> last[200];
    bool flag;
};

node bfs()
{
    node cur,next;
    cur.a = cur.b = cur.step = cur.flag = 0;
    vis[make_pair(0,0)] = 1;
    queue<node> q;
    q.push(cur);
    while(!q.empty())
    {
        cur = q.front();q.pop();
        if(cur.a == c || cur.b == c)
        {
            return cur;
        }
        if(cur.a < a)
        {
            next = cur;
            next.a = a;
            next.b = cur.b;
            next.step = cur.step + 1;
            next.last[cur.step].push_back(1);
            next.last[cur.step].push_back(1);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
        if(cur.b < b)
        {
            next = cur;
            next.b = b;
            next.a = cur.a;
            next.step = cur.step + 1;
            next.last[cur.step].push_back(1);
            next.last[cur.step].push_back(2);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
        if(cur.a > 0)
        {
            next = cur;
            next.a = 0;
            next.b = cur.b;
            next.step = cur.step + 1;
            next.last[cur.step].push_back(2);
            next.last[cur.step].push_back(1);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
        if(cur.b > 0)
        {
            next = cur;
            next.b = 0;
            next.a = cur.a;
            next.step = cur.step + 1;
            next.last[cur.step].push_back(2);
            next.last[cur.step].push_back(2);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
        if(cur.a>0 && cur.b<b)
        {
            next = cur;
            int tmp = b - cur.b;
            if(tmp>=cur.a)
            {
                next.b = cur.b+cur.a;
                next.a = 0;
            }
            else
            {
                next.b = b;
                next.a = cur.a-tmp;
            }
            next.step = cur.step + 1;
            next.last[cur.step].push_back(3);
            next.last[cur.step].push_back(1);
            next.last[cur.step].push_back(2);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
        if(cur.a<a && cur.b>0)
        {
            next = cur;
            int tmp = a - cur.a;
            if(tmp >= cur.b)
            {
                next.b = 0;
                next.a = cur.a + cur.b;
            }
            else
            {
                next.a = a;
                next.b = cur.b - tmp;
            }
            next.step = cur.step + 1;
            next.last[cur.step].push_back(3);
            next.last[cur.step].push_back(2);
            next.last[cur.step].push_back(1);
            if(!vis[make_pair(next.a,next.b)])
            {
                q.push(next);
                vis[make_pair(next.a,next.b)] = 1;
            }
        }
    }
    node tmp;
    tmp.flag = 1;
    return tmp;
}

int main()
{
    cin>>a>>b>>c;
    node ans = bfs();
    if(!ans.flag)
    {
        cout<<ans.step<<endl;
        for(int i=0;i<ans.step;i++)
        {
            if(ans.last[i][0]==1)
                printf("FILL(%d)\n",ans.last[i][1]);
            if(ans.last[i][0]==2)
                printf("DROP(%d)\n",ans.last[i][1]);
            if(ans.last[i][0]==3)
                printf("POUR(%d,%d)\n",ans.last[i][1],ans.last[i][2]);
        }
    }
    else
    {
        cout<<"impossible"<<endl;
    }
}