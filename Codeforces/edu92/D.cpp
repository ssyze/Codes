/*
 * @Date         : 2020-07-31 22:45:56
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k, l[2], r[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> l[0] >> r[0] >> l[1] >> r[1];
        if (l[0] > l[1]) {
            swap(l[0], l[1]);
            swap(r[0], r[1]);
        }
        ll ans = 0, sum = 0;
        if (r[0] < l[1]) {
            ll tmp = l[1] - r[0];
            if (r[1] - l[0] >= k) {
                cout << l[1] - r[0] + k << endl;
                continue;
            }
            ll ans = 0x3f3f3f3f3f3f3f3f;
            for (int i = 1; i <= n; i++) {
                ll s = tmp * i;
                ll tmp1 = r[1] - l[0];
                int ti = k / tmp1;
                if (ti >= i)
                    ans = min(ans, s + i * tmp1 + (k - tmp1 * i) * 2);
                else
                    ans = min(ans, s + ti * tmp1 + (k - ti * tmp1));
            }
            cout << ans << endl;
        }
        else {
            ll ans = 0, sum = n * (min(r[0], r[1]) - max(l[0], l[1]));
            k -= sum;
            if (k <= 0) {
                cout << ans << endl;
                continue;
            }
            sum = max(r[0], r[1]) - min(r[0], r[1]) + max(l[0], l[1]) - min(l[0], l[1]);
            if (sum == 0) {
                cout << k * 2 << endl;
                continue;
            }
            int ti = k / sum;
            if (ti < n) {
                cout << ans + k << endl;
                continue;
            }
            else {
                ans += sum * n;
                k -= sum * n;
                cout << ans + 2 * k << endl;
                continue;
            }
        }
    }
}