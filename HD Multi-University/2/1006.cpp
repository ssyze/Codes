/*
 * @Date         : 2020-07-23 17:27:01
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 3e6 + 5;
int t;
ull f[maxn];
unordered_map<ull, int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[1] = 1, f[2] = 2;
    for (int i = 3; i < maxn; i++) f[i] = f[i - 1] + f[i - 2];
    cout << ULLONG_MAX + 1 << ' ' << f[1] - f[3] << endl;
    cin >> t;
    while (t--) {
        int n, x;
        ull a = 0, b = 0, c = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x) a += f[i];
        }
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x) b += f[i];
        }
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x) c += f[i];
        }
    }
}
