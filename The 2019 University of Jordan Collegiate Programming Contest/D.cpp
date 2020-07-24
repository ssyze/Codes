/*
 * @Date         : 2020-01-29 13:05:30
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int g[15][15];
bool vis[15][15];
int t, r, c;
int dx[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
struct node {
    int x, y;
    int step = 0;
    int l[50];
};
bool can_vis(int x, int y)
{
    if (x < 1 || y < 1 || x > 12 || y > 12)
        return 0;
    if (vis[x][y])
        return 0;
    if (g[x][y] == 2)
        return 0;
    return 1;
}
node bfs()
{
    node cur, next;
    cur.x = r;
    cur.y = c;
    queue<node> q;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (g[cur.x][cur.y] == 1) {
            return cur;
        }
        for (int i = 0; i < 4; i++) {
            next = cur;
            next.x = cur.x + dx[i][0];
            next.y = cur.y + dx[i][1];
            if (can_vis(next.x, next.y)) {
                next.step = cur.step + 1;
                next.l[cur.step] = i;
                q.push(next);
            }
        }
    }
}
int main()
{
    g[3][3] = g[3][10] = g[10][3] = g[10][10] = 1;
    g[6][6] = g[6][7] = g[7][6] = g[7][7] = 2;
    g[9][2] = g[9][3] = g[10][2] = 2;
    g[9][10] = g[9][11] = g[10][11] = 2;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        memset(vis, 0, sizeof(vis));
        node ans = bfs();
        cout << ans.step << endl;
        for (int i = 0; i < ans.step; i++) {
            if (ans.l[i] == 0)
                cout << 'D';
            if (ans.l[i] == 1)
                cout << 'U';
            if (ans.l[i] == 2)
                cout << 'R';
            if (ans.l[i] == 3)
                cout << 'L';
        }
        cout << endl;
    }
}