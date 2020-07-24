/*
 * @Date         : 2020-02-08 13:22:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char g[55][55];
int n, m;
int dp[55][55];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'R')
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            else if (g[i][j] == 'D')
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            else {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][m] % mod << endl;
}