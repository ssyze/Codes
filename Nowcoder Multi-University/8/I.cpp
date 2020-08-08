#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;

pair<int, int> pii[maxn];
int t, n, kase;
vector<int> c;

struct Dinic {
    struct edge {
        int to, f, nxt;
    };
    int n, m, S, T, tot;
    vector<edge> e;
    vector<int> head, cur, dep;

    void add(int u, int v, int f)
    {
        e[tot].to = v;
        e[tot].f = f;
        e[tot].nxt = head[u];
        head[u] = tot++;
        e[tot].to = u;
        e[tot].f = 0;
        e[tot].nxt = head[v];
        head[v] = tot++;
    }

    int bfs(int node)
    {
        for (int i = 1; i <= n; ++i) dep[i] = 0, cur[i] = head[i];
        dep[node] = 1;
        queue<int> Q;
        Q.push(node);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = head[x]; i != -1; i = e[i].nxt) {
                int y = e[i].to, f = e[i].f;
                if (!dep[y] && f) {
                    dep[y] = dep[x] + 1;
                    Q.push(y);
                }
            }
        }
        return dep[T];
    }

    int dfs(int x, int flow)  // dfs找增广路
    {
        if (x == T) {
            return flow;
        }
        int sum = 0;
        for (int i = cur[x]; i != -1; i = e[i].nxt) {
            cur[x] = i;
            int y = e[i].to, f = e[i].f;
            if (f && dep[y] == dep[x] + 1) {
                int t = dfs(y, min(flow - sum, f));  // 优化1
                sum += t;
                e[i].f -= t;
                e[i ^ 1].f += t;
                if (sum == flow) break;  // 优化1
            }
        }
        if (sum == 0) {  // 如果sum==0，那么这个点之前没有增广路，深度清零
            dep[x] = 0;
        }
        return sum;
    }

    int run()
    {
        int ans = 0;
        while (bfs(S)) {
            ans += dfs(S, inf);
        }
        return ans;
    }

    //边数尽量给多以防RE
    void init(int _n, int _m, int _S, int _T)
    {
        n = _m, m = _m, S = _S, T = _T, tot = 0;
        e.resize(m + 100);
        head.assign(n + 100, -1);
        cur.assign(n + 100, 0);
        dep.assign(n + 100, 0);
    }
} din;

int idx(int x)
{
    int l = 0, r = c.size() - 1;
    while (l < r) {
        int m = l + r >> 1;
        if (c[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return l + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        c.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> pii[i].first >> pii[i].second;
            if (pii[i].first < pii[i].second) swap(pii[i].first, pii[i].second);
            c.push_back(pii[i].first);
            c.push_back(pii[i].second);
        }
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        din.init(3 * c.size() + 2, 10 * c.size(), 3 * c.size() + 1, 3 * c.size() + 2);
        for (int i = 1; i <= c.size(); ++i)
            din.add(din.S, i, n), din.add(2 * c.size() + i, din.T, 1);
        for (int i = 1; i <= n; ++i) {
            int fi = idx(pii[i].first), se = idx(pii[i].second);
            din.add(fi, se + c.size(), 1);
            din.add(se + c.size(), fi + 2 * c.size(), 1);
            din.add(se + c.size(), se + c.size() * 2, 1);
        }
        cout << "Case #" << ++kase << ": " << din.run() << endl;
    }
}
