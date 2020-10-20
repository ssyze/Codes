#include <bits/stdc++.h>
using namespace std;
double a[505], ans[505];
double n, k;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ans[i] = k * a[i] / n;
        /* if (k == 1) {
            for (int j = 1; j <= n - 1; j++) ans[i] += (a[(i - j + int(n)) % int(n)] / n);
        } */
        for (int j = 1; j <= n - k; j++) {
            int pos = (i - j + int(n)) % int(n);
            // cout << ans[i] << ' ' << pos << '\n';
            double val = k / n;
            for (int p = 1; p <= j; p++) { val = val * (n - k - p + 1) / (n - p); }
            ans[i] += val * a[pos];
        }
    }
    for (int i = 0; i < n; i++) printf("%.10f ", ans[i]);
    puts("");
}