/*
 * @Date         : 2020-08-09 14:19:07
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2005;
int n, w1, w2, k, x[maxn], y[maxn];
pair<int, int> p[maxn];
int main()
{
    scanf("%d%d%d%d", &n, &k, &w1, &w2);
    for (int i = 0; i < k; i++) scanf("%d%d", &p[i].first, &p[i].second);
    if (w2 >= 2 * w1) {
        printf("%lld\n", 1LL * n * 2 * w1);
        return 0;
    }
    sort(p, p + k);
    for (int i = 0; i < k; i++) x[i] = p[i].first, y[i] = p[i].second;
    int sum = 0, nx, ny;
    for (int i = 0; i < k;) {
        sum++;
        nx = x[i], ny = y[i];
        int ps = upper_bound(x + i + 1, x + k, nx) - x;
        int ps1 = upper_bound(y + ps, y + k, ny) - y;
        // cout << ps1 << endl;
        i = ps1;
    }
    ll ans = 1LL * sum * w2 + 1LL * (2 * n - 2 * sum) * w1;
    printf("%lld\n", ans);
}