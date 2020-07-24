/*
 * @Date         : 2020-07-19 15:08:34
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int t, a, b;
int main()
{
    for (int i = 1; i <= 1000; i++) dp[1][i] = dp[i][1] = i;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2; j <= 1000; j++) {
            if (__gcd(i, j) == 1)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cin >> t;
    while (t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}