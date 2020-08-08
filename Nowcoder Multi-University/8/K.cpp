/*
 * @Date         : 2020-08-03 12:32:42
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
int t, n, Case;
ll a[maxn], b[maxn], mn[maxn];
ll p[maxn], mx[maxn][100];
ll askmx(int l, int r)
{
    int k = log2(r - l + 1);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
void init()
{
    for (int i = 0; i <= n; ++i) mx[i][0] = p[i];
    for (int j = 1; (1 << j) <= n + 1; ++j)
        for (int i = 0; i + (1 << j) <= n + 1; ++i)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
}
int main()
{
    // freopen("I.in", "r", stdin);
    // freopen("K.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(mn, 0x3f, sizeof(mn));
        mn[n + 1] = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        for (int i = 1; i <= n; i++) scanf("%lld", b + i);
        ll mx = -0x3f3f3f3f3f3f3f3f, ps, ans = b[1], sum1 = 0, ssum = 0;
        ull sum = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i];
            mn[i] = min(b[i], mn[i - 1]);
        }
        init();
        for (int i = n + 1;;) {
            int j, k;
            for (j = i - 1; j >= 1; j--) {
                if (mn[j] > mn[i]) break;
            }
            if (j <= 1) break;
            int l = 1, r = j;
            mx = askmx(l, r);
            while (l <= r) {
                int mid = (l + r) / 2;
                if (askmx(1, mid) >= mx)
                    r = mid - 1, ps = mid;
                else
                    l = mid + 1;
            }
            if (ps == 1) break;
            if (p[ps] > 0)
                sum += 1ULL * p[ps] * (mn[ps] - sum1);
            else {
                ll tmp = p[ps] * (mn[ps] - sum1);
                if (sum > -tmp)
                    sum = sum - (-tmp);
                else
                    ssum += tmp;
            }
            i = ps;
            sum1 = mn[ps];
        }
        cout << "Case #" << ++Case << ": " << ans << ' ';
        ll tmp = 1LL * (mn[1] - sum1) * p[1] + ssum;
        if (tmp < 0 && -tmp > sum)
            cout << tmp + ll(sum) << '\n';
        else if (tmp < 0 && sum >= -tmp)
            cout << sum - (-tmp) << '\n';
        else
            cout << sum + tmp << '\n';
    }
}