/*
 * @Date         : 2020-08-26 15:53:17
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
map<int, int> vis;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = -1, mn = 1e9 + 7;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            mx = max(mx, x), mn = min(mn, x);
        }
        if (mx == mn)
            cout << n << '\n';
        else
            cout << 1 << '\n';
    }
}