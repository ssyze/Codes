/*
 * @Date         : 2020-04-05 14:52:45
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
string s[maxn], r[maxn];
ll n, c[maxn], dp[maxn][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; i++) {
        if (s[i] >= s[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i] >= r[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (r[i] >= s[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (r[i] >= r[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    ll ans = min(dp[n - 1][1], dp[n - 1][0]);
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}