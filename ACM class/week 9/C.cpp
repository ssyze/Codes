/*
 * @Date         : 2020-02-10 13:39:38
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
const int INF = 0x3f3f3f3f;
struct Edge {
    int from, to, cap, flow;
};
struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int c = 0)
    {
        edges.push_back(Edge { from, to, cap, 0 });
        edges.push_back(Edge { to, from, c, 0 });
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int u, int dist)
    {
        if (u == t || dist == 0)
            return dist;
        int flow = 0, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to] && (f = DFS(e.to, min(dist, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[u][i] ^ 1].flow -= f;
                flow += f;
                dist -= f;
                if (!dist)
                    break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} net;
int n, m, t, Case;
char g[maxn][maxn];
pair<int, int> s[maxn], e[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> m >> n;
        //int cnt1 = 0, cnt2 = 0;
        net.init(n);
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--;
            net.AddEdge(x, y, z);
        }
        int ans = net.Maxflow(0, n - 1);
        printf("Case %d: %d\n", ++Case, ans);
    }
}