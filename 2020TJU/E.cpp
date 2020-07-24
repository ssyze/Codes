/*
 * @Date         : 2020-05-10 14:34:00
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
ll inv(ll x)
{
    return qpow(x, mod - 2);
}
int main()
{
    ll n;
    cin >> n;
    ll t = 1;
    for (ll i = 0; i < n; i++)
        t = (t * (2LL * n - i) % mod * inv(i + 1) % mod) % mod;
    t = t * inv(n + 1) % mod;
    ll f = 1;
    for (ll i = 1; i < 2 * n; i += 2)
        f = f * i % mod;
    ll ans = t * inv(f) % mod;
    printf("%lld\n", ans);
}