#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5e6 + 100;
typedef long long ll;

ll h[maxn], p[maxn], hh[maxn], have[maxn];
int t, n, tot;
char s[maxn];

ll geth(int l, int r, ll* ha) { return (ha[r] - ha[l - 1] * p[r - l + 1] % mod + mod) % mod; }

bool Find(ll x)
{
    int idx = lower_bound(have, have + tot, x) - have;
    if (idx == tot)
        return 0;
    else
        return have[idx] == x;
}

bool check(int x)
{
    tot = 0;
    ll cur = 0;
    for (int i = 1; i <= x; ++i) cur *= p[1], cur += s[i], cur %= mod;
    have[tot++] = cur;
    for (int i = 1; i <= x; ++i) {
        cur -= s[i] * p[x - 1] % mod;
        cur += mod;
        cur %= mod;
        cur *= p[1];
        cur %= mod;
        cur += s[i];
        cur %= mod;
        have[tot++] = cur;
    }
    sort(have, have + tot);
    for (int i = x + 1; i <= n; i += x) {
        if (!Find(geth(i, i + x - 1, h))) return 0;
    }
    return 1;
}

int main()
{
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) p[i] = p[i - 1] * 13331 % mod;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * p[1] + s[i], h[i] %= mod;
        for (int i = 2; i <= n / 2 + 1; ++i) {
            if (n % i != 0) continue;
            if (check(i)) {
                puts("Yes");
                goto nxt;
            }
        }
        puts("No");
    nxt:;
    }
}
