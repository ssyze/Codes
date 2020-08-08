/*
 * @Date         : 2020-07-31 11:46:02
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
pair<int, int> p[maxn];
int t, n, ans, l[maxn], r[maxn], sl, sr;

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
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int c = 0)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, c, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        for (int i = 0; i <= n; i++) vis[i] = 0;
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
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
        if (u == t || dist == 0) return dist;
        int flow = 0, f;
        for (int &i = cur[u]; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to] && (f = DFS(e.to, min(dist, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[u][i] ^ 1].flow -= f;
                flow += f;
                dist -= f;
                if (!dist) break;
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
            for (int i = 0; i <= n; i++) cur[i] = 0;
            flow += DFS(s, INF);
        }
        return flow;
    }
} d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            p[i].first = a + b;
            p[i].second = a - b;
            // cout << p[i].first << ' ' << p[i].second << endl;
        }
        sl = 0, sr = 0;
        for (int i = 0; i < n; i++) {
            l[i] = p[i].first;
            r[i] = p[i].second;
        }
        sort(l, l + n);
        sort(r, r + n);
        sl = unique(l, l + n) - l;
        sr = unique(r, r + n) - r;
        d.init(sl + sr + 2);
        for (int i = 1; i <= sl; i++) d.AddEdge(0, i, 1);
        for (int i = 1; i <= sr; i++) d.AddEdge(i + sl, sl + sr + 1, 1);
        // cout << sl << ' ' << sr << endl;
        for (int i = 0; i < n; i++) {
            int lnum = lower_bound(l, l + sl, p[i].first) - l;
            int rnum = lower_bound(r, r + sr, p[i].second) - r;
            // cout << lnum << ' ' << rnum << endl;
            d.AddEdge(lnum + 1, rnum + 1 + sl, 1);
        }
        cout << d.Maxflow(0, sl + sr + 1) << endl;
    }
}