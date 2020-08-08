/*
 * @Date         : 2020-07-29 23:11:58
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, k, z, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = a[1], mx = -1, sum1, ans = -1, pos = -1;
        for (int i = 2; i <= k + 1; i++) {
            if (a[i - 1] + a[i] > mx) {
                mx = a[i - 1] + a[i];
                pos = i;
            }
            sum += a[i];
            sum1 = sum;
            int tmp = k - i + 1, q = z;
            for (; tmp > 1 && q > 0; q--, tmp -= 2) {
                sum1 += a[pos - 1] + a[pos];
            }
            if (q && tmp) sum1 += a[i - 1];
            ans = max(ans, sum1);
        }
        ans = max(ans, sum);
        cout << ans << endl;
    }
}
