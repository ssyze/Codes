/*
 * @Date         : 2020-04-17 21:34:15
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll t, n, a[maxn], x;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> x;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll ans = n, res = n * x;
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (sum >= res)
                break;
            else {
                ans--;
                sum -= a[i];
                res -= x;
            }
        }
        cout << ans << endl;
    }
}