#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int a[maxn], n, m, b[5];
int dp[41][41][41][41];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    int ans = 0;
    dp[0][0][0][0] = a[1];
    for (int i = 0; i <= b[1]; i++) {
        for (int j = 0; j <= b[2]; j++) {
            for (int p = 0; p <= b[3]; p++) {
                for (int q = 0; q <= b[4]; q++) {
                    int pos = i + 2 * j + 3 * p + 4 * q + 1;
                    if (i) dp[i][j][p][q] = max(dp[i - 1][j][p][q] + a[pos], dp[i][j][p][q]);
                    if (j) dp[i][j][p][q] = max(dp[i][j - 1][p][q] + a[pos], dp[i][j][p][q]);
                    if (p) dp[i][j][p][q] = max(dp[i][j][p - 1][q] + a[pos], dp[i][j][p][q]);
                    if (q) dp[i][j][p][q] = max(dp[i][j][p][q - 1] + a[pos], dp[i][j][p][q]);
                    if (pos == n) ans = max(ans, dp[i][j][p][q]);
                }
            }
        }
    }
    cout << ans << endl;
}