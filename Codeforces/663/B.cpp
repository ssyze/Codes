/*
 * @Date         : 2020-08-09 22:41:17
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char g[maxn][maxn];
int t, n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if (j == m && g[i][j] == 'R') ans++;
                if (i == n && g[i][j] == 'D') ans++;
            }
        }
        cout << ans << endl;
    }
}