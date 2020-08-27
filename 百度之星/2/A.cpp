/*
 * @Date         : 2020-08-09 19:09:12
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll t, n, p, q;
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p >> q;
        ll ans = (100 * n % mod * qpow(p, mod - 2) % mod - 1);
        ans = ans * q % mod * qpow(100, mod - 2) % mod;
        // cout << ans << endl;
        cout << (n - ans + mod) % mod << '\n';
    }
}