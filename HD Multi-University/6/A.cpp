/*
 * @Date         : 2020-08-06 13:59:57
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
ll t, n, s[maxn], sum[maxn], sum1[maxn];
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
    sum[1] = qpow(3, mod - 2);
    sum1[1] = 1;
    for (int i = 2; i < maxn; i++) {
        sum[i] = (i * qpow(i + 2, mod - 2) + sum[i - 1]) % mod;
        sum1[i] = (qpow(i, mod - 2) + sum1[i - 1]) % mod;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (1629735LL + 2509851LL * qpow(2, mod - 2)) % mod << endl;
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; i++) cin >> s[i];
        for (ll i = 1; i <= n; i++) {
            ll tmp1 = 0, tmp2 = 0, tmp3 = 0;
            tmp1 = sum1[n - i + 1] * s[i] % mod;
            if (i >= 2) tmp2 = (sum1[i] - 1) * s[i] % mod;
            if (i != 1 && i != n) {
                ll l = i - 1, r = n - i;
                ll mn = min(l, r), mx = max(l, r);
                tmp3 = sum[mn];
                ll sm = (sum1[mx + 2] - sum1[mn + 2] + mod) % mod;
                tmp3 = (tmp3 + (mn * sm) % mod) % mod;
                while (mn) {
                    tmp3 = (tmp3 + (mn - 1) * qpow(mx + 3, mod - 2) % mod) % mod;
                    mn--, mx++;
                }
                tmp3 = tmp3 * s[i] % mod;
            }
            cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << endl;
            ans = (ans + tmp1 + tmp2 + tmp3) % mod;
        }
        cout << ans << endl;
        ans = ans * 2 % mod * qpow(n, mod - 2) % mod * qpow(n + 1, mod - 2) % mod;
        cout << ans << endl;
    }
}