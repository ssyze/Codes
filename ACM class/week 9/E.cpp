/*
 * @Date         : 2020-03-18 16:51:41
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7;
const int INF = 0x3f3f3f3f;
struct Edge {
    int from, to, cap, flow, cost;
};
struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn]; //最短路数组
    int p[maxn]; //记录路径
    int a[maxn]; //记录流量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge { from, to, cap, 0, cost });
        edges.push_back(Edge { to, from, 0, 0, -cost });
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool spfa(int s, int t, int& flow, int& cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost; //松弛
                    p[e.to] = G[u][i]; //记录上一个点
                    a[e.to] = min(a[u], e.cap - e.flow); //流量控制
                    if (!inq[e.to]) {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF)
            return false; //不存在最短路
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    int Mincost(int s, int t)
    {
        int flow = 0, cost = 0;
        while (spfa(s, t, flow, cost))
            ;
        return cost;
    }
};
int n;
int g[1005][1005];
int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> g[i][j];
            }
        }
        MCMF net;
        int tot = n * n;
        net.init(2 * tot + 2);
        int s = 0, t = 2 * tot + 1;
        net.addedge(s, 1, 2, 0);
        net.addedge(t - 1, t, 2, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int tmp = (i - 1) * n + j, cap = 1;
                if ((i == 1 && j == 1) || (i == n && j == n))
                    cap = 2;
                net.addedge(tmp, tmp + tot, cap, -g[i][j]);
                if (i < n)
                    net.addedge(tmp + tot, tmp + n, cap, 0);
                if (j < n)
                    net.addedge(tmp + tot, tmp + 1, cap, 0);
            }
        }
        int ans = net.Mincost(s, t);
        cout << -ans - g[1][1] - g[n][n] << endl;
    }
}