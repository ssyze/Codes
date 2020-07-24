/*
 * @Date         : 2020-03-04 16:37:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, ans, cnt;
vector<int> g[maxn];
bool vis[maxn];
void dfs(int v, int d)
{
    //cout << v << " * " << d << endl;
    vis[v] = 1;
    cnt++;
    ans = max(ans, d);
    for (int i = 0; i < g[v].size(); i++) {
        if (!vis[g[v][i]]) {
            dfs(g[v][i], d + 1);
        }
    }
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 0, ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        dfs(0, 1);
        cout << ans << ' ' << cnt << endl;
        for (int i = 0; i <= cnt; i++) {
            g[i].clear();
        }
    }
}