/*
 * @Date         : 2020-03-25 16:03:01
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
//first是最短距离 second是顶点的编号
//利用pair与利用结构体相同
typedef pair<int, int> P;
typedef long long ll;
struct edge {
    int to;
    ll val;
    edge(int a = 0, ll b = 0)
    {
        to = a;
        val = b;
    }
};
vector<edge> mp[maxn]; //邻接表存图
ll d[maxn]; //存距离
void dijkstra(int s) //起点
{
    //通过greater<P> 按照first从小到大取值
    priority_queue<P, vector<P>, greater<P>> que;
    memset(d, INF, sizeof(d)); //所有距离设置为INF
    d[s] = 0; //起点的距离为0
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        //若到v点的距离，小于pair中存的最短距离
        if (d[v] < p.first)
            continue;
        //遍历邻接表中v点能到的所有点
        for (int i = 0; i < mp[v].size(); i++) {
            edge e = mp[v][i];
            //若直接到i点的距离大于先到v点再从v点到i点的距离
            //则更新
            if (d[e.to] > d[v] + e.val) {
                d[e.to] = d[v] + e.val;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int n, m;
int main()
{
    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            mp[x].push_back({ y, z });
            mp[y].push_back({ x, z });
        }
        dijkstra(1);
        cout << d[n] << endl;
        for (int i = 0; i <= n; i++) {
            mp[i].clear();
        }
    }
}