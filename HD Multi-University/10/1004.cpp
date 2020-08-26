/*
 * @Date         : 2020-08-21 13:10:15
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 1e9 + 7;
int t, n, dp[maxn][maxn], a[maxn];
int main()
{
    // freopen("1004.in", "r", stdin);
    // freopen("1004.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) cin >> a[i];
        memset(dp, 0, sizeof(dp));
        if (a[1] == 1) dp[2][1] = 1;
        if (a[1] == 0) dp[2][2] = 1;
        for (int i = 2; i < n; i++) {
            if (a[i] == 1) {
                for (int j = i; j >= 1; j--) dp[i + 1][j] = (dp[i][j] + dp[i + 1][j + 1]) % mod;
            }
            if (a[i] == 0) {
                for (int j = 1; j <= i + 1; j++)
                    dp[i + 1][j] = (dp[i][j - 1] + dp[i + 1][j - 1]) % mod;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) cout << dp[n][i] << '\n';
        for (int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % mod;
        cout << ans << '\n';
    }
}