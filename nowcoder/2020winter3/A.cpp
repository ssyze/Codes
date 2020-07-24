/*
 * @Date         : 2020-02-08 13:03:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
char g[55][55];
int n, m, ans;
bool vis[55][55];
bool can_vis(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return 0;
    return 1;
}
void dfs(int x, int y)
{
    if (x == n && y == m) {
        ans++;
        if (ans > mod)
            ans %= mod;
        return;
    }
    vis[x][y] = 1;
    if (g[x][y] == 'R') {
        int nx = x;
        int ny = y + 1;
        if (can_vis(nx, ny) && !vis[nx][ny])
            dfs(nx, ny);
    }
    else if (g[x][y] == 'D') {
        int nx = x + 1;
        int ny = y;
        if (can_vis(nx, ny) && !vis[nx][ny])
            dfs(nx, ny);
    }
    else if (g[x][y] == 'B') {
        int nx = x + 1;
        int ny = y;
        if (can_vis(nx, ny) && !vis[nx][ny])
            dfs(nx, ny);
        nx = x;
        ny = y + 1;
        if (can_vis(nx, ny) && !vis[nx][ny])
            dfs(nx, ny);
    }
    vis[x][y] = 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
}