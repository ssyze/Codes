/*
 * @Date         : 2020-08-04 22:12:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
vector<int> g[maxn], r, s;
int n, b[maxn], vis[maxn];
ll a[maxn], ans;
void dfs(int u, int fa)
{
    for (auto& v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    if (a[u] > 0) {
        vis[u] = 1;
        ans += a[u];
        s.push_back(u);
        a[fa] += a[u];
    }
}
void dfs1(int u, int fa)
{
    if (!vis[u]) {
        ans += a[u];
        s.push_back(u);
    }
    for (auto& v : g[u]) {
        if (v == fa) continue;
        dfs1(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == -1) {
            r.push_back(i);
            continue;
        }
        g[i].push_back(b[i]);
        g[b[i]].push_back(i);
    }
    for (auto& root : r) dfs(root, -1);
    for (auto& root : r) dfs1(root, -1);
    cout << ans << '\n';
    for (auto& x : s) cout << x << ' ';
    cout << '\n';
}