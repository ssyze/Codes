/*
 * @Date         : 2020-07-21 16:08:09
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e5 + 10;
int t, n, m, x, y, q, u, fa[maxn];
vector<int> g[maxn];
int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cin >> q;
        while (q--) {
            cin >> u;
            if (fa[u] != u) continue;
            vector<int> tmp = g[u];
            g[u].clear();
            for (auto& x : tmp) {
                int v = find(x);
                if (v != u) {
                    fa[v] = u;
                    for (auto& y : g[v]) g[u].push_back(y);
                }
            }
        }
        for (int i = 0; i < n; i++) cout << find(i) << ' ';
        cout << endl;
    }
}