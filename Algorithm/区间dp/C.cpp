#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s) {
        if (s == "end") break;
        memset(dp, 0, sizeof(dp));
        for (int len = 2; len <= s.length(); len++) {
            for (int st = 0; st < s.length() - len + 1; st++) {
                int ed = st + len - 1;
                if ((s[st] == '(' && s[ed] == ')') || (s[st] == '[' && s[ed] == ']'))
                    dp[st][ed] = dp[st + 1][ed - 1] + 2;
                for (int k = st + 1; k <= ed; k++) {
                    dp[st][ed] = max(dp[st][ed], dp[st][k - 1] + dp[k][ed]);
                }
            }
        }
        cout << dp[0][s.length() - 1] << endl;
    }
}