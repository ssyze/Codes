/*
 * @Date         : 2020-08-11 00:06:31
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int t, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
        int sum = 0;
        for (int k = 2; k <= 2 * n; k++) {
            vector<int> vis(n, 0);
            int ans = 0;
            for (int i = 0; i < n - 1; i++) {
                if (vis[i]) continue;
                for (int j = i + 1; j < n; j++) {
                    if (vis[j]) continue;
                    if (a[i] + a[j] == k) {
                        ans++, vis[i] = vis[j] = 1;
                        break;
                    }
                }
            }
            sum = max(ans, sum);
        }
        cout << sum << '\n';
    }
}