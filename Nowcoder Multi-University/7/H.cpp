#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

ll n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (n == 1) {
        cout << k % mod << endl;
        return 0;
    }
    ll ans = n % mod, sqr = 1;
    if (k >= n) ans = ans + 1 + (k - n), ans %= mod;
    for (ll i = 2; i * i <= n && i <= k; sqr = i, ++i) ans = (ans + (n - 1) / i + n / i + 1) % mod;
    if (k * k > n) {
        for (ll i = 1; i <= sqr; ++i) {
            ll a = min((n - 1) / i, k), b = max((n - 1) / (i + 1), sqr);
            if (a <= b) continue;
            ans += (a - b) * (i + 1) % mod;
            ans %= mod;
        }
        for (ll i = 1; i <= sqr; ++i) {
            ll a = min(n / i, k), b = max(n / (i + 1), sqr);
            if (a <= b) continue;
            ans += (a - b) * i % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}