/*
 * @Date         : 2020-07-12 12:48:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 5;
const int mod = 998244353;
ll f[maxn], n;
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
ll inv(int a) { return qpow(a, mod - 2) % mod; }
int C(int n, int m)
{
    // cout << inv(f[m]) << endl;
    ll tmp = f[n] * inv(f[m]) % mod * inv(f[n - m]) % mod;
    return tmp % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < maxn; i++) f[i] = f[i - 1] * i % mod;
    while (cin >> n) {
        ll ans = (f[n] * f[n] % mod * inv(f[2 * n + 1]) % mod + mod) % mod;
        cout << ans << endl;
    }
}