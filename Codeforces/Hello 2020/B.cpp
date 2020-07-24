/*
 * @Date         : 2020-01-04 20:21:10
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, ans, f = 1;
int min1[maxn], max1[maxn];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, x, flag = 0;
        cin >> l;
        cin >> x;
        int mx = x, mn = x, pre = x;
        for (int j = 1; j < l; j++) {
            cin >> x;
            mx = max(mx, x);
            mn = min(mn, x);
            if (x > pre && !flag) {
                flag = 1;
                ans += 2 * n - f;
                //cout << ans << endl;
            }
            pre = min(pre, x);
        }
        if (flag) {
            min1[i] = 0x3f3f3f3f;
            max1[i] = -0x3f3f3f3f;
            f += 2;
            continue;
        }
        min1[i] = mn;
        max1[i] = mx;
    }
    sort(max1, max1 + n);
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(max1, max1 + n, min1[i]) - max1;
        ans += (n - pos);
        //cout << i << ' ' << pos << ' ' << ans << endl;
    }
    cout << ans << endl;
}