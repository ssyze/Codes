/*
 * @Date         : 2020-07-26 21:41:01
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
typedef long long ll;
int t, n, m, k;
ll fac[maxn], inv[maxn];
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 2] = qpow(fac[maxn - 2], mod - 2);
    for (int i = maxn - 3; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    init();
    while (t--) {
        cin >> n >> m >> k;
        ll ans = 0;
        for (int r = k; r <= min(n, m); r++) {
            ans = (ans + C(r - 1, k - 1) * C(n - r + k - 1, k - 1) % mod *
                             C(m - r + k - 1, k - 1) % mod) %
                  mod;
        }
        cout << ans << endl;
    }
}