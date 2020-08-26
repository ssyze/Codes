#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;

ll t, n, k, ans[maxn];
pair<ll, ll> a[maxn], b[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        bool no = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
        for (int i = n; i >= 1; --i) {
            if (i != n) {
                a[i].first = max(a[i].first, b[i].first);
                a[i].second = min(a[i].second, b[i].second);
                if (a[i].first > a[i].second) no = 1;
            }
            b[i - 1].first = a[i].first - k;
            b[i - 1].second = a[i].second + k;
        }
        if (no)
            cout << "NO\n";
        else {
            cout << "YES\n";
            ans[1] = a[1].first;
            for (int i = 2; i <= n; ++i) {
                if (ans[i - 1] < a[i].first)
                    ans[i] = a[i].first;
                else if (ans[i - 1] > a[i].second)
                    ans[i] = a[i].second;
                else
                    ans[i] = ans[i - 1];
            }
            for (int i = 1; i <= n; ++i) cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }
}
