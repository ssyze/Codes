/*
 * @Date         : 2020-04-21 14:52:22
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll t, n, a[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        ll mx = 0, ans = 0, mxx = -0x3f3f3f3f, c = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mxx = max(mxx, mx - a[i]);
            mx = max(mx, a[i]);
        }
        while (mxx > 0) {
            mxx -= c;
            c *= 2;
            ans++;
        }
        cout << ans << endl;
    }
}