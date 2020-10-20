#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, k, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << (-1) / 2 << endl;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        int flag = 1;
        for (int i = 1; i < n; i++)
            if (a[i] != a[i - 1]) flag = 0;
        if (k == 1) {
            if (flag)
                cout << 1 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        if (flag) {
            cout << 1 << endl;
            continue;
        }
        set<int> s;
        for (int i = 0; i < n; i++) s.insert(a[i]);
        int sz = s.size();
        cout << 1 + (sz - 2) / (k - 1) << endl;
    }
}