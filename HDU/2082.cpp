/*
 * @Date         : 2020-02-24 15:38:00
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[100], t, a[27], sum;
int main()
{
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 26; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= 26; i++) {
            for (int j = 50; j >= 0; j--) {
                for (int k = 1; k <= a[i]; k++) {
                    if (j - k * i >= 0)
                        dp[j] += dp[j - k * i];
                }
            }
        }
        for (int i = 1; i <= 50; i++)
            ans += dp[i];
        cout << ans << endl;
    }
}