/*
 * @Date         : 2020-08-23 00:53:43
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
constexpr int threshold = 10000000;
const int maxn = 5e6 + 5;
typedef unsigned long long ull;
typedef long long ll;
ull k1, k2;
int a[maxn], b[maxn], n, m;
ull xorShift128Plus()
{
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void gen(int n, ull _k1, ull _k2)
{
    k1 = _k1, k2 = _k2;
    for (int i = 1; i <= n; i++) {
        a[i] = xorShift128Plus() % threshold + 1;
        b[i] = xorShift128Plus() % threshold + 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m >> k1 >> k2) {
        gen(n, k1, k2);
        for (int i = 1; i <= n; i++) cout << a[i] << ' ' << b[i] << '\n';
        sort(a + 1, a + 1 + n, greater<int>());
        sort(b + 1, b + 1 + n, greater<int>());
        int a1 = 2, b1 = 1;
        ll ans = a[1], f = a[1];
        for (int i = 2; i <= m; i++) {
            ll tmp1 = -1, tmp2 = -1;
            if (a1 <= n) tmp1 = f + a[a1];
            if (a1 > 1 && b1 <= n) tmp2 = f + b[b1] - a[a1 - 1];
            if (tmp1 > tmp2)
                f = tmp1, a1++;
            else
                f = tmp2, a1--, b1++;
            ans ^= f;
        }
        cout << ans << '\n';
    }
}