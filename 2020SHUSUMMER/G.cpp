/*
 * @Date         : 2020-08-05 16:53:37
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll dp[maxn][5][2], ans, a[maxn];
int n, x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    memset(dp, -0x3f, sizeof(dp));
    dp[0][2][0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i != x) {
            for (int j = 0; j < 5; j++) {
                if (i % 2)
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                else if (j < 4)
                    dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
            }
        }
        for (int j = 0; j < 5; j++) {
            if (i % 2 && j >= 1)
                dp[i][j][1] = dp[i - 1][j - 1][0] + a[i];
            else
                dp[i][j][1] = dp[i - 1][j][0] + a[i];
        }
    }
    cout << max(dp[n][2][0], dp[n][2][1]) << endl;
}