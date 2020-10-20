#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, k, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    a[0] = -1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != a[i - 1]) v.push_back(a[i]);
        }
        if (k == 1) {
            if (v.size() == 1)
                cout << 1 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        if (v.size() <= k)
            cout << 1 << endl;
        else {
            int sz = v.size() - k, ans = 1;
            --k;
            ans += (sz % k == 0 ? sz / k : sz / k + 1);
            cout << ans << endl;
        }
    }
}