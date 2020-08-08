/*
 * @Date         : 2020-08-07 13:55:35
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int t, n, m, num, a[maxn], f[maxn], bl, wh;
struct edge {
    ll w = 0, rw = 0, rb = 0;
} e[maxn];
vector<pair<int, int>> g[maxn];
ll w, ans;
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
void init()
{
    for (int i = 0; i <= n; i++) {
        f[i] = i;
        g[i].clear();
        e[i].w = e[i].rw = e[i].rb = 0;
    }
    w = 1, ans = 0, bl = 0, wh = 0;
}
void dfs(int u, int fa)
{
    if (a[u])
        e[u].rb++;
    else
        e[u].rw++;
    for (auto& v : g[u]) {
        if (v.first == fa) continue;
        dfs(v.first, u);
        e[u].rw += e[v.first].rw;
        e[u].rb += e[v.first].rb;
        e[v.first].w = v.second;
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i])
                bl++;
            else
                wh++;
        }
        for (int i = 1, u, v; i <= m; i++) {
            cin >> u >> v;
            w = w * 2 % mod;
            int fu = find(u), fv = find(v);
            if (fu != fv) {
                f[fu] = fv;
                g[u].push_back({v, w});
                g[v].push_back({u, w});
            }
        }
        dfs(1, -1);
        for (int i = 1; i <= n; i++) {
            // cout << e[i].w << ' ' << e[i].rb << ' ' << e[i].rw << endl;
            if (e[i].w == 0) continue;
            ll rb = e[i].rb, rw = e[i].rw;
            ll lb = bl - rb, lw = wh - rw;
            ll tmp = 1ll * rb * lw % mod;
            ans = (ans + tmp * e[i].w % mod) % mod;
            tmp = 1ll * lb * rw % mod;
            ans = (ans + tmp * e[i].w % mod) % mod;
        }
        cout << ans << endl;
    }
}
