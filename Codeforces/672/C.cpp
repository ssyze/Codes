#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int t, n, q, a[maxn];
ll dp[maxn][3];
// dp[i][j] pos i, 0 nxt add, 1 nxt minus
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp[1][0] = 0, dp[1][1] = a[1];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][1] - a[i], dp[i - 1][0]);
            dp[i][1] = max({ 1LL * a[i], dp[i - 1][0] + a[i], dp[i - 1][1] });
            // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
        }
        cout << max(dp[n][1], dp[n][0]) << '\n';
    }
}