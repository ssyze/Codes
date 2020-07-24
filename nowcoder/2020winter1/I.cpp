/*
 * @Date         : 2020-02-05 13:20:23
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
typedef long long ll;
ll dp[maxn];
ll n, a, b, c;
string s;
int main()
{
    cin >> n >> a >> b >> c;
    cin >> s;
    for (int i = 3; i < n; i++) {
        if (s.substr(i - 3, 4) == "nico")
            dp[i] = max(dp[i], dp[i - 3] + a);
        if (i >= 5) {
            if (s.substr(i - 5, 6) == "niconi")
                dp[i] = max(dp[i], dp[i - 5] + b);
        }
        if (i >= 9) {
            if (s.substr(i - 9, 10) == "niconiconi")
                dp[i] = max(dp[i], dp[i - 9] + c);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
}