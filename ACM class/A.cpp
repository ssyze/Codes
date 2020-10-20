#include <bits/stdc++.h>
using namespace std;
int t, n, m, Case;
char a[55], b[55];
int dp[55][55];
set<string> lcs;
void prt(int n, int m, string l)
{
    while (n && m) {
        if (a[n] == b[m])
            l.push_back(a[n]), n--, m--;
        else {
            if (dp[n - 1][m] < dp[n][m - 1])
                m--;
            else if (dp[n - 1][m] > dp[n][m - 1])
                n--;
            else {
                prt(n - 1, m, l);
                prt(n, m - 1, l);
                return;
            }
        }
    }
    reverse(l.begin(), l.end());
    lcs.insert(l);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << "Case " << ++Case << endl;
        cout << dp[n][m] << endl;
        string l;
        l.clear();
        lcs.clear();
        prt(n, m, l);
        cout << lcs.size() << endl;
        for (auto& x : lcs) cout << x << endl;
    }
}