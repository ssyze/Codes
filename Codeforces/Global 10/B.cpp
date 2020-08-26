/*
 * @Date         : 2020-08-26 16:54:41
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll k;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        int mx = -0x3f3f3f3f, mx1 = -0x3f3f3f3f;
        for (auto& x : a) {
            cin >> x;
            mx = max(mx, x);
        }
        for (auto& x : a) x = mx - x, mx1 = max(mx1, x);
        if (k & 1)
            for (auto& x : a) cout << x << ' ';
        else
            for (auto& x : a) cout << mx1 - x << ' ';
        cout << '\n';
    }
}