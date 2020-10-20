#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, a[maxn], b[maxn], c[maxn], p[maxn], n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        p[0] = a[0];
        for (int i = 0; i < n - 1; i++) {
            if (a[(i + 1) % n] == p[i])
                p[i + 1] = b[i + 1];
            else
                p[i + 1] = a[i + 1];
        }
        p[n - 1] = a[n - 1];
        if (p[n - 1] == p[n - 2] || p[n - 1] == p[0]) {
            p[n - 1] = b[n - 1];
            if (p[n - 1] == p[n - 2] || p[n - 1] == p[0]) p[n - 1] = c[n - 1];
        }
        for (int i = 0; i < n; i++) cout << p[i] << ' ';
        cout << endl;
    }
}