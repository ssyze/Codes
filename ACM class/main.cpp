/*
 * @Date         : 2020-03-06 16:52:27
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, V;
    int c[10], v[10], dp[10];
    memset(dp, 0, sizeof(dp));
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = c[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    cout << dp[V] << endl;
}