/*
 * @Date         : 2020-08-13 12:06:59
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
pair<ll, ll> p[3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
        int cl = 0, cc = 0;
        for (int i = 0; i < 3; i++) {
            ll ans = p[i].first * p[(i + 1) % 3].second - p[i].second * p[(i + 1) % 3].first;
            if (ans < 0)
                cl++;
            else if (ans > 0)
                cc++;
        }
        if (cc > cl)
            cout << "Counterclockwise\n";
        else
            cout << "Clockwise\n";
    }
}