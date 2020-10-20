#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int t, n, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        int flag = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}