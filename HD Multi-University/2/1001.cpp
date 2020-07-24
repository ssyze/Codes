/*
 * @Date         : 2020-07-23 16:07:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
pair<int, int> c[maxn];
int t, n, m, b[maxn], fa[maxn], vis[maxn], sum[maxn];
ll ans;
vector<int> g[maxn];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}
void init(int n)
{
    for (int i = 0; i <= n; i++) fa[i] = i, vis[i] = 0;
    for (int i = 1; i <= n; i++) {
        c[i].first = i;
        c[i].second = b[i];
        sum[i] = b[i];
    }
    for (int i = 0; i <= n; i++) g[i].clear();
    ans = 0;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
void add(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    ans += sum[v] - sum[u];
    fa[v] = u;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> b[i];
        init(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        sort(c + 1, c + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int u = c[i].first;
            vis[u] = 1;
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j];
                if (vis[v]) add(u, v);
            }
        }
        for (int i = 1; i <= n; i++)
            if (fa[i] == i) ans += sum[i];
        cout << ans << '\n';
    }
}