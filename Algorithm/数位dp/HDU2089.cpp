/*
 * @Date         : 2020-07-29 16:14:10
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int dp[10][2], a[10];
// dp[pos][if6]
int n, m;

int dfs(int pos, int lim, int six)
{
    if (pos == -1) return 1;
    if (!lim && dp[pos][six] != -1) return dp[pos][six];
    int up = lim ? a[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++) {
        if (i == 4) continue;
        if (six && i == 2) continue;
        ans += dfs(pos - 1, lim && i == a[pos], i == 6);
    }
    if (!lim) dp[pos][six] = ans;
    return ans;
}

int solve(int x)
{
    memset(dp, -1, sizeof(dp));
    int pos = 0;
    while (x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 1, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n && m) {
        cout << solve(m) - solve(n - 1) << endl;
    }
}