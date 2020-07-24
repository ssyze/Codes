/*
 * @Date         : 2020-03-30 14:15:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int t, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            if (a[i] != a[i - 1])
                cnt++;
        }
        if (cnt == 1) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++)
                cout << 1 << ' ';
            cout << endl;
            continue;
        }
        if (n % 2 == 0) {
            cout << 2 << endl;
            for (int i = 0; i < n; i += 2) {
                cout << 1 << ' ' << 2 << ' ';
            }
            cout << endl;
        }
        else {
            int flag = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == a[(i + 1) % n]) {
                    vector<int> ans(n);
                    for (int j = i, k = 0; j >= 0; j--, k ^= 1) {
                        ans[j] = k + 1;
                    }
                    for (int j = i + 1, k = 0; j < n; j++, k ^= 1) {
                        ans[j] = k + 1;
                    }
                    cout << 2 << endl;
                    for (auto& x : ans) {
                        cout << x << ' ';
                    }
                    cout << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            cout << 3 << endl;
            for (int i = 0; i < n - 1; i += 2)
                cout << 1 << ' ' << 2 << ' ';
            cout << 3 << endl;
        }
    }
}