/*
 * @Date         : 2020-05-11 11:17:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
char g[15][15];
int w, h, k, flag;
vector<pair<int, int>> car;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
bool can_vis(int x, int y, vector<pair<int, int>>& car)
{
    if (x < 0 || y < 0 || x >= h || y >= w)
        return 0;
    if (g[x][y] == 'X')
        return 0;
    for (auto& c : car) {
        if (x == c.first && y == c.second)
            return 0;
    }
    return 1;
}
void dfs(int t, vector<pair<int, int>> car)
{
    /* for (auto& x : car)
        cout << x.first << ' ' << x.second << ' ';
    cout << t << ' ' << endl; */
    if (flag)
        return;
    if (t == k) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (g[i][j] == 'D') {
                    for (auto& x : car) {
                        if (x.first == i && x.second == j) {
                            flag = 1;
                            return;
                        }
                    }
                }
            }
        }
        return;
    }
    for (auto& c : car) {
        int x = c.first, y = c.second;
        for (int i = 0; i < 4; i++) {
            while (can_vis(c.first + dx[i], c.second + dy[i], car))
                c.first += dx[i], c.second += dy[i];
            dfs(t + 1, car);
            c.first = x, c.second = y;
        }
    }
}
int main()
{
    //freopen("t1.txt", "w", stdout);
    cin >> w >> h >> k;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'R') {
                car.push_back({ i, j });
                g[i][j] = '.';
            }
        }
    }
    dfs(0, car);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}