/*
 * @Date         : 2020-07-16 16:30:27
 * @Author       : ssyze
 * @Description  : A^k = B, A^(k * t) = B^t, t为k的逆元, 则 A = B^t
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k, a[maxn], vis[maxn], ans[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector<int> c;
        int pos = i;
        while (!vis[pos]) {
            c.push_back(pos);
            vis[pos] = 1;
            pos = a[pos];
        }
        int sz = c.size(), t = 0;
        while (t < sz) {
            if ((1LL * t * k) % sz == 1) break;
            t++;
        }
        for (int j = 0; j < sz; j++) {
            ans[c[j]] = c[(j + t) % sz];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}