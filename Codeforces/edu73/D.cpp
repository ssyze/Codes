/*
 * @Date         : 2020-04-09 17:43:36
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[maxn][3];
int n, q, a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            dp[i][0] = dp[i][1] = dp[i][2] = inf;
        }
        dp[0][0] = dp[0][1] = dp[0][2] = dp[1][0] = 0;
        dp[1][1] = b[1];
        dp[1][2] = 2 * b[1];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i] + j != a[i - 1] + k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                    }
                }
            }
        }
        cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    }
}