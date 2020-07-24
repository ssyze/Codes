/*
 * @Date         : 2020-04-08 14:08:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int dp[maxn], vis[maxn];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << cnt[i] << endl;
        if (!cnt[i])
            continue;
        ans++;
        i += 2;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[a[i] - 1]) {
            dp[i] = dp[i - 1] + 1;
            vis[a[i] - 1] = 1;
        }
        else if (!vis[a[i]]) {
            dp[i] = dp[i - 1] + 1;
            vis[a[i]] = 1;
        }
        else if (!vis[a[i] + 1]) {
            dp[i] = dp[i - 1] + 1;
            vis[a[i] + 1] = 1;
        }
        else
            dp[i] = dp[i - 1];
        //cout << a[i] << ' ' << dp[i] << endl;
    }
    cout << ans << ' ' << dp[n - 1] << endl;
}