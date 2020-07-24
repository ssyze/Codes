/*
 * @Date         : 2020-07-19 14:02:35
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, m, x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            int tmp = (m + x - 1) / x;
            ans = min(ans, tmp * y);
        }
        cout << ans << endl;
    }
}