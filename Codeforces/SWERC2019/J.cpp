#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

ll a[maxn], f[maxn], n;

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

ll C(ll n, ll m) { return f[n] * inv(f[n - m]) % mod * inv(f[m]) % mod; }

ll Ca(ll n) { return C(2 * n, n) * inv(n + 1) % mod; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * i % mod;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<ll> s;
    ll ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty() || a[i] >= s.top())
            s.push(a[i]);
        else if (a[i] < s.top()) {
            while (!s.empty() && a[i] < s.top()) {
                int top = s.top(), cnt = 0;
                while (!s.empty() && top == s.top()) s.pop(), cnt++;
                ans = (ans * Ca(cnt)) % mod;
                // cout << top << ' ' << ans << '\n';
            }
            s.push(a[i]);
        }
    }
    int top, cnt = 0;
    while (!s.empty()) {
        top = s.top(), cnt = 0;
        while (!s.empty() && top == s.top()) s.pop(), cnt++;
        ans = (ans * Ca(cnt)) % mod;
    }
    cout << ans << '\n';
}