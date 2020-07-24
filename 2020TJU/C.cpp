/*
 * @Date         : 2020-05-11 17:06:10
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int n, dp[maxn][maxn][2];
// dp[l][r][0]表示l-r在l停止最小时间
// dp[l][r][1]表示l-r在r停止最小时间
int main()
{
    cin >> n;
    vector<int> p(n), t(n);
    for (auto& x : p)
        cin >> x;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] == 0)
            pos = i;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[pos][pos][0] = dp[pos][pos][1] = 0;
    for (int len = 2; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++, r++) {
            int ti = min(dp[l + 1][r][1] + p[r] - p[l], dp[l + 1][r][0] + p[l + 1] - p[l]);
            if (ti <= t[l])
                dp[l][r][0] = min(dp[l][r][0], ti);
            ti = min(dp[l][r - 1][0] + p[r] - p[l], dp[l][r - 1][1] + p[r] - p[r - 1]);
            if (ti <= t[r])
                dp[l][r][1] = min(dp[l][r][1], ti);
        }
    }
    int ans = min(dp[0][n - 1][0], dp[0][n - 1][1]);
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}