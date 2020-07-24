/*
 * @Date         : 2020-04-03 15:59:03
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int mod = 1e9 + 7;
int dp[maxn][2];
int n, k, d;
int main()
{
    dp[0][1] = 0;
    dp[0][0] = 1;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;
        for (int j = 1; j <= k; j++) {
            if (j < d && i - j >= 0) {
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
            else if (j >= d && i - j >= 0) {
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
        }
    }
    cout << dp[n][1] % mod << endl;
}