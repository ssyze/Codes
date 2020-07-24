/*
 * @Date         : 2019-12-28 14:46:42
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
typedef long long ll;
int n, k;
int m[maxn][maxn];
ll dp[maxn][maxn];
bool check(int x)
{
    //dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1]
    for (int x2 = x; x2 <= n; x2++) {
        for (int y2 = x; y2 <= n; y2++) {
            int x1 = x2 - x + 1;
            int y1 = y2 - x + 1;
            ll ssum = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
            if (ssum >= k)
                return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m[i][j]);
        }
    /* if (sum < k) {
        cout << "I'm a Gold Chef!" << endl;
        return 0;
    } */
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + m[i][j];
    int l = 1, r = n + 1, ans = -1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
            ans = mid;
        }
        else
            l = mid + 1;
        //cout << l << ' ' << r << ' ' << mid << endl;
    }
    if (ans == -1)
        cout << "I'm a Gold Chef!" << endl;
    else
        cout << ans << endl;
}