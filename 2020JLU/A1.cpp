/*
 * @Date         : 2020-06-13 13:34:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
ll dp[100005][20][2];
ll fac[100005];
int num[100005];
string n;
int t;
ll dfs(int pos, int now, int lim)
{
    if (pos == 1)
        return now == 7;
    if (dp[pos][now][lim] != -1)
        return dp[pos][now][lim];
    ll ans = 0;
    if (now == 7 && !lim)
        ans = (ans + fac[pos + 1]) % mod;
    if (now == 7 && lim) {
        ll sum = 0;
        for (int i = n.length() - 1; i >= n.length() - pos + 1; i--) {
            sum = sum * 10 % mod;
            sum = (sum + n[i] - '0') % mod;
        }
        ans = (ans + sum) % mod;
    }
    int limt = lim ? num[pos - 1] : 9;
    for (int i = 0; i < limt; i++)
        ans = (ans + dfs(pos - 1, i, lim && i == num[pos - 1])) % mod;
    return dp[pos][now][lim] = ans;
}
ll getA(string s)
{
    ll ans = 0;
    memset(num, 0, sizeof(num));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < s.length(); i++)
        num[s.length() - i] = s[i] - '0';
    for (int i = 0; i <= num[s.length()]; i++)
        ans = (ans + dfs(s.length(), i, i == num[s.length()])) % mod;
    return ans;
}
int main()
{
    fac[0] = 1, fac[1] = 1;
    for (int i = 2; i <= 100005; i++)
        fac[i] = fac[i - 1] * 10 % mod;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << getA(n) << '\n';
    }
}