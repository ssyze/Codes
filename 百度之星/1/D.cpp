/*
 * @Date         : 2020-07-19 15:36:25
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int t, n, x, y, g[maxn][maxn], st[10];
bool can_vis(int x, int y, int xx, int yy)
{
    if (x < 1 || y < 1 || x > n || y > n) return false;
    if (abs(xx - x) + abs(yy - y) > 3) return false;
    return true;
}
int solve(int xx, int yy)
{
    int round = 0;
    round += (abs(xx - x) + abs(yy - y) + 1) / 2;
    vector<int> food;
    for (int i = xx - 3; i <= xx + 3; i++) {
        for (int j = yy - 3; j <= yy + 3; j++) {
            if (i == xx && j == yy) continue;
            if (can_vis(i, j, xx, yy)) food.push_back(g[i][j]);
        }
    }
    // cout << "ok" << endl;
    sort(food.begin(), food.end(), greater<int>());
    int now = g[xx][yy], sum = 0;
    for (int i = 1; i <= 8; i++) {
        int ti = (st[i] - sum + now - 1) / now;
        sum += ti * now;
        // cout << sum << ' ';
        round += ti;
        if ((i - 1) < food.size()) now += food[i - 1];
    }
    // cout << endl;
    return round;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 9; i++) st[i] = i * i * 8;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cin >> g[i][j];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans = min(ans, solve(i, j));
                // cout << solve(i, j) << ' ';
            }
            // cout << endl;
        }
        cout << ans << '\n';
    }
}