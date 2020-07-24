/*
 * @Date         : 2020-04-09 17:51:44
 * @Author       : ssyze
 * @Description  : 
 */
/*
 * @Date         : 2020-04-09 17:43:36
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[maxn];
int n, q;
pair<int, int> p[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (p[i].first == p[i - 1].first) {
                if (p[i].second < p[i - 1].second) {
                }
            }
        }
    }
}