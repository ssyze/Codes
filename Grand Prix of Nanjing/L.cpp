/*
 * @Date         : 2020-05-03 17:11:34
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t;
int x[5], y[5], _x[5], _y[5];
int mp[10][10];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[10][10];
bool can_vis(int x, int y)
{
    if (x < 0 || y < 0 || x >= 10 || y >= 10)
        return 0;
    if (vis[x][y])
        return 0;
    if (mp[x][y])
        return 0;
    return 1;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    int tmpx, tmpy;
    for (int i = 0; i < 4; i++) {
        tmpx = x + dx[i];
        tmpy = y + dy[i];
        if (can_vis(tmpx, tmpy))
            dfs(tmpx, tmpy);
    }
    return;
}
int main()
{
    cin >> t;
    while (t--) {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 4; i++) {
            cin >> x[i] >> y[i];
            _x[i] = x[i];
            _y[i] = y[i];
        }
        sort(x + 1, x + 5);
        sort(y + 1, y + 5);
        int xx = unique(x + 1, x + 5) - x;
        int yy = unique(y + 1, y + 5) - y;
        for (int i = 1; i <= 4; i++) {
            _x[i] = lower_bound(x + 1, x + 5, _x[i]) - x;
            _x[i] = _x[i] * 2 - 1;
            _y[i] = lower_bound(y + 1, y + 5, _y[i]) - y;
            _y[i] = _y[i] * 2 - 1;
        }
        for (int i = _y[1]; i <= _y[2]; i++) {
            mp[_x[1]][i] = 1;
            mp[_x[2]][i] = 1;
        }
        for (int i = _y[3]; i <= _y[4]; i++) {
            mp[_x[3]][i] = 1;
            mp[_x[4]][i] = 1;
        }
        for (int i = _x[1]; i <= _x[2]; i++) {
            mp[i][_y[1]] = 1;
            mp[i][_y[2]] = 1;
        }
        for (int i = _x[3]; i <= _x[4]; i++) {
            mp[i][_y[3]] = 1;
            mp[i][_y[4]] = 1;
        }
        /* for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << mp[i][j];
            }
            cout << endl;
        } */
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (!vis[i][j] && mp[i][j] == 0) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}