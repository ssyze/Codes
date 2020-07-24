/*
 * @Date         : 2020-03-25 16:10:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 3, c;
ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main()
{
    while (cin >> c) {
        if (c == 1) {
            cout << 1 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll tmp = gcd(i, n);
            ans += qpow(c, tmp * 2);
        }
        //cout << ans << endl;
        ans += 3 * qpow(c, 4);
        cout << ans / (n * 2) << endl;
    }
}