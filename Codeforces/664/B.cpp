/*
 * @Date         : 2020-08-13 23:39:19
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> sx >> sy;
    int i = sx, j = sy;
    for (int i = sx; i <= n; i++) cout << i << ' ' << j << '\n';
    for (int i = sx - 1; i >= 1; i--) cout << i << ' ' << j << '\n';
    for (int j = 0; j < m - 1; j++) {
        if (j & 1)
            for (int i = n; i >= 1; i--) cout << i << ' ' << (j + sy) % m + 1 << '\n';
        else
            for (int i = 1; i <= n; i++) cout << i << ' ' << (j + sy) % m + 1 << '\n';
    }
}