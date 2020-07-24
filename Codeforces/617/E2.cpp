/*
 * @Date         : 2020-04-04 17:21:39
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
string s;
int main()
{
    cin >> n >> s;
    vector<int> dp(n, 1);
    vector<int> c(26);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 25; j > s[i] - 'a'; j--) {
            dp[i] = max(dp[i], c[j] + 1);
        }
        c[s[i] - 'a'] = max(c[s[i] - 'a'], dp[i]);
        ans = max(ans, c[s[i] - 'a']);
    }
    cout << ans << endl;
    for (auto& x : dp)
        cout << x << ' ';
    cout << endl;
}