/*
 * @Date         : 2020-03-28 18:33:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
int g[maxn][maxn];
int n, m;
int main()
{
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        if (g[1][1] == -1 || g[n][m] == -1) {
            cout << "Impossible" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((g[i - 1][j] == -1 || dp[i - 1][j] == -1) && (dp[i][j - 1] == -1 || g[i][j - 1] == -1))
                    dp[i][j] = -1;
                else if (g[i - 1][j] == -1 || dp[i - 1][j] == -1)
                    dp[i][j] = dp[i][j - 1] + g[i][j];
                else if (g[i][j - 1] == -1 || dp[i][j - 1] == -1)
                    dp[i][j] = dp[i - 1][j] + g[i][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
            }
        }
        if (dp[n][m] == -1)
            cout << "Impossible" << endl;
        else
            cout << dp[n][m] << endl;
    }
}