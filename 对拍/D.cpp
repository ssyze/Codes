/*
 * @Date         : 2020-01-07 13:39:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int x[maxn], y[maxn], t[maxn], dp[maxn];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}