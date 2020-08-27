/*
 * @Date         : 2020-08-10 13:01:31
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll llinf = 0x3f3f3f3f3f3f3f3f;

ll t, n, sum, ans;

int main()
{
    cin >> t;
    while (t--) {
        sum = 0;
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            ll x;
            cin >> x;
            sum += x;
            ans = max(ans, sum % i == 0 ? sum / i : sum / i + 1);
        }
        cout << ans << endl;
    }
}
