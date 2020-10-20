#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, a[maxn], h[35];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(h, 0, sizeof(h));
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int tmp = a[i];
            int cnt = 0;
            while (tmp) {
                cnt++;
                tmp >>= 1;
            }
            h[cnt]++;
        }
        long long ans = 0;
        for (int i = 0; i <= 32; i++) { ans += 1LL * h[i] * (h[i] - 1) / 2; }
        cout << ans << '\n';
    }
}