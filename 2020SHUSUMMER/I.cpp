#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<vector<int>> g;
int n, m, k;
struct point {
    int x, y, h;
    bool operator<(const point& b) const { return h < b.h; }
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        g[i].resize(m + 1);
        for (auto& x : g[i]) x = inf;
    }
    priority_queue<point> q;
    for (int i = 0, x, y, h; i < k; i++) {
        cin >> x >> y >> h;
        g[x][y] = h;
        q.push({x, y, h});
    }
    if (k == 0) q.push({1, 1, 0});
    point now;
    while (!q.empty()) {
        now = q.top();
        q.pop();
        int x = now.x, y = now.y, h = now.h;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (g[nx][ny] == inf) {
                g[nx][ny] = h - 1;
                q.push({nx, ny, h - 1});
            }
            else if (abs(g[nx][ny] - h) > 1) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << g[i][j] << ' ';
        cout << '\n';
    }
}