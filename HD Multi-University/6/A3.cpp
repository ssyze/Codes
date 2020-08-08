/*
 * @Date         : 2020-08-06 17:30:55
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
ll t, n;
ll s[maxn], sum[maxn], sum1[maxn], lsum[maxn], inv[maxn];
ll qpow(ll a, ll b)
{
    a %= mod;
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
    inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
}
void init1()
{
    for (int i = 0; i < n + 5; i++) sum[i] = sum1[i] = lsum[i] = 0;
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        init1();
        ll res = 0;
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + s[i]) % mod;
        for (ll i = 1; i <= n; i++) sum1[i] = (sum1[i - 1] + s[i] * i % mod) % mod;
        for (ll i = n; i >= 1; i--) lsum[i] = (lsum[i + 1] + s[i] * (n - i + 1) % mod) % mod;
        for (ll i = 1; i <= n; i++) {
            ll l = i, r = n - i + 1, ans = 0;
            if (l <= r) {
                ans = (ans + sum1[l - 1]) % mod;
                ans = (ans + lsum[r + 1]) % mod;
                ans = (ans + ((sum[r] - sum[l - 1] + mod) * i % mod) % mod) % mod;
            }
            else {
                ans = (ans + sum1[r - 1]) % mod;
                ans = (ans + lsum[l + 1]) % mod;
                ans = (ans + r * ((sum[l] - sum[r - 1] + mod) % mod) % mod) % mod;
            }
            ans = ans * inv[i] % mod;
            res = (res + ans) % mod;
        }
        cout << res * qpow(1LL * n * (n + 1) / 2, mod - 2) % mod << endl;
    }
}