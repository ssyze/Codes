/*
 * @Descripttion: maximum subsequence sum dp
 * @Author: ssyze
 * @Date: 2019-12-17 13:26:57
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn];
int a[maxn];
int b[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            b[i] = 1;
        else
            b[i] = -1;
    }
    dp[0] = b[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + b[i], b[i]);
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(dp[i], ans);
    }
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}