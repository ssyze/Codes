/*
 * @Date         : 2020-02-08 14:54:15
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 5;
int t, n, m, p, x, y, val;
int a[maxn][maxn];
signed main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m >> p;
        memset(a, 0, sizeof(a));
        int flag = 0, flag1 = 0;
        for (int i = 0; i < p; i++) {
            cin >> x >> y >> val;
            if ((m * x + y) < 0 || (m * x + y) >= (n * m)) {
                flag = 1;
            }
            else if (x < 0 || x >= n || y < 0 || y >= m) {
                flag1 = 1;
                int sum = m * x + y;
                int nx = sum / m, ny = sum % m;
                a[nx][ny] = val;
            }
            else
                a[x][y] = val;
        }
        if (flag)
            puts("Runtime error");
        else if (flag1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j != m - 1)
                        cout << a[i][j] << ' ';
                    else
                        cout << a[i][j] << endl;
                }
            }
            puts("Undefined Behaviour");
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j != m - 1)
                        cout << a[i][j] << ' ';
                    else
                        cout << a[i][j] << endl;
                }
            }
            puts("Accepted");
        }
    }
}
