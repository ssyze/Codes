/*
 * @Date         : 2020-04-17 21:50:39
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
ll t, n, a[maxn], b[maxn];
double c[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0, sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            sum1 += a[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            if (b[i] >= a[i + 1])
                b[i] = a[i + 1];
        }
        if (b[n] >= a[1])
            b[n] = a[1];
        ll mn = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            sum2 += b[i];
            mn = min(mn, b[i]);
        }
        cout << sum1 - sum2 + mn << endl;
    }
}