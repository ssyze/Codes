/*
 * @Date         : 2020-07-21 14:04:18
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
const int maxn = 1e5 + 5;
ll fac[maxn], a[maxn], b[maxn];
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
    fac[0] = a[0] = b[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = i * fac[i - 1] % mod;
    for (int i = 1; i < maxn; i++) a[i] = a[i - 1] * 691504013 % mod;
    for (int i = 1; i < maxn; i++) b[i] = b[i - 1] * 308495997 % mod;
}
void solve()
{
    int n, c, k;
    cin >> n >> c >> k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}