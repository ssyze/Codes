/*
 * @Date         : 2020-04-09 16:57:50
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, a[maxn], sum[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> m;
        m[0] = 0;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (a[i] == 2)
                a[i] = -1;
            sum[i] = sum[i - 1] + a[i];
            if (i <= n)
                m[sum[i]] = i;
        }
        int ans = 2 * n;
        for (int i = n; i <= 2 * n; i++) {
            auto x = m.find(sum[i] - sum[2 * n]);
            if (x != m.end())
                ans = min(ans, i - x->second);
        }
        cout << ans << endl;
    }
}