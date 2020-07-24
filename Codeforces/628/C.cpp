/*
 * @Date         : 2020-03-20 16:29:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<pair<int, int>> g[maxn];
int n, ans[maxn], tmp, vis[maxn];
int main()
{
    memset(ans, -1, sizeof(ans));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({ y, i });
        g[y].push_back({ x, i });
    }
    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            ans[g[i][0].second] = tmp++;
        }
    }
    for (int i = 1; i < n; i++) {
        if (ans[i] == -1)
            ans[i] = tmp++;
        cout << ans[i] << endl;
    }
}