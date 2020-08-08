#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;

int t, n, w[maxn], f[maxn];
ll cnt[maxn][3], num[3], fac[maxn], ans, inv[maxn];

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 2] = qpow(fac[maxn - 2], mod - 2);
    for (int i = maxn - 3; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m) { return m > n ? 0ll : fac[n] * inv[m] % mod * inv[n - m] % mod; }

int fin(int x) { return f[x] == x ? x : f[x] = fin(f[x]); }

void uni(int a, int b)
{
    int fa = fin(a), fb = fin(b);
    if (fa == fb) return;

    ans = (ans - cnt[fa][1] * cnt[fb][2] % mod * (num[2] - cnt[fa][2] - cnt[fb][2]) % mod + mod) %
          mod;
    ans = (ans - cnt[fa][2] * cnt[fb][1] % mod * (num[2] - cnt[fa][2] - cnt[fb][2]) % mod + mod) %
          mod;
    ans = (ans - cnt[fa][2] * cnt[fb][2] % mod * (num[1] - cnt[fa][1] - cnt[fb][1]) % mod + mod) %
          mod;
    ans = (ans - cnt[fa][2] * cnt[fb][2] % mod * (num[2] - cnt[fa][2] - cnt[fb][2]) % mod + mod) %
          mod;
    cnt[fa][2] += cnt[fb][2];
    cnt[fa][1] += cnt[fb][1];
    f[fb] = fa;
}

int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
            num[w[i]]++;
            cnt[i][w[i]] = 1;
            f[i] = i;
        }
        ans = (C(num[2], 2) * C(num[1], 1) % mod + C(num[2], 3)) % mod;
        cout << ans << '\n';
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            uni(u, v);
            cout << ans << '\n';
        }
        num[1] = num[2] = 0;
        for (int i = 1; i <= n; ++i) cnt[i][1] = cnt[i][2] = 0;
    }
}