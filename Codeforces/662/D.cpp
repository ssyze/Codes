/*
 * @Date         : 2020-08-08 01:53:40
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int dp[maxn][maxn];
char g[maxn][maxn];
int m, n, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != g[i - 1][j] || g[i][j] != g[i - 2][j] || g[i][j] != g[i - 1][j - 1] ||
                g[i][j] != g[i - 1][j + 1])
                dp[i][j] = 1;
            else
                dp[i][j] =
                    min({dp[i - 1][j], dp[i - 2][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + 1;
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
}