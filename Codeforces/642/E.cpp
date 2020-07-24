/*
 * @Date         : 2020-05-14 23:44:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int t, n, k, num[maxn], sum[maxn], dp[maxn][2];
string s;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i <= n; i++)
            dp[i][0] = dp[i][1] = 0;
        sum[0] = s[0] - '0';
        for (int i = 1; i < s.length(); i++)
            sum[i] = sum[i - 1] + s[i] - '0';
        if (s[0] == '0')
            dp[0][1] = 1;
        else
            dp[0][0] = 1;
        for (int i = 1; i < s.length(); i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            if (i < k)
                dp[i][1] = sum[i - 1];
            else
                dp[i][1] = min(dp[i - k][1] + sum[i - 1] - sum[i - k], sum[i - 1]);
            if (s[i] == '1')
                dp[i][0]++;
            else
                dp[i][1]++;
            //cout << dp[i][0] << ' ' << dp[i][1] << endl;
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
}