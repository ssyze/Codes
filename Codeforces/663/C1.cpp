/*
 * @Date         : 2020-08-09 22:47:52
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
ll fac[maxn];
ll qpow(ll a, ll b)
{
    a %= mod, b %= mod - 1;
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a) { return qpow(a, mod - 2); }
ll C(ll n, ll m) { return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod; }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1, fac[1] = 1;
    for (int i = 2; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    int n;
    cin >> n;
    ll ans = fac[n];
    for (int i = 0; i <= n - 1; i++) ans -= C(n - 1, i), ans += mod, ans %= mod;
    cout << ans << endl;
}