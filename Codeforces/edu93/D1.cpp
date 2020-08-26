/*
 * @Date         : 2020-08-19 23:35:28
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 205;
int rr, gg, bb;
int r[maxn], g[maxn], b[maxn];
ll dp[maxn][maxn][maxn], ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> rr >> gg >> bb;
    for (int i = 1; i <= rr; i++) cin >> r[i];
    for (int i = 1; i <= gg; i++) cin >> g[i];
    for (int i = 1; i <= bb; i++) cin >> b[i];
    sort(r + 1, r + 1 + rr, greater<int>());
    sort(g + 1, g + 1 + gg, greater<int>());
    sort(b + 1, b + 1 + bb, greater<int>());
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = 0;
    for (int i = 0; i <= rr; i++) {
        for (int j = 0; j <= gg; j++) {
            for (int k = 0; k <= bb; k++) {
                if (i != 0 && j != 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
                if (i != 0 && k != 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
                if (j != 0 && k != 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
                // printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}