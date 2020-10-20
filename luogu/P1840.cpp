#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int inf = 0x3f3f3f3f;
int g[305][305];
int n, m, v, e;
int c[maxn], d[maxn];
double k[maxn];
double dp[maxn][maxn][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("P1850_2.in", "r", stdin);
    // memset(dp, 0x3f, sizeof(dp));
    cin >> n >> m >> v >> e;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) { dp[i][j][0] = dp[i][j][1] = 1e9; }
    }
    for (int i = 0; i <= v; i++) {
        for (int j = 0; j <= v; j++) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = 10000007;
        }
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 0; i < e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = min(z, g[x][y]);
    }
    for (int q = 1; q <= v; q++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) { g[i][j] = min(g[i][j], g[i][q] + g[q][j]); }
        }
    }
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        int pre0 = c[i - 1], pre1 = d[i - 1];
        int cur0 = c[i], cur1 = d[i];
        for (int j = 0; j <= m; j++) {
            if (j == 0)
                dp[i][j][0] = dp[i - 1][j][0] + g[pre0][cur0];
            else {
                dp[i][j][0] = min(dp[i - 1][j][0] + g[pre0][cur0],
                    dp[i - 1][j][1] + k[i - 1] * g[pre1][cur0] + (1.0 - k[i - 1]) * g[pre0][cur0]);
                dp[i][j][1]
                    = min({ dp[i - 1][j - 1][0] + k[i] * g[pre0][cur1] + (1 - k[i]) * g[pre0][cur0],
                        dp[i - 1][j - 1][1] + k[i] * k[i - 1] * g[pre1][cur1]
                            + (1 - k[i]) * k[i - 1] * g[pre1][cur0]
                            + k[i] * (1 - k[i - 1]) * g[pre0][cur1]
                            + (1 - k[i]) * (1 - k[i - 1]) * g[pre0][cur0] });
            }
        }
    }
    double ans = 1e9;
    for (int i = 0; i <= m; i++) { ans = min({ ans, dp[n][i][0], dp[n][i][1] }); }
    cout << fixed << setprecision(2) << ans << '\n';
}