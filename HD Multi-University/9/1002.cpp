/*
 * @Date         : 2020-08-26 00:55:00
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
const int inv2 = 500000003;
int t, n, m, ans[10005];
int prime[maxn], tot, f[maxn], g[maxn], vis[maxn];
struct data {
    int div, range, pre, Case;
};
vector<data> c;
void init() // 筛f, g
{
    f[1] = g[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) prime[++tot] = i, f[i] = 2, g[i] = inv2;
        for (int j = 1; j <= tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j])
                f[i * prime[j]] = 2 * f[i] % mod, g[i * prime[j]] = 1LL * g[prime[j]] * g[i] % mod;
            else {
                f[i * prime[j]] = f[i];
                break;
            }
        }
    }
}
void get(int n, vector<int>& x) // 分解n
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            x.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) x.push_back(n);
}
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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    cin >> t;
    for (int T = 1; T <= t; T++) {
        cin >> n >> m;
        int tmp = n;
        vector<int> div;
        get(n, div);
        for (int i = 0; i < 1 << div.size(); i++) { // 枚举因数
            int di = 1;
            for (int j = 0; j < div.size(); j++)
                if (i & (1 << j)) di *= div[j];
            if (m < di || !g[di]) continue;
            c.push_back({ di, m / di, int(1LL * f[n] * g[di] % mod), T });
        }
    }
    sort(c.begin(), c.end(), [&](data a, data b) {
        if (a.div == b.div)
            return a.range < b.range;
        else
            return a.div < b.div;
    });
    int sum = 0, d = 0, i = 1;
    for (auto& x : c) {
        if (d != x.div) d = x.div, i = 1, sum = 0;
        for (; i <= x.range; i++) sum += f[i * d];
        sum %= mod;
        ans[x.Case] = (ans[x.Case] + 1LL * x.pre * sum % mod) % mod;
    }
    for (int i = 1; i <= t; i++) cout << ans[i] << '\n';
}