/*
 * @Date         : 2020-02-04 14:31:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, m, ans;
int main()
{
    cin >> n >> m;
    ll ans = 0;
    ans += m * (m - 1) % mod * (n - 2) % mod * 2;
    ans %= mod;
    ans += m * (m - 2) % mod * (n - 1) % mod * 2;
    ans %= mod;
    ans += n * (n - 2) % mod * (m - 1) % mod * 2;
    ans %= mod;
    ans += n * (n - 1) % mod * (m - 2) % mod * 2;
    ans %= mod;
    ans -= (n - 2) * (m - 1) % mod * 2 % mod * 2 % mod;
    ans += mod;
    ans %= mod;
    ans -= (m - 2) * (n - 1) % mod * 2 % mod * 2 % mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
}