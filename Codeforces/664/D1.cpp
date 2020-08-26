/*
 * @Date         : 2020-08-14 20:48:47
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
ll n, d, m, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int ps = n + 10;
    for (int i = 0; i < n; i++)
        if (a[i] <= m) {
            ps = i;
            break;
        }
    ll ans = 0;
    for (int i = 0; i <= (n - 1) / (d + 1) + 1; i++) {
        if (1LL * (i - 1) * (d + 1) + 1 <= n) {
            ll sum = 0;
            for (int j = 0; j < min(i, ps); j++) sum += a[j];
            ll day = 1LL * (i - 1) * (d + 1) + 1;
            day = n - day;
            for (int j = 0; j < day; j++) sum += a[j + ps];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}