/*
 * @Date         : 2020-08-14 20:01:24
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 9;
int n, m, dp[205][maxn], a[205], b[205];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 1 << 9; k++) {
                if (dp[i - 1][k]) dp[i][k | a[i] & b[j]] = 1;
            }
        }
    }
    for (int i = 0; i < 1 << 9; i++)
        if (dp[n][i]) {
            cout << i << endl;
            break;
        }
}