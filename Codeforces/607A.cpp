/*
 * @Date         : 2020-04-07 13:39:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
pair<int, int> p[maxn];
int dp[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n, [&](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    dp[p[0].first] = 1;
    for (int i = p[0].first + 1, j = 1; i <= p[n - 1].first; i++) {
        if (i == p[j].first) {
            if (i - p[j].second - 1 < 0)
                dp[i] = 1;
            else
                dp[i] = dp[i - p[j].second - 1] + 1;
            j++;
        }
        else
            dp[i] = dp[i - 1];
    }
    int ans = -1;
    for (auto& x : dp) {
        //cout << x << endl;
        ans = max(ans, x);
    }
    cout << n - ans << endl;
}