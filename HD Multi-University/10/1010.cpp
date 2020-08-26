/*
 * @Date         : 2020-08-21 20:54:35
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int g[5][5], t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int ans = 0, x = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> g[i][j];
                x ^= g[i][j] - 1;
            }
        }
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                int flag = 1;
                for (int p = 1; p <= 3; p++) {
                    if (p == i) continue;
                    for (int q = 1; q <= 3; ++q) {
                        if (q == j) continue;
                        int tmp = (g[i][j] - 1) ^ (g[p][q] - 1) ^ (g[6 - i - p][6 - j - q] - 1)
                            ^ g[6 - i - p][6 - j - q];
                        if (tmp == x) {
                            // cout << i << ' ' << j << ' ' << p << ' ' << q << endl;
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag) ans++;
            }
        }
        cout << ans << endl;
    }
}