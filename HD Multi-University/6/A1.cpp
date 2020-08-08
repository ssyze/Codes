/*
 * @Date         : 2020-08-06 16:29:23
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll qpow(ll x, ll y)
{
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

ll inv(ll x) { return qpow(x, mod - 2); }

int t;
ll ans, n, s[maxn], w[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i < maxn; ++i) {
        w[i] = w[i - 1] + inv(i);
        w[i] %= mod;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; ++i) {
            cin >> s[i];
            ans += i * s[i] % mod;
            ans %= mod;
            if (n - 2 * i >= 1) {
                ans += i * (w[n - i] - w[i] + mod) % mod * s[i] % mod;
                ans += mod;
                ans %= mod;
                ans += (n + 1) * (w[n] - w[n - i] + mod) % mod * s[i] % mod;
                ans %= mod;
                ans -= i * s[i] % mod;
                ans += mod;
                ans %= mod;
            }
            else {
                ans += (n + 1) * (w[n] - w[i] + mod) % mod * s[i] % mod;
                ans %= mod;
                ans -= (n - i) * s[i] % mod;
                ans += mod;
                ans %= mod;
            }
            cout << ans << endl;
        }
        cout << ans * 2 % mod * inv(n) % mod * inv(n + 1) % mod << endl;
    }
}
