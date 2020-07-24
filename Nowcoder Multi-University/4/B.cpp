/*
 * @Date         : 2020-07-20 19:16:23
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int t, n, c, fac[maxn], vis[maxn];
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
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            for (int j = i; j < maxn; j += i) {
                vis[j] = 1;
                int tmp = j;
                while (tmp % i == 0) fac[j]++, tmp /= i;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n >> c;
        cout << qpow(c, fac[n]) << '\n';
    }
}
