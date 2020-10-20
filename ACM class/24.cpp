#include <bits/stdc++.h>
using namespace std;
int n, a[25], dp[25][25], f[25][25], Case;
void print(int i, int j)
{
    if (i == j) {
        cout << "A" << i;
        return;
    }
    if (i != 1 || j != n) cout << "(";
    print(i, f[i][j]);
    print(f[i][j] + 1, j);
    if (i != 1 || j != n) cout << ")";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        memset(dp, 0x3f, sizeof(dp));
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
            dp[i][i] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int st = 1; st <= n - len + 1; st++) {
                int ed = st + len - 1;
                dp[st][ed] = dp[st + 1][ed] + a[st - 1] * a[st] * a[ed];
                f[st][ed] = st;
                for (int k = st + 1; k < ed; k++) {
                    int tmp = dp[st][k] + dp[k + 1][ed] + a[st - 1] * a[ed] * a[k];
                    if (dp[st][ed] > tmp) {
                        dp[st][ed] = tmp;
                        f[st][ed] = k;
                    }
                }
            }
        }
        cout << "Case " << ++Case << endl;
        cout << dp[1][n] << ' ';
        print(1, n);
        cout << endl;
    }
}