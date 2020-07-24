/*
 * @Date         : 2020-04-09 16:31:05
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, p, k, a[maxn], dp[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = 0;
        }
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + a[i];
            if (i >= k)
                dp[i] = min(dp[i], dp[i - k] + a[i]);
            if (dp[i] <= p)
                ans = max(ans, i);
        }
        cout << ans << endl;
    }
}