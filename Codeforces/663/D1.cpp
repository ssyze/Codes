/*
 * @Date         : 2020-08-10 00:58:26
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m;
int dp[maxn][8];
char x;
vector<vector<int>> g;
vector<int> num;
int dif(int x)
{
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (x & 1) ans++;
        x >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> x;
            g[i][j] = x - '0';
        }
    }
    if (n > 3 && m > 3) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1 || m == 1) {
        cout << 0 << endl;
        return 0;
    }
    // memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (g[j][i]) sum += (1 << j);
        }
        num.push_back(sum);
    }
    if (n == 2) {
        for (int i = 0; i < 4; i++) dp[0][i] += dif(num[0] ^ i);
        for (int i = 1; i < m; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dif(num[i] ^ 0);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][3]) + dif(num[i] ^ 1);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][3]) + dif(num[i] ^ 2);
            dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + dif(num[i] ^ 3);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 4; i++) ans = min(ans, dp[m - 1][i]);
        cout << ans << endl;
    }
    else {
        for (int i = 0; i < 8; i++) dp[0][i] += dif(num[0] ^ i);
        for (int i = 1; i < m; i++) {
            dp[i][0] = min(dp[i - 1][2], dp[i - 1][5]) + dif(num[i] ^ 0);
            dp[i][1] = min(dp[i - 1][3], dp[i - 1][4]) + dif(num[i] ^ 1);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][7]) + dif(num[i] ^ 2);
            dp[i][3] = min(dp[i - 1][6], dp[i - 1][1]) + dif(num[i] ^ 3);
            dp[i][4] = min(dp[i - 1][6], dp[i - 1][1]) + dif(num[i] ^ 4);
            dp[i][5] = min(dp[i - 1][0], dp[i - 1][7]) + dif(num[i] ^ 5);
            dp[i][6] = min(dp[i - 1][3], dp[i - 1][4]) + dif(num[i] ^ 6);
            dp[i][7] = min(dp[i - 1][2], dp[i - 1][5]) + dif(num[i] ^ 7);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 8; i++) ans = min(ans, dp[m - 1][i]);
        cout << ans << endl;
    }
}