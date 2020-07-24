/*
 * @Date         : 2020-04-19 14:52:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ll;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int INF = 0x7f7f7f7f;
const int maxn = 2e5 + 7;
struct Edge {
    int from, to;
    ll cap, flow;
    Edge(int u, int v, ll c, ll f)
        : from(u)
        , to(v)
        , cap(c)
        , flow(f)
    {
    }
};
struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from, int to, ll cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, ll a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(ll(a), e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
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
} ans;
int sum, n, e, c[maxn], g[maxn][8], s, t, st, en;
bool check(int x)
{
    for (int i = st; i < en; i += 2) {
        ans.edges[i].cap = 1ll * x / 7 * e;
    }
    for (int i = st, j = 0; j < x % 7; i += 2, j++) {
        ans.edges[i].cap += e;
    }
    for (int i = 0; i < ans.edges.size(); i++)
        ans.edges[i].flow = 0;
    return sum == ans.Maxflow(0, n + 8);
}

int main()
{
    scanf("%d%d", &n, &e);
    for (int u = 1; u <= n; u++) {
        int c, m;
        scanf("%d%d", &c, &m);
        ans.AddEdge(0, u, c);
        sum += c;
        for (int j = 0, v; j < m; j++) {
            scanf("%d", &v);
            ans.AddEdge(u, n + v, INF);
        }
    }
    st = ans.edges.size();
    for (int i = 1, j = n + 1; i <= 7; i++, j++)
        ans.AddEdge(j, n + 8, 0);
    en = ans.edges.size();
    int l = 1, r = INF;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}