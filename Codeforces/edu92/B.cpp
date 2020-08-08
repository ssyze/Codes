/*
 * @Date         : 2020-07-29 22:43:22
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, k, z;
int a[maxn], dp[maxn][6];

int dfs(int pos, int now, int pre, int z)
{
    if (now == 0) return a[pos];
    if (z == 0 && dp[pos][0] != -1) return dp[pos][0];
    int ans = 0;
    if (pre == 1)
        ans += dfs(pos + 1, now - 1, 0, z) + a[pos];
    else {
        if (z == 0) {
            ans += dfs(pos + 1, now - 1, 0, z) + a[pos];
            dp[pos][0] = ans;
        }
        else {
            int ans1 = ans;
            ans1 += dfs(pos - 1, now - 1, 1, z - 1) + a[pos];
            ans += dfs(pos + 1, now - 1, 0, z) + a[pos];
            dp[pos][z - 1] = ans1;
            dp[pos][z] = ans;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) cin >> a[i];
        int pos = -1, mx = -1, sum1 = a[1], sum2 = a[1];
        /* for (int i = 2; i < k - z; i++) {
            if (a[i] + a[i - 1] > mx) {
                mx = a[i] + a[i - 1];
                pos = i;
            }
        } */
        dfs(1, k, 0, z);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < z; j++) {
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx << endl;
    }
}