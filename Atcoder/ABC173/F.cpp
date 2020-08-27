/*
 * @Date         : 2020-08-10 17:39:48
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += i * (n - i + 1);
    for (ll i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        ans -= x * (n - y + 1);
    }
    cout << ans << endl;
}