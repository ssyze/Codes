/*
 * @Date         : 2020-05-10 15:25:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int w, h, k, cnum, p[4][2], flag;
char g[15][15], m[15][15], m1[15][15];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
bool can_vis(int x, int y)
{
    if (x < 0 || y < 0 || x >= h || y >= w)
        return 0;
    if (m[x][y] == 'X')
        return 0;
    if (m[x][y] == 'R')
        return 0;
    return 1;
}
void dfs(int s, int k, int now)
{
    for (int i1 = 0; i1 < h; i1++) {
        for (int j1 = 0; j1 < w; j1++)
            cout << m[i1][j1];
        cout << endl;
    }
    cout << k << endl;
    if (k == 0) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (g[i][j] == 'D' && m[i][j] == 'R') {
                    flag = 1;
                    return;
                }
            }
        }
        return;
    }
    int tmpx = p[now][0], tmpy = p[now][1];
    for (int i = 0; i < 4; i++) {
        int x = p[now][0], y = p[now][1];
        while (can_vis(x + dx[i], y + dy[i]))
            x += dx[i], y += dy[i];
        if (m[x + dx[i]][y + dy[i]] == 'R')
            x += dx[i], y += dy[i];
        p[now][0] = x, p[now][1] = y;
        m[tmpx][tmpy] = '.';
        m[x][y] = 'R';
        for (int j = 0; j < cnum; j++) {
            dfs(s, k - 1, j);
            m[tmpx][tmpy] = '.';
            m[x][y] = 'R';
            p[now][0] = x, p[now][1] = y;
        }
        m[x][y] = '.';
        m[tmpx][tmpy] = 'R';
        p[now][0] = tmpx, p[now][1] = tmpy;
    }
}
int main()
{
    freopen("t.txt", "w", stdout);
    cin >> w >> h >> k;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> g[i][j];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'R') {
                p[cnum][0] = i;
                p[cnum][1] = j;
                cnum++;
            }
        }
    }
    for (int _ = 0; _ < 1; _++) {
        int _c = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                m[i][j] = g[i][j];
                if (m[i][j] == 'R')
                    p[_c][0] = i, p[_c][1] = j;
                if (m[i][j] == 'D')
                    m[i][j] = '.';
            }
        }
        dfs(_, k, _);
        if (flag)
            break;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}