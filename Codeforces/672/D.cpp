#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
const int mod = 998244353;
ll n, k, ans, hl, hr;
vector<ll> t;
vector<ll> l, r;
ll fac[maxn];
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
ll inv(ll n) { return qpow(n, mod - 2); }
ll C(ll n, ll m) { return m > n ? 0 : fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod; }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    // cout << C(0, 1) << endl;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int _l, _r;
        cin >> _l >> _r;
        t.push_back(_l), t.push_back(_r + 1);
        l.push_back(_l), r.push_back(_r + 1);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    // for (auto& x : v) cout << x.first << ' ' << x.second << '\n';
    for (ll i = 0, cur = 0, tmp = 0; i < t.size(); i++) {
        while (hr < r.size() && r[hr] == t[i]) cur--, hr++;
        tmp = cur;
        while (hl < l.size() && l[hl] == t[i]) cur++, hl++;
        ans = (ans + (C(cur, k) - C(tmp, k) + mod) % mod) % mod;
        // cout << t[i] << ' ' << cur << ' ' << tmp << endl;
    }
    cout << ans << endl;
}
