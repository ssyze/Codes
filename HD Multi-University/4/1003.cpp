/*
 * @Date         : 2020-07-31 14:34:00
 * @Author       : ssyze
 * @Description  :
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 100;
const int base = 40000;
const int lim = 1e5 + 10;
int t, n, m, w, v;
struct node {
    int w, v;
} a[2005];
ll dp[maxn];
mt19937 rnd(time(0));
int main()
{
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    /* ios::sync_with_stdio(0);
    cin.tie(0); */
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &w, &v);
            a[i] = {w, v};
        }
        for (int i = n + 1; i <= n + m; i++) {
            scanf("%d%d", &w, &v);
            a[i] = {-w, v};
        }
        memset(dp, -0x3f, sizeof(dp));
        dp[base] = 0;
        shuffle(a + 1, a + n + m + 1, rnd);
        ll ans = 0;
        for (int i = 1; i <= n + m; i++) {
            if (a[i].w > 0)
                for (int j = 2 * base; j >= a[i].w; j--)
                    dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
            else
                for (int j = 0; j <= 2 * base; j++) dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
            ans = max(ans, dp[base]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}