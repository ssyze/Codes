/*
 * @Date         : 2020-08-04 00:05:56
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int p[maxn], t, n, m, sum[maxn], god[maxn], flag;
ll h[maxn], h1[maxn];
vector<int> g[maxn];
void init()
{
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 0; i <= n; i++) h[i] = p[i] = sum[i] = h1[i] = god[i] = 0;
}
int dfs(int u, int fa)
{
    for (auto& v : g[u]) {
        if (v == fa) continue;
        sum[u] += dfs(v, u);
    }
    sum[u] += p[u];
    if ((sum[u] + h[u]) & 1)
        flag = 0;
    else
        god[u] = (sum[u] + h[u]) / 2;
    if (god[u] > sum[u]) flag = 0;
    return sum[u];
}
void dfs2(int u, int fa)
{
    int gd = 0;
    for (auto& v : g[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        gd += god[v];
    }
    if (gd > god[u]) flag = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 0, x, y; i < n - 1; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        flag = 1;
        dfs(1, 0);
        dfs2(1, 0);
        if (!flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}