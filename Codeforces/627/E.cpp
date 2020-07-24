/*
 * @Date         : 2020-04-03 14:14:07
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int dp[maxn][maxn], a[maxn];
// dp[i][j] 第i天j点睡觉 睡好觉的次数
int n, h, l, r;
int main()
{
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < h; j++) {
            int nxt = (j + a[i]) % h;
            dp[i][nxt] = max(dp[i][nxt], dp[i - 1][j] + (nxt >= l && nxt <= r));
            nxt = (j + a[i] - 1) % h;
            dp[i][nxt] = max(dp[i][nxt], dp[i - 1][j] + (nxt >= l && nxt <= r));
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}