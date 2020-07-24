/*
 * @Date         : 2020-04-07 16:52:33
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn][maxn][2];
// dp[i][j][k][0/1] a[i]为0/1,1~i用了j个奇数，k个偶数
int n, a[maxn], oddcnt, evencnt;
int main()
{
    cin >> n;
    oddcnt = (n + 1) / 2;
    evencnt = n / 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            if (a[i] & 1)
                oddcnt--;
            else
                evencnt--;
        }
    }
    //cout << oddcnt << ' ' << evencnt << endl;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= oddcnt; j++) {
            for (int k = 0; k <= evencnt; k++) {
                if (a[i] == 0) {
                    if (k > 0)
                        dp[i][j][k][0] = min(dp[i - 1][j][k - 1][0], dp[i - 1][j][k - 1][1] + 1);
                    if (j > 0)
                        dp[i][j][k][1] = min(dp[i - 1][j - 1][k][0] + 1, dp[i - 1][j - 1][k][1]);
                }
                else if (a[i] & 1)
                    dp[i][j][k][1] = min(dp[i - 1][j][k][0] + 1, dp[i - 1][j][k][1]);
                else
                    dp[i][j][k][0] = min(dp[i - 1][j][k][1] + 1, dp[i - 1][j][k][0]);
                //cout << i << ' ' << j << ' ' << k << endl;
                //cout << dp[i][j][k][0] << ' ' << dp[i][j][k][1] << endl;
            }
        }
    }
    //cout << dp[n][oddcnt][evencnt][0] << ' ' << dp[n][oddcnt][evencnt][1] << endl;
    cout << min(dp[n][oddcnt][evencnt][0], dp[n][oddcnt][evencnt][1]) << endl;
}