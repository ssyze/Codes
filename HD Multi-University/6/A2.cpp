/*
 * @Date         : 2020-08-06 16:55:28
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll wa[maxn];
ll wws[maxn];
ll inv1[maxn];

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
ll ans, n, s[maxn];

int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i = 1; i < maxn; i++) inv1[i] = inv(i);
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            wws[i] = (wws[i - 1] + s[i]) % mod;
        }

        int r = n, l = 1;
        for (int i = 1; i <= n; i++) {
            if (i > (n + 1) / 2)
                wa[i] = wa[n - i + 1];
            else {
                wa[i] = (wa[i - 1] + (wws[r] - wws[l - 1] + mod) % mod) % mod;
                r--, l++;
            }
            ans = (ans + wa[i] * inv1[i] % mod) % mod;
        }
        ll res = inv(1ll * n * (n + 1) / 2);
        ans = ans * res % mod;
        cout << ans << endl;
    }
}
