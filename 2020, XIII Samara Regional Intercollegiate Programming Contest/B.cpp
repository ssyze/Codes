/*
 * @Date         : 2020-05-22 13:37:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n, t, a[maxn];
bool check(int m)
{
    if (m == 0)
        return 1;
    for (int i = 0; i < n - m + 1; i++) {
        int l = a[i], r = a[i + m - 1], ti;
        if (l <= 0 && r <= 0)
            ti = abs(l);
        else if (l <= 0 && r >= 0)
            ti = min(abs(l) * 2 + r, r * 2 + abs(l));
        else
            ti = r;
        if (ti <= t)
            return 1;
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n, ans = l;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cout << l << ' ' << r << ' ' << mid << endl;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}