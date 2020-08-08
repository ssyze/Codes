/*
 * @Date         : 2020-07-24 21:52:31
 * @Author       : ssyze
 * @Description  : dfs && bfs
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, ans, vis[maxn][maxn];
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
char g[maxn][maxn];
bool can_vis(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (g[x][y] == '*' || vis[x][y]) return 0;
    return 1;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (can_vis(xx, yy)) dfs(xx, yy);
    }
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    pair<int, int> f, nxt;
    while (!q.empty()) {
        f = q.front();
        q.pop();
        g[f.first][f.second] = '*';
        // vis[f.first][f.second] = 1;
        for (int i = 0; i < 8; i++) {
            nxt.first = f.first + dx[i], nxt.second = f.second + dy[i];
            if (can_vis(nxt.first, nxt.second)) q.push(nxt);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n && m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    ans++;
                    bfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
}