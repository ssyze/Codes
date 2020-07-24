/*
 * @Date         : 2020-07-17 00:00:33
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, x, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum++;
            if (sum * a[i] >= x) ans++, sum = 0;
        }
        cout << ans << endl;
    }
}