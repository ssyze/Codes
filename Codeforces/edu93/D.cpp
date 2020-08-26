/*
 * @Date         : 2020-08-19 23:11:45
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[3], vis[3], x;
vector<int> a[3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c[0] >> c[1] >> c[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < c[i]; j++) {
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < c[i]; j++) cout << a[i][j] << ' ';
        cout << endl;
    }
    int cnt = 3;
    ll ans = 0;
    while (cnt >= 2) {
        ll r = 0, g = 0, b = 0;
        if (!vis[0]) r = a[0][a[0].size() - 1];
        if (!vis[1]) g = a[1][a[1].size() - 1];
        if (!vis[2]) b = a[2][a[2].size() - 1];
        ll rg = r * g, rb = r * b, gb = g * b;
        ll mx = max({ rg, rb, gb });
        cout << mx << endl;
        if (rg == mx)
            ans += rg, a[0].pop_back(), a[1].pop_back();
        else if (rb == mx)
            ans += rb, a[0].pop_back(), a[2].pop_back();
        else if (gb == mx)
            ans += gb, a[1].pop_back(), a[2].pop_back();
        if (a[0].empty() && !vis[0]) cnt--, vis[0] = 1;
        if (a[1].empty() && !vis[1]) cnt--, vis[1] = 1;
        if (a[2].empty() && !vis[2]) cnt--, vis[2] = 1;
    }
    cout << ans << endl;
}