/*
 * @Date         : 2020-02-06 17:21:53
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2005;
int a[maxn];
long long dp[maxn][maxn];
//前i题做对j题
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] * (mod + 1 - a[i]) % mod;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * (mod + 1 - a[i]) % mod + dp[i - 1][j - 1] * a[i] % mod;
            dp[i][j] %= mod;
        }
    }
    for (int i = 0; i <= n; i++)
        cout << dp[n][i] << ' ';
    cout << endl;
}