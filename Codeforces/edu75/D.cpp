/*
 * @Date         : 2020-04-10 16:19:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n, a[maxn], dp[maxn][5];
char s[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    string t = " hard";
    for (int i = 1; i <= 4; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            if (s[i] != t[j]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + a[i]);
            }
        }
    }
    cout << dp[n][4] << endl;
}