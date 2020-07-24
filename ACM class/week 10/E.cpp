/*
 * @Date         : 2020-03-25 16:38:05
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int m, n, ans;
char g[maxn][maxn];
bool vis[maxn][maxn];
int res[505 * 505];
int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
bool can_vis(int x, int y)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;
    if (vis[x][y])
        return false;
    if (g[x][y] == '1')
        return false;
    return true;
}
void dfs(int x, int y)
{
    res[ans]++;
    vis[x][y] = 1;
    int tmpx, tmpy;
    for (int i = 0; i < 8; i++) {
        tmpx = x + dx[i];
        tmpy = y + dy[i];
        if (can_vis(tmpx, tmpy))
            dfs(tmpx, tmpy);
    }
    return;
}
int main()
{
    while (cin >> m >> n && m && n) {
        memset(vis, 0, sizeof(vis));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && g[i][j] == '0')
                    ans++, dfs(i, j);
            }
        }
        sort(res, res + ans);
        cout << ans << ' ' << res[ans - 1] << endl;
    }
}
