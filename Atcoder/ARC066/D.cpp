/*
 * @Date         : 2020-07-28 23:41:58
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
map<pair<ll, ll>, int> dp;
ll n;

ll dfs(ll u, ll v)
{
    cout << u << ' ' << v << ' ' << dp[{u, v}] << endl;
    if (v < 0) return 0;
    if (v == 0) return 1;
    if (dp[{u, v}]) return dp[{u, v}];
    ll ans = 0;
    ans = (ans + dfs(u >> 1, v >> 1)) % mod;
    ans = (ans + dfs((u - 1) >> 1, (v - 1) >> 1)) % mod;
    if (v >= 2) ans = (ans + dfs(u >> 1, (v - 2) >> 1)) % mod;
    cout << u << ' ' << v << ' ' << dp[{u, v}] << ' ' << ans << endl;
    return dp[{u, v}] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << dfs(n, n) << '\n';
    for (auto &x : dp) {
        cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
    }
}