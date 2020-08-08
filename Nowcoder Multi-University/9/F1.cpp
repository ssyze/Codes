/*
 * @Date         : 2020-08-08 13:48:25
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m, sum;
vector<int> a[maxn];
vector<pair<int, int>> p;
int vis[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(vis, -1, sizeof(vis));
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto &x : a[i]) p.push_back({x, i});
    }
    sort(p.begin(), p.end());
    int i = 0, l = 0;
    while (sum < m) {
        if (vis[p[i].second] == -1) vis[p[i].second] = i, sum++, i++;
    }
    int ans = p[i - 1].first - p[0].first;
    for (; i < p.size(); i++) {
        if (vis[p[i].second] != -1) {
            int pos = vis[p[i].second];
            if (pos == l) l = l + 1;
            vis[p[i].second] = i;
        }
        else if (vis[p[i].second] == -1) {
            vis[p[i].second] = 1;
            if (vis[p[l].second] == l) vis[p[l].second] = -1;
            l = l + 1;
        }
        ans = min(ans, p[i].first - p[l].first);
    }
    cout << ans << endl;
}