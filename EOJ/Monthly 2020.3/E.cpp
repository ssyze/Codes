/*
 * @Date         : 2020-03-20 20:03:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int a[maxn];
int t, m, n;
ll f[maxn];
void init()
{
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        f[i] = f[i - 1] * i % mod;
    }
}
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
int main()
{
    init();
    //cout << qpow(2, 3) << endl;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        long long ans = a[m];
        for (int i = m + 1; i <= n; i++) {
            //cout << (f[i - 1] * qpow(f[i - m], mod - 2) % mod * qpow(f[m - 1], mod - 2) % mod) << endl;
            ans = (ans + ((((f[i - 1] * qpow(f[i - m], mod - 2)) % mod * qpow(f[m - 1], mod - 2)) % mod) * a[i]) % mod) % mod;
        }
        cout << ans << endl;
    }
}