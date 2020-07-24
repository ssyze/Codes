/*
 * @Date         : 2020-03-25 16:13:04
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, V, dp[maxn], c[maxn], v[maxn];
int main()
{
    while (cin >> n >> V) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            v[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = V; j >= c[i]; j--) {
                dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
            }
        }
        cout << dp[V] << endl;
    }
}