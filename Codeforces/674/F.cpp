#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n, dp[4];
// dp[1]-'a',dp[2]-'ab',dp[3]-'abc'
// s[i]=='a',dp[1] = dp[1] + 1
// s[i]=='b',dp[2] = dp[1] + dp[2]
// s[i]=='c',dp[3] = dp[2] + dp[3]
// s[i]=='?', sizeof sequence * 3
string s;
int main()
{
    cin >> n >> s;
    dp[0] = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') dp[1] = (dp[1] + dp[0]) % mod;
        if (s[i] == 'b') dp[2] = (dp[1] + dp[2]) % mod;
        if (s[i] == 'c') dp[3] = (dp[2] + dp[3]) % mod;
        if (s[i] == '?') {
            dp[3] = (3 * dp[3] % mod + dp[2]) % mod;
            dp[2] = (3 * dp[2] % mod + dp[1]) % mod;
            dp[1] = (3 * dp[1] % mod + dp[0]) % mod;
            dp[0] = 3 * dp[0] % mod;
        }
    }
    cout << dp[1] << ' ' << dp[3] << endl;
}