/*
 * @Date         : 2020-07-14 02:01:46
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int t, n, a[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int flag = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                cout << "YES" << endl;
                cout << i - 1 << ' ' << i << ' ' << i + 1 << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "NO" << endl;
    }
}