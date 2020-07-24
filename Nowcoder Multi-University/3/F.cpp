/*
 * @Date         : 2020-07-18 16:31:24
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
int t, a, b;

int prime[maxn] = {0}, vis[maxn] = {0}, tot;

void euler()
{
    vis[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            vis[i]++;
            for (int j = i + i; j < maxn; j += i) vis[j]++;
        }
    }
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
void solve(ll a, ll b, ll c, ll &x, ll &y)
{
    ll g = exgcd(a, b, x, y);
    // cout << a << ' ' << b << ' ' << x << ' ' << y << endl;
    x *= c;
    y *= c;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    euler();
    cin >> t;
    while (t--) {
        cin >> a >> b;
        // cout << vis[b] << endl;
        ll g = __gcd(a, b);
        if (g != 1) {
            cout << a / g + 1 << ' ' << b / g << ' ' << 1 << ' ' << b / g
                 << '\n';
            continue;
        }
        if (b == 1 || vis[b] == 1) {
            cout << "-1 -1 -1 -1" << '\n';
            continue;
        }
        ll c = 0, e = 0, d, f;
        int bb = b;
        for (int i = 0; i < tot; i++) {
            if (bb % prime[i] == 0) {
                d = prime[i];
                while (bb % prime[i] == 0) bb /= prime[i];
                break;
            }
        }
        f = bb;
        d = b / bb;
        // cout << d << ' ' << f << endl;
        solve(f, d, a, c, e);
        if (c < 0 && e > 0)
            cout << e << ' ' << f << ' ' << -c << ' ' << d << '\n';
        else
            cout << c << ' ' << d << ' ' << -e << ' ' << f << '\n';
    }
}