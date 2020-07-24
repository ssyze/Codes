/*
 * @Date         : 2020-03-28 20:03:20
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f;
int map1[55][55];
int n, m;

int main()
{
    while (scanf("%d%d", &m, &n) != EOF) {
        memset(map1, 0, sizeof(map1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map1[i][j];
                if (map1[i][j] == -1)
                    map1[i][j] = -inf;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (map1[i - 1][j] < 0 && map1[i][j - 1] < 0)
                    map1[i][j] = -inf;
                else
                    map1[i][j] += max(map1[i - 1][j], map1[i][j - 1]);
            }
        }

        int ans = map1[m][n];
        if (ans < 0)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}