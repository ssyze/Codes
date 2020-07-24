/*
 * @Date         : 2019-12-19 23:39:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
const int inf = 0x3f3f3f3f;
int dp[maxn], w[3];
int n, a, b, c;
int main()
{
    cin >> n >> w[0] >> w[1] >> w[2];
    memset(dp, -inf, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = w[i]; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}