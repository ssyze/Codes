/*
 * @Date         : 2020-04-19 21:50:11
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 5;
const int mod = 1e9 + 7;
ll dp[maxn][maxn], n, m, v;
// dp[i][j] 敲了i次得到长度为j的字符串的方案数
string s;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a)
{
    return qpow(a, mod - 2);
}
int main()
{
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = (dp[i][0] + dp[i - 1][0] + dp[i - 1][1]) % mod;
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 26 % mod + dp[i - 1][j + 1]) % mod;
    }
    ll ans = 0;
    while (n--) {
        cin >> s >> v;
        ll len = s.length();
        for (int i = len; i <= m; i++) { //枚举打出来的长度
            //cout << ans << ' ' << dp[m][i] << endl;
            ans = (ans + v * (i - len + 1) * dp[m][i] % mod * inv(qpow(26, len)) % mod) % mod;
        }
    }
    cout << ans << endl;
}