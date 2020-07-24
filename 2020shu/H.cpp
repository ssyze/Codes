/*
 * @Date         : 2020-04-18 13:21:58
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, k;
string s;
string dp[maxn][3];
int v[3][10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s >> k;
        for (int i = 0; i <= k + 5; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j].clear();
            }
        }
        memset(v, 0, sizeof(v));
        for (int i = 0; i < s.length(); i++) {
            v[0][s[i] - '0']++;
            v[1][s[i] - '0']++;
            v[2][s[i] - '0']++;
        }
        for (int i = 1; i <= k; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            for (int j = 9; j >= 0; j--) {
                int mod = j % 3;
                bool vis[3] = { 0 };
                for (int q = 0; q < 3; q++) {
                    if (v[q][j] && !vis[(q + mod) % 3]) {
                        //cout << 1 << endl;
                        //cout << (q + mod) % 3 << endl;
                        dp[i][(q + mod) % 3] += char(j + '0');
                        cout << dp[i][(q + mod) % 3] << endl;
                        v[q][j]--;
                        vis[(q + mod) % 3] = 1;
                    }
                }
                if (vis[0] && vis[1] && vis[2])
                    break;
            }
        }
        cout << dp[k][0] << endl;
    }
}