/*
 * @Date         : 2020-04-18 16:36:38
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string dp[maxn][3], s;
int t, k;
int main()
{
    cin >> t;
    while (t--) {
        cin >> s >> k;
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for (int i = 0; i <= k + 2; i++)
            dp[i][0].clear(), dp[i][1].clear(), dp[i][2].clear();
        for (int i = 0, j = 1; i < s.length(); i++) {
            int tmp = s[i] - '0' % 3;
            string a = "";
            a += s[i];
            if (tmp == 0) {
                if (dp[j - 1][0] + a > dp[j][0])
                    dp[j][0] = dp[j - 1][0] + a;
                if (dp[j - 1][1] + a)
            }
            else if (tmp == 1) {
                dp[j][1] = dp[j - 1][0] + s[i];
                if (!dp[j - 1][1].empty())
                    dp[j][2] = dp[j - 1][1] + s[i];
                if (!dp[j - 1][2].empty())
                    dp[j][3] = dp[j - 1][2] + s[i];
            }
            else if (tmp == 2) {
                dp[j][2] = dp[j - 1][0] + s[i];
                if (!dp[j - 1][1].empty())
                    dp[j][0] = dp[j - 1][1] + s[i];
                if (!dp[j - 1][2].empty())
                    dp[j][1] = dp[j - 1][2] + s[i];
            }
            cout << dp[j][0] << endl;
            cout << dp[j][1] << endl;
            cout << dp[j][2] << endl;
        }
    }
}